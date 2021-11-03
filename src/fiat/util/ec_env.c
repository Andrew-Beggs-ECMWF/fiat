/*
 * (C) Copyright 2005- ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */


/* env.c */

/* Implement Fortran-callable ec_getenv and ec_putenv,
   since not all environments have getenv & putenv,
   but Unix/C library always have them */

/* Author: Sami Saarinen, ECMWF, 15-Mar-2006 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <time.h>

#include "raise.h"

#define EC_HOST_NAME_MAX 512

extern char **environ; /* Global Unix var */
static int numenv = 0;

void
ec_numenv_bind_c(int *n)
{ /* Returns the number of environment variables currently active */
  int j=0;
  if (environ) {
    for (; environ[j]; j++) { }
  }
  if (n) *n = j;
  numenv = j; /* Not thread-safe */
}

void
ec_environ_bind_c(const int *i,
	   char *value,
	   /* Hidden arguments */
	   const int valuelen)
{ /* Returns (*i)'th environment number; 
     Note: "Fortran", not "C" range between [1..numenv] */
  int j = (i && environ) ? (*i) : 0;
  memset(value, ' ', valuelen);
  if (j >= 1 && j <= numenv) {
    char *p = environ[--j];
    if (p) {
      int len = strlen(p);
      if (valuelen < len) len = valuelen;
      memcpy(value,p,len);
    }
  }
}


void
ec_getenv_bind_c(const char *s,
	   char *value,
	   /* Hidden arguments */
	   int slen,
	   const int valuelen)
{
  char *env = NULL;
  char *p = malloc(slen+1);
  if (!p) {
    fprintf(stderr,"ec_getenv_(): Unable to allocate %d bytes of memory\n", slen+1);
    ABOR1("ec_getenv_(): Unable to allocate memory");
  }
  memcpy(p,s,slen);
  p[slen]='\0';
  memset(value, ' ', valuelen);
  env = getenv(p);
  if (env) {
    int len = strlen(env);
    if (valuelen < len) len = valuelen;
    memcpy(value,env,len);
  }
  free(p);
}

void
ec_putenv_overwrite_bind_c(const char *s,
	   /* Hidden argument */
	   int slen)
{
  const char *x = &s[slen-1];
  /* strip trailing blanks first */
  while (slen > 0 && *x == ' ') { --slen; --x; }
  /* now go ahead */
  if (slen > 0) {
    char *p = malloc(slen+1);
    if (!p) {
      fprintf(stderr,"ec_putenv_(): Unable to allocate %d bytes of memory\n", slen+1);
      ABOR1("ec_putenv_(): Unable to allocate memory");
    }
    memcpy(p,s,slen);
    p[slen]='\0';
    putenv(p);
    /* Cannot free(p); , since putenv() uses this memory area for good ;-( */
  }
}

void
ec_putenv_nooverwrite_bind_c(const char *s,
		       /* Hidden argument */
		       int slen)
{
  const char *x = &s[slen-1];
  /* strip trailing blanks first */
  while (slen > 0 && *x == ' ') { --slen; --x; }
  /* now go ahead */
  if (slen > 0) {
    char *eq = NULL;
    char *p = malloc(slen+1);
    if (!p) {
      fprintf(stderr,"ec_putenv_nooverwrite_(): Unable to allocate %d bytes of memory\n", slen+1);
      ABOR1("ec_putenv_nooverwrite_(): Unable to allocate memory");
    }
    memcpy(p,s,slen);
    p[slen]='\0';
    eq = strchr(p,'=');
    if (eq) {
      char *env = NULL;
      *eq = '\0';
      env = getenv(p);
      if (env) {
	/* Already found ==> do not overwrite */
	free(p);
	return;
      }
      else {
	/* Reset '=' back and continue with putenv() */
	*eq = '=';
      }
    }
    putenv(p);
    /* Cannot free(p); , since putenv() uses this memory area for good ;-( */
  }
}

/*--- sleep_by_spinning ---*/

static int sleep_by_spinning(long secs, long nanosecs) { /* see also drhook.c */
  /* This does not call sleep() at all i.e. is not SIGALRM driven */
  int rc;
  struct timespec req, rem;
  req.tv_sec = secs;
  req.tv_nsec = nanosecs;
  rc = nanosleep(&req, &rem);
  if (rc == -1) {
    if (errno == EINTR) {
      rc = rem.tv_sec;
    }
    else
      rc = 0; /* Can't do much more about this */
  }
  return rc;
}

unsigned int
ec_sleep_(const int *nsec)
{
  //return sleep((nsec && *nsec > 0) ? *nsec : 0);
  return sleep_by_spinning((nsec && *nsec > 0) ? *nsec : 0, 0);
}


unsigned int
ec_sleep(const int *nsec)
{
  return ec_sleep_(nsec);
}

/* Microsecond-sleep, by S.Saarinen, 25-jan-2008 */

void  /* Global, C-callable, too */
ec_microsleep(int usecs) {
  if (usecs > 0) {
    struct timeval t;
    t.tv_sec =  usecs/1000000;
    t.tv_usec = usecs%1000000;
    // (void) select(0, NULL, NULL, NULL, &t);
    (void) sleep_by_spinning(t.tv_sec, (long)1000*t.tv_usec);
  }
}


void
ec_usleep_(const int *usecs)
{
  if (usecs && *usecs > 0) ec_microsleep(*usecs);
}


void
ec_usleep(const int *usecs)
{
  ec_usleep_(usecs);
}

/* ec_gethostname, by S.Saarinen, 30-sep-2016 */

void ec_gethostname_(char a[], 
		     /* Hidden argument */
		     int alen)
{
  char s[EC_HOST_NAME_MAX];
  memset(a,' ',alen);
  if (gethostname(s,sizeof(s)) == 0) {
    int len;
    char *pdot = strchr(s,'.');
    if (pdot) *pdot = '\0'; // cut short from "." char e.g. hostname.fmi.fi becomes just "hostname"
    len = strlen(s);
    if (len > alen) len = alen;
    memcpy(a,s,len);
  }
}

void ec_gethostname(char a[], 
		     /* Hidden argument */
		     int alen)
{
  ec_gethostname_(a,alen);
}


/* For checking runtime affinities (not setting them, though) */

#if defined(LINUX) && !defined(__NEC__)
#include <sched.h>
int sched_getcpu(void);
#define getcpu() sched_getcpu()
#else
#define getcpu() -1
#endif

void ec_coreid_(int *coreid)
{
  if (coreid) *coreid = getcpu();
}

void ec_coreid(int *coreid)
{
  ec_coreid_(coreid);
}

#ifdef DARSHAN
/* Some issues with Darshan -- better to use our own version of MPI_Wtime (mpi_wtime_ in Fortran) */
double mpi_wtime_()
{
  extern double util_walltime_(); /* from drhook.c */
  return util_walltime_();
}
#endif