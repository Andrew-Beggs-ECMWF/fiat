.. role:: c(code)
   :language: c

Flags & Environment variables
=============================

.. _DR_HOOK_SHOW_LOCK:

DR_HOOK_SHOW_LOCK
-----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Used to specify if lock debug info should be output. This is on initialisation only.

Notes
^^^^^
This is done by enabling ``OML_DEBUG`` in the *OML* library, initialising a new ``lockid``, and then restoring the original value.

| This debug info takes the following format:
| :samp:`oml_init_lockid_with_name "{lock_name}" : {lock_ID}, {lock_address}`

.. todo:: Written - Not tested

.. ###############################################

.. _OMP_STACKSIZE:

OMP_STACKSIZE
-------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> <suffix>
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
| suffix ::= '' | 'G' | 'M' | 'K'

Purpose
^^^^^^^
Specifies an indicative stack size the master thread should not exceed.

Notes
^^^^^
This is an overloaded environment variable, used primarily by *OpenMP*.

It will only be read if :ref:`DR_HOOK_TRACE_STACK <DR_HOOK_TRACE_STACK>` is also set.

``OMP_STACKSIZE`` is scaled by ``opt_trace_stack``, obtained from :ref:`DR_HOOK_TRACE_STACK <DR_HOOK_TRACE_STACK>`, to give ``drhook_stacksize_threshold``. If ``drhook_stacksize_threshold`` is exceeded by the master thread during a ``random_memstat`` check, an abort will occur.

The stack size can be specified in GiB, MiB, or KiB using the suffix ``G``, ``M``, or ``K`` respectively. A lack of suffix will imply the stack size is in bytes. If multiple suffixes are specified, then the largest specified will be chosen. The stack size is truncated at the first occurring suffix.

The size is limited to the size of :c:`long long int`.

An invalid or negative input size will result in a default of ``0``.

.. todo:: Written - Not tested

.. ###############################################

.. _DR_HOOK_CATCH_SIGNALS:

DR_HOOK_CATCH_SIGNALS
---------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <signal> |  <valid_value> <delim> <signal>
| delim ::= ',' | ' ' | '\t' | '/'
| signal ::= '-1' | <number>
| number ::= <digit> | <number> <digit> | <number> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'


Purpose
^^^^^^^
Specifies a list of signals to be caught and handled by \drhook.

Notes
^^^^^
If :math:`1 \leq` ``signal`` :math:`\leq` ``NSIG``, then it is registered to be caught and handled by \drhook - unless it has been set to ignored by
:ref:`DR_HOOK_IGNORE_SIGNALS <DR_HOOK_IGNORE_SIGNALS>`. ``NSIG`` is defined in :file:`signal.h` and is system dependant.


If ``signal`` is set to ``-1``, then all available catchable signals are registered to be caught and handled by \drhook. Any value after ``-1`` will be discarded.

All other values will be silently discarded.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_RESTORE_DEFAULT_SIGNALS:

DR_HOOK_RESTORE_DEFAULT_SIGNALS
-------------------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <signal> |  <valid_value> <delim> <signal>
| delim ::= ',' | ' ' | '\t' | '/'
| signal ::= '-1' | <number>
| number ::= <digit> | <number> <digit> | <number> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies a list of signals to have their default handler restored, if they haven't been set to be ignored.

Notes
^^^^^
If :math:`1 \leq` ``signal`` :math:`\leq` ``NSIG``, then it's default signal handler is restored - unless it has been set to ignored by
:ref:`DR_HOOK_IGNORE_SIGNALS <DR_HOOK_IGNORE_SIGNALS>`. ``NSIG`` is defined in :file:`signal.h` and is system dependant.


If ``signal`` is set to ``-1``, then all available catchable signals have their default signal handler restored. Any value after ``-1`` will be discarded.

All other values will be silently discarded.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_IGNORE_SIGNALS:

DR_HOOK_IGNORE_SIGNALS
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <signal> |  <valid_value> <delim> <signal>
| delim ::= ',' | ' ' | '\t' | '/'
| signal ::= '-1' | <number>
| number ::= <digit> | <number> <digit> | <number> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies a list of signals to be ignored by \drhook. This means \drhook will not handle these signals when they occur.

Notes
^^^^^
If :math:`1 \leq` ``signal`` :math:`\leq` ``NSIG``, then it's set to inactive and ignored by \drhook. ``NSIG`` is defined in :file:`signal.h` and is system dependant.

If ``signal`` is set to ``-1``, then all available catchable signals are set to inactive and be ignored by \drhook. Any value after ``-1`` will be discarded.

All other values will be silently discarded.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_SILENT:

DR_HOOK_SILENT
--------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Used to enable or disable debug prints to ``STDERR``.

Notes
^^^^^
This is not recommended during production run due to the excessive slowdown caused by printing.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_INIT_SIGNALS:

DR_HOOK_INIT_SIGNALS
--------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies if signals should be initialised via \drhook (dangerous, but sometimes necessary).

Notes
^^^^^
.. todo:: Not certain on exactly what it does. 

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_SHOW_PROCESS_OPTIONS:

DR_HOOK_SHOW_PROCESS_OPTIONS
----------------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | '-1'
| number ::= <digit> | <number> <digit> | <number> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies processIDs for which all options will be output \todo{Where?}.

Notes
^^^^^
If this option isn't specified, and :ref:`DR_HOOK_SILENT <DR_HOOK_SILENT>` doesn't evaluate to ``True``, then this will default to the process with ID ``1``.

Specifying ``-1`` will enable this for all processes.

.. todo:: Not tested

.. ###############################################

.. _ATP_ENABLED:

ATP_ENABLED
-----------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Enable `Abnormal Termination Processing (ATP) <https://cpe.ext.hpe.com/docs/debugging-tools/atp.1.html>`_ mode for *Cray* systems. This will pass certain signals to :abbr:`ATP (Abnormal Termination Processing)` instead of \drhook.

Notes
^^^^^
If nothing is specified, then this will default to ``0``.

This will also cause \drhook to check the following flags:

* :ref:`ATP_MAX_CORES <ATP_MAX_CORES>`
* :ref:`ATP_MAX_ANALYSIS_TIME <ATP_MAX_ANALYSIS_TIME>`
* :ref:`ATP_IGNORE_SIGTERM <ATP_IGNORE_SIGTERM>`

The signals passed to :abbr:`ATP (Abnormal Termination Processing)` are:

* ``SIGINT``
* ``SIGFPE``
* ``SIGILL``
* ``SIGTRAP``
* ``SIGABRT``
* ``SIGBUS``
* ``SIGSEGV``
* ``SIGSYS``
* ``SIGXCPU``
* ``SIGXFSZ``
* ``SIGTERM``

  * ``SIGTERM`` is only passed to :abbr:`ATP (Abnormal Termination Processing)` if :ref:`ATP_IGNORE_SIGTERM <ATP_IGNORE_SIGTERM>` is set

.. todo:: Not tested

.. ###############################################

.. _ATP_MAX_CORES:

ATP_MAX_CORES
-------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number>
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used as a multiplier for calculating the spin wait time for all cores to dump if :abbr:`ATP (Abnormal Termination Processing)` is enabled and handling signals.

Also used along with :ref:`ATP_ENABLED <ATP_ENABLED>` to determine if any cores are being dumped by :abbr:`ATP (Abnormal Termination Processing)`.

Notes
^^^^^
This is an overloaded environment variable, used primarily for :abbr:`ATP (Abnormal Termination Processing)`. If nothing is specified, then this will default to ``20``.

This will only be enable if the :ref:`ATP_ENABLED <ATP_ENABLED>` flag evaluates to ``True``.

The size is limited to the size of :c:`int`.

.. todo:: Not tested

.. ###############################################

.. _ATP_MAX_ANALYSIS_TIME:

ATP_MAX_ANALYSIS_TIME
---------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number>
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used as a base value for calculating the spin wait time for all cores to dump if :abbr:`ATP (Abnormal Termination Processing)` is enabled and handling signals.

Notes
^^^^^
This is an overloaded environment variable, used primarily for :abbr:`ATP (Abnormal Termination Processing)`. If nothing is specified, then this will default to ``300``.

This will only be enable if the :ref:`ATP_ENABLED <ATP_ENABLED>` flag evaluates to ``True``.

The minimum between ``ATP_MAX_ANALYSIS_TIME`` and ``drhook_harakiri_timeout`` (set by :ref:`DR_HOOK_HARAKIRI_TIMEOUT <DR_HOOK_HARAKIRI_TIMEOUT>`) is chosen as the base for calculating the time to spin wait for :abbr:`ATP (Abnormal Termination Processing)` to finish handling a signal, through the following:

.. code-block:: C

    int secs = MIN(drhook_harakiri_timeout, atp_max_analysis_time);
    secs = 60 + MIN(tdiff * (atp_max_cores - 1), secs);

The size is limited to the size of :c:`int`.

.. todo:: Not tested

.. ###############################################

.. _ATP_IGNORE_SIGTERM:

ATP_IGNORE_SIGTERM
------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Determines if ``SIGTERM`` should be handled by \drhook or :abbr:`ATP (Abnormal Termination Processing)`.

Notes
^^^^^
This is an overloaded environment variable, used primarily for :abbr:`ATP (Abnormal Termination Processing)`. If nothing is specified, then this will default to ``0``.

This will only be enable if the :ref:`ATP_ENABLED <ATP_ENABLED>` flag evaluates to ``True``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_ALLOW_COREDUMP:

DR_HOOK_ALLOW_COREDUMP
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | '-1'
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies both if core dumping should be enabled, and if so, which processes.

Notes
^^^^^

If ``DR_HOOK_ALLOW_COREDUMP`` evaluates to :math:`1\leq` ``process`` :math:`\leq` ``# of processes`` then only the specified process has core dumping enabled.

If ``DR_HOOK_ALLOW_COREDUMP`` evaluates to ``-1`` then core dumping is enabled for all processes.

If ``DR_HOOK_ALLOW_COREDUMP`` evaluates to ``0`` then core dumping is disabled.

.. -1 denotes ALL MPI-tasks, 1..NPES == myproc, 0 = coredump will not be enabled by DrHook at init
.. todo:: It doesn't seem like this value matters apart from zero vs non-zero?
.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_PROFILE:

DR_HOOK_PROFILE
---------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <char> | <valid_value> <char>
| char ::= <letter> | <digit> | <symbol>
| letter ::= <lower> | <upper>
| upper ::= 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M' | 'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z'
| lower ::= 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z'
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
| symbol ::= ' \' | '!' | '"' | '#' | '$' | '%' | '&' | ''' | '(' | ')' | '*' | '+' | ',' | '-' | '.' | ':' | ';' | '<' | '=' | '>' | '?' | '@' | '[' | '' | ']' | '^' | '_' | '`' | '{' | '|' | '}' | '~'

Purpose
^^^^^^^
Specifies where to output profiles.

Notes
^^^^^
While ``DR_HOOK_PROFILE`` is just to be a valid file name, many of the valid symbols are not recommended for obvious reasons.

If a relative path is used, then it will be relative to the rundir of the binary \drhook is linked into.

If ``DR_HOOK_PROFILE`` doesn't contain the character :code:`\%`, then :code:`.\%d` will be appended.

If :ref:`DR_HOOK_PROFILE_PROC <DR_HOOK_PROFILE_PROC>` is set and valid, but ``DR_HOOK_PROFILE`` is not set, then ``DR_HOOK_PROFILE`` defaults to ``drhook.prof.%d``.

If \drhook fails to set the process specific patch string either due to an error or process configuration, then it will default to :file:`drhook.prof.0`.

``DR_HOOK_PROFILE`` is also indirectly used in :c:`get_memmon_out`. ``-mem`` is simply appended to the previously described path.

``DR_HOOK_PROFILE`` is also indirectly used in :c:`get_csv_out` for PAPI mode, enabled with :ref:`DR_HOOK_OPT <DR_HOOK_OPT>`. ``.csv`` is simply appended to the previously described path.

This option is only used in profiling and memory profiling modes.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_PROFILE_PROC:

DR_HOOK_PROFILE_PROC
--------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | '-1'
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to specify which process, or all processes, that should output profiling data.

Notes
^^^^^
If ``DR_HOOK_PROFILE_PROC`` is ``-1``, then all processes will out profiling data. All other valid values will result in the one specified process outputting its data.

If this option isn't specified, then it will default to ``-1``.

The size is limited to the size of :c:`double`.

This option is only used in profiling and memory profiling modes.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_PROFILE_LIMIT:

DR_HOOK_PROFILE_LIMIT
---------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | <number> '.' <number> 
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies at which percentage of the maximum value data points should be dropped from profiling outputs.

Notes
^^^^^
If this option isn't specified, then it will default to ``-10``.

The size is limited to the size of :c:`double`.

This option is only used in profiling and memory profiling modes.

.. Lowest percentage accepted into the printouts

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_FUNCENTER:

DR_HOOK_FUNCENTER
-----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to specify a thread to print memory and stack information to stdout upon entering a function.

Notes
^^^^^
If this option isn't specified, then it will default to ``0``.

This will also set ``opt_gethwm`` and ``opt_getstk`` to ``1``, that are usually handled by :ref:`DR_HOOK_OPT <DR_HOOK_OPT>`.

To see when a process exits a function, use :ref:`DR_HOOK_FUNCEXIT <DR_HOOK_FUNCEXIT>`.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_FUNCEXIT:

DR_HOOK_FUNCEXIT
----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to specify a thread to print memory and stack information to stdout upon exiting a function.

Notes
^^^^^
If this option isn't specified, then it will default to ``0``.

This will also set ``opt_gethwm`` and ``opt_getstk`` to ``1``, that are usually handled by :ref:`DR_HOOK_OPT <DR_HOOK_OPT>`.

To see when a process enters a function, use :ref:`DR_HOOK_FUNCENTER <DR_HOOK_FUNCENTER>`.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMELINE:

DR_HOOK_TIMELINE
----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | '-1'
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to enable timeline mode for either all processes or a specific process.

Notes
^^^^^
If ``DR_HOOK_TIMELINE`` is ``-1``, then all processes will have timeline mode enabled. All other non-zero valid values will result in the one specified process having timeline mode enabled.

.. todo:: What is timeline mode??.

.. , at the frequency specified by :ref:`DR_HOOK_TIMELINE_FREQ <DR_HOOK_TIMELINE_FREQ>`

If this option isn't specified, then it will default to ``0``.

Setting ``DR_HOOK_TIMELINE`` to a non-zero value also causes \drhook to check the following options:

* :ref:`DR_HOOK_TIMELINE_THREAD <DR_HOOK_TIMELINE_THREAD>`
* :ref:`DR_HOOK_TIMELINE_FORMAT <DR_HOOK_TIMELINE_FORMAT>`
* :ref:`DR_HOOK_TIMELINE_UNITNO <DR_HOOK_TIMELINE_UNITNO>`
* :ref:`DR_HOOK_TIMELINE_FREQ <DR_HOOK_TIMELINE_FREQ>`
* :ref:`DR_HOOK_TIMELINE_MB <DR_HOOK_TIMELINE_MB>`

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMELINE_THREAD:

DR_HOOK_TIMELINE_THREAD
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number>
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to specify which threads should output timeline info upon entry and exit of a region.


Notes
^^^^^
If timeline mode is enabled via :ref:`DR_HOOK_TIMELINE <DR_HOOK_TIMELINE>`, then for all threads in the range :math:`1 \rightarrow n` (inclusive) \drhook will print timeline information on both entry and exit from a region. \drhook will also print the sum of *all threads* for the first thread.

.. todo:: Which info gets summed? is it all?

If ``DR_HOOK_TIMELINE_THREAD`` is set to ``0``, then all n will be set so as to cover all threads and the behaviour is identical to the above.

.. <= 0 print for all threads
.. 1 -> #1 only [but curheap still SUM of all threads] (default),
.. n -> print for increasing number of threads separately : [1..n] */

While not strictly valid, any value less than ``0`` will have the same behaviour as ``0``.

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMELINE_FORMAT:

DR_HOOK_TIMELINE_FORMAT
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Used to specify if timeline information should be output in value only or verbose mode.

Notes
^^^^^
.. /* if 1, print only {wall,hwm,rss,curheap} w/o labels "wall=" etc.; else fully expanded fmt */

This option is only available if timeline mode is enabled via :ref:`DR_HOOK_TIMELINE <DR_HOOK_TIMELINE>`.

If ``DR_HOOK_TIMELINE_FORMAT`` is ``1``, then the following value only formatter will be used:

:c:`"%.6f %.4g %.4g %.4g %.4g"`

Otherwise, the verbose formatter is used:

:c:`"wall=%.6f cpu=%.4g hwm=%.4g rss=%.4g curheap=%.4g stack=%.4g vmpeak=%.4g pag=%lld"`

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMELINE_UNITNO:

DR_HOOK_TIMELINE_UNITNO
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies the unit number to be used for timeline output.

Notes
^^^^^
.. /* Fortran unit number : default = 6 i.e. stdout */

This option is only available if timeline mode is enabled via :ref:`DR_HOOK_TIMELINE <DR_HOOK_TIMELINE>`.

``DR_HOOK_TIMELINE_UNITNO`` must be an integer between ``1`` and ``99``. Some unit numbers are reserved: ``5`` is standard input, ``6`` is standard output.

As the value of ``DR_HOOK_TIMELINE_UNITNO`` has to be interpreted by :c:`atoi()`, only integer unit numbers are valid.

If ``0`` is specified, then timeline outputs are silently ignored.

If this option isn't specified, then it will default to ``6``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMELINE_FREQ:

DR_HOOK_TIMELINE_FREQ
---------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> | <valid_value> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to specify how many DR_HOOK_TIMELINE_FREQ\ :sup:`th` regions entries/exits should be output during timeline mode.

Notes
^^^^^
.. /* How often to print : every n-th call : default = every 10^6 th call or ... */

This option is only available if timeline mode is enabled via :ref:`DR_HOOK_TIMELINE <DR_HOOK_TIMELINE>`.

If a \drhook region is entered/exited and it is the n\ :sup:`th` entry/exit, where n is a multiple of ``DR_HOOK_TIMELINE``, then the timeline information will be output.

If a \drhook region is entered/exited and it isn't the n\ :sup:`th` call, but the resident set size varies by more than :ref:`DR_HOOK_TIMELINE_MB <DR_HOOK_TIMELINE_MB>`, then it is output anyway.

A value less than ``1`` will silently disable timeline mode.

The size is limited to the size of :c:`long long int`.

If this option isn't specified, then it will default to ``1000000``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMELINE_MB:

DR_HOOK_TIMELINE_MB
-------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | <number> '.' <number> 
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
This specifies how much the resident set size needs to vary by, in MB, before :ref:`DR_HOOK_TIMELINE_FREQ <DR_HOOK_TIMELINE_FREQ>` is overridden.

.. todo:: Double check, is this MB or MiB

Notes
^^^^^
.. /* ... rss or curheap jumps up/down by more than this many MBytes (default = 1) : unit MBytes */

This option is only available if timeline mode is enabled via :ref:`DR_HOOK_TIMELINE <DR_HOOK_TIMELINE>`.

A value less than ``0`` will be set to ``1.0``.

The size is limited to the size of :c:`double`.

If this option isn't specified, then it will default to ``1.0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TRACE_STACK:

DR_HOOK_TRACE_STACK
-------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | <number> '.' <number> 
| number ::= <digit> | <number> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
A multiplier for :ref:`OMP_STACKSIZE <OMP_STACKSIZE>`, to monitor high master thread stack usage.

Notes
^^^^^
.. if > 0, a multiplier for OMP_STACKSIZE to monitor high master thread stack usage --
.. -- implies opt_random_memstat = 1 (regardless of DR_HOOK_RANDOM_MEMSTAT setting)
.. -- for master MPI task only (for the moment)

As described for :ref:`OMP_STACKSIZE <OMP_STACKSIZE>`, ``DR_HOOK_TRACE_STACK`` is used to scale the value of :ref:`OMP_STACKSIZE <OMP_STACKSIZE>` to give :c:`drhook_stacksize_threshold`. If :c:`drhook_stacksize_threshold` is exceeded by the master thread during a ``random_memstat`` check, an abort will occur.

``DR_HOOK_TRACE_STACK`` being defined and non-zero also implies :c:`opt_random_memstat` has a default value of ``1`` (meaning it will always trigger a ``random_memstat`` check on entry to a \drhook region). However, if :ref:`DR_HOOK_RANDOM_MEMSTAT <DR_HOOK_RANDOM_MEMSTAT>` is defined, it will override this value.

A value less than ``0`` will be set to ``0``. Additionally, ``drhook_stacksize_threshold`` won't be scaled, and :c:`opt_random_memstat` is not set to ``1``.

The size is limited to the size of :c:`double`.

If this option isn't specified, then it will default to ``0``.

.. todo:: Written - Not tested

.. ###############################################

.. _DR_HOOK_RANDOM_MEMSTAT:

DR_HOOK_RANDOM_MEMSTAT
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> 
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Used to enable random memstat checks, and how often to do it.

Notes
^^^^^
.. /* > 0 if to obtain random memory stats (maxhwm, maxstk) for tid=1. Updated when rand() % opt_random_memstat == 0 */

The random memstat check is done when a \drhook region is entered and :c:`rand() % opt_random_memstat == 0`, or unconditionally when the feature is explicitly, or implicitly (see :ref:`DR_HOOK_TRACE_STACK <DR_HOOK_TRACE_STACK>`) enabled.

Due to the implementation of the random check, the value of ``DR_HOOK_RANDOM_MEMSTAT`` is important in ways that may not be immediately obvious. For example, a value of ``2`` will result in a check every other entry to a \drhook region on average. Whereas a sufficiently large number will only result in a check every ``1/RAND_MAX`` times on average.

A value greater than :c:`RAND_MAX` will be set to :c:`RAND_MAX`.

A value less than ``0`` will be set to ``0``, effectively disabling the feature.

The size is limited to the size of :c:`int`.

If this option isn't specified, then it will default to ``0``.

.. todo:: Written - Not tested

.. ###############################################

.. _DR_HOOK_HASHBITS:

DR_HOOK_HASHBITS
----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> 
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
.. todo:: Not entirely sure

Notes
^^^^^

A value greater than ``RAND_MAX`` will be set to ``RAND_MAX``.

A value less than ``0`` will be set to ``0``.

| The value of ``DR_HOOK_HASHBITS``, :c:`nhash`, is also used to update the values of :c:`hashsize` and :c:`hashmask`. This is done for :c:`hashsize` via the following:
| :c:`static unsigned int hashsize = ((unsigned int)1<<(nhash));`
| For ``hashmask`` it is:
| :c:`static unsigned int hashmask = (((unsigned int)1<<(nhash))-1);`

The size is limited to the size of :c:`int`.

If this option isn't specified, then it will default to the definition of ``NHASH``, typically ``16``. As such, ``hashsize`` and ``hashmask`` default to ``65536`` and ``65535``, respectively.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_NCALLSTACK:

DR_HOOK_NCALLSTACK
------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> 
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
.. todo:: not entirely sure what this does. Why is it only needed for sp? How does dp manage the keys?

Notes
^^^^^
.. sets maxdepth
.. == 0 is dp
.. > 0 is sp
.. being overloaded to set the size of something based on a union type

.. /* This compile definition serves as default which can still be overwritten using environment variable with same name */
.. /* > 0 : USE call stack approach : needed for single precision version */
.. /* == 0 : do NOT use call stack approach : usually for double precision version */

.. todo:: verify 2 functions only

This is an overloaded value with 2 functions. The first is to set the precision used by \drhook, which also determines which method is used to X. A performance penalty is incurred when using the single precision mode (valid non-zero values), and so is not recommended.

The second function of ``DR_HOOK_NCALLSTACK``, is to act as a parameter when in single precision mode. This parameter sets the maximum stack depth allowed. You must be careful when selecting this that a sufficient depth is chosen. If the depth is exceeded, then \drhook will abort.

A value less than ``0`` will be set to ``0``, effectively selecting double precision.

The size is limited to the size of :c:`int`.

If this option isn't specified, then it will default to ``0``, which enables double precision mode.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_HARAKIRI_TIMEOUT:

DR_HOOK_HARAKIRI_TIMEOUT
------------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> 
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
A timeout for when to kill threads that may have hung.

Notes
^^^^^
.. Strategy:
..       - drhook intercepts most interrupts.
..       - 1st interupt will
..       - call alarm(10) to try to make sure 2nd interrupt received
..       - try to call tracebacks and exit (which includes atexits)
..       - 2nd (and subsequent) interupts will
..       - spin for 20 sec (to give 1st interrupt time to complete tracebacks)
..       - and then call _exit (bypassing atexit)

``DR_HOOK_HARAKIRI_TIMEOUT`` is used in three places. The first is when a signal is first caught by \drhook; it is used as the timeout for :c:`alarm()`. This is to prevent hangs by triggering a second signal when the :c:`alarm()` expires. This second signal then takes an alternative path for subsequent signals where the second use case of ``DR_HOOK_HARAKIRI_TIMEOUT`` occurs. Here it is used to spin for ``DR_HOOK_HARAKIRI_TIMEOUT`` :math:`+ 60` seconds before the thread is killed using ``SIGKILL``. This is to allow for tracebacks to complete.

The third place it is used, is in conjunction with :ref:`ATP_MAX_ANALYSIS_TIME <ATP_MAX_ANALYSIS_TIME>`. Here it is used in the following way to allow :abbr:`ATP (Abnormal Termination Processing)` to dump cores:

.. code-block:: C

    int secs = MIN(drhook_harakiri_timeout, atp_max_analysis_time);
    secs = 60 + MIN(tdiff * (atp_max_cores - 1), secs);

The timeout is specified in seconds.

A value less than ``0`` will be set to the definition of ``drhook_harakiri_timeout_default``, typically ``500``.

The size is limited to the size of :c:`int`.

If this option isn't specified, then it will default to the definition of ``drhook_harakiri_timeout_default``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_USE_LOCKFILE:

DR_HOOK_USE_LOCKFILE
--------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Toggles the use of a lockfile, ``drhook_lock``, for outputting which thread handled a signal first.

Notes
^^^^^
.. todo:: Where is the lockfile?

When enabled, this will enable a lockfile when handling signals in \drhook. This lockfile, ``drhook_lock``, will contain the number of the thread which got the lock first.

.. todo:: Does this imply that this thread triggered the signal?

``DR_HOOK_USE_LOCKFILE`` having a value evaluating to ``1``, will also disable some output regarding the use of :ref:`DR_HOOK_USE_LOCKFILE <DR_HOOK_USE_LOCKFILE>` in it's alternative path for subsequent signals.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TRAPFPE:

DR_HOOK_TRAPFPE
---------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Toggles if floating point exceptions should be trapped, regardless of compiler settings.

Notes
^^^^^
.. todo:: Talk about preprocessor guards

If ``DR_HOOK_TRAPFPE`` evaluates to ``1``, then \drhook will trap floating point exceptions regardless of compilation settings. A value of ``0`` will instead rely on the compiler flags used, e.g. :code:`-Ktrap=fp`.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TRAPFPE_INVALID:

DR_HOOK_TRAPFPE_INVALID
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Toggles whether invalid operation floating point exceptions should be trapped.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_TRAPFPE <DR_HOOK_TRAPFPE>` evaluates to ``1`` or the compiler had trapping of floating point exceptions enabled.

These invalid operations are defined by IEEE 754 standard.

If the exception is not trapped, then the result of the operation is ``NaN``.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TRAPFPE_DIVBYZERO:

DR_HOOK_TRAPFPE_DIVBYZERO
-------------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Toggles whether divide by zero floating point exceptions should be trapped.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_TRAPFPE <DR_HOOK_TRAPFPE>` evaluates to ``1`` or the compiler had trapping of floating point exceptions enabled.

This exception occurs when a finite nonzero number is divided by zero.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TRAPFPE_OVERFLOW:

DR_HOOK_TRAPFPE_OVERFLOW
------------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Toggles whether overflow floating point exceptions should be trapped.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_TRAPFPE <DR_HOOK_TRAPFPE>` evaluates to ``1`` or the compiler had trapping of floating point exceptions enabled.

This exception occurs when the result of a calculation cannot be represented as a finite value in the precision format of the destination. This behaviour is affected by rounding modes.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``1``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_TIMED_KILL:

DR_HOOK_TIMED_KILL
------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <formatted> |  <valid_value> <delim> <formatted>
| delim ::= ',' | ' ' | '\t' | '/'
| formatted ::= <id> ':' <id> ':' <integer> ':' <double>
| double ::= <double_part> | 'double_part' '.' <double_part>
| double_part ::= <digit_0> | <double_part> <digit_0>
| digit_0 ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
| id = <integer> | '-1'
| integer ::= <digit> | <integer> <digit> | <integer> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Set timers for specific, or all, threads to trigger signals. This is a developer option.

Notes
^^^^^
.. /* Timer assisted simulated kill of procs/threads by signal */

The parameters provided to ``DR_HOOK_TIMED_KILL`` (``target_process``, ``target_oml_thread_id``, ``target_signal``, and ``start_time``) are in the following pattern:

``target_process:target_oml_thread_id:target_signal:start_time``

Note that:

* ``target_process`` can be a valid integer for a single process, or ``-1`` for all.
* ``target_oml_thread_id`` can be a valid integer for a single thread, or ``-1`` for all.
* ``target_signal`` must be valid for your system.
* ``start_time`` must be non-zero.

Any set of parameters that are invalid, will be silently discarded.

The timers will be started as part of \drhook's initialisation, and are specified in seconds.

If this option isn't specified, then it will default to ``NULL``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_DUMP_SMAPS:

DR_HOOK_DUMP_SMAPS
------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies whether :file:`/proc/<process_ID>/smaps` should be dumped when handling a signal or not. This is a developer option.

Notes
^^^^^
.. /* Print /proc/<tid>/smaps from signal handler (before moving to ATP or below) */

:file:`smaps` will be dumped after the first signal is handled by \drhook, but before signals are handled by other handlers, e.g. :abbr:`ATP (Abnormal Termination Processing)`. It will only be dumped for the process which raises the signal.

.. todo:: in which directory are they dumped to?

:file:`smaps` will be dumped to :file:`/proc/<process_ID>/smaps`.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_DUMP_MAPS:

DR_HOOK_DUMP_MAPS
-----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies whether :file:`/proc/<process_ID>/maps` should be dumped when handling a signal or not. This is a developer option.

Notes
^^^^^
:file:`maps` will be dumped after the first signal is handled by \drhook, but before signals are handled by other handlers, e.g. :abbr:`ATP (Abnormal Termination Processing)`. It will only be dumped for the process which raises the signal.

:file:`maps` will be dumped to :file:`/proc/<process_ID>/maps`

.. todo:: in which directory are they dumped to?

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_DUMP_BUDDYINFO:

DR_HOOK_DUMP_BUDDYINFO
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies whether :file:`/proc/buddyinfo` should be dumped when handling a signal or not. This is a developer option.

Notes
^^^^^
:file:`buddyinfo` will be dumped after the first signal is handled by \drhook, but before signals are handled by other handlers, e.g. :abbr:`ATP (Abnormal Termination Processing)`.

:file:`buddyinfo` can also be dumped during the dumping of hugepages(enabled via :ref:`DR_HOOK_DUMP_HUGEPAGES <DR_HOOK_DUMP_HUGEPAGES>`). This occurs during the handling of signals, and when \drhook enters a region.

.. todo:: in which directory are they dumped to?

:file:`buddyinfo` will be dumped to :file:`/proc/buddyinfo`.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_DUMP_MEMINFO:

DR_HOOK_DUMP_MEMINFO
--------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies whether :file:`/proc/meminfo` should be dumped when handling a signal or not. This is a developer option.

Notes
^^^^^
:file:`meminfo` will be dumped after the first signal is handled by \drhook, but before signals are handled by other handlers, e.g. :abbr:`ATP (Abnormal Termination Processing)`.

:file:`meminfo` can also be dumped during the dumping of hugepages (enabled via :ref:`DR_HOOK_DUMP_HUGEPAGES <DR_HOOK_DUMP_HUGEPAGES>`). This occurs during the handling of signals, and when \drhook enters a region.

.. todo:: in which directory are they dumped to?

:file:`meminfo` will be dumped to :file:`/proc/meminfo`.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_DUMP_HUGEPAGES:

DR_HOOK_DUMP_HUGEPAGES
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <id> ',' <double>
| double ::= <double_part> | 'double_part' '.' <double_part>
| double_part ::= <digit_0> | <double_part> <digit_0>
| digit_0 ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
| id = <integer> | '-1'
| integer ::= <digit> | <integer> <digit> | <integer> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^

.. todo:: what is ECMEMINFO?

 Specifies whether ``ECMEMINFO`` should be dumped or not. This is a developer option.

Notes
^^^^^
The parameters provided to ``DR_HOOK_DUMP_HUGEPAGES`` (``target_process``, and ``frequency``) are in the following pattern:

``target_process, frequency``

Note that:

* ``target_process`` can be a valid integer for a single process, or ``-1`` for all.
* ``frequency`` is given in seconds. This is the minimum time that must pass before huge pages are dumped - unless the function has been called with the ``enforced`` flag. Although, enforcement isn't currently used within \drhook.

If either parameters are invalid, both will be silently discarded.

.. ``meminfo`` can also be dumped during the dumping of hugepages. This occurs during the handling of signals, and when \drhook enters a region.

Hugepages are only dumped by the first thread.

Hugepage dumping can occur when handling a signal or entering a \drhook region.

:file:`/proc/buddyinfo` and :file:`/proc/meminfo` can also be dumped with hugepages, if :ref:`DR_HOOK_DUMP_BUDDYINFO <DR_HOOK_DUMP_BUDDYINFO>` and :ref:`DR_HOOK_DUMP_MEMINFO <DR_HOOK_DUMP_MEMINFO>` are enabled respectively.

.. todo:: is this right? & talk about if so

The dumping of hugepages is handled by ec_meminfo.

If this option isn't specified, then it will default to ``0,0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_GENCORE:

DR_HOOK_GENCORE
---------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies whether generating core dumps is enabled or not.

Notes
^^^^^
Any non-zero valid integer value will be treated as ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_GENCORE_SIGNAL:

DR_HOOK_GENCORE_SIGNAL
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> | <valid_value> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies the signal which triggers generating a core dump.

Notes
^^^^^
To be valid then it must be :math:`1 \leq` ``signal`` :math:`\leq` ``NSIG``, and not equal to ``SIGABRT``. ``NSIG`` and ``SIGABRT`` are defined in :file:`signal.h` and are system dependant.

All invalid values will be silently discarded.

If this option isn't specified, then it will default to ``0``, which causes it to be ignored.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_STRICT_REGIONS:

DR_HOOK_STRICT_REGIONS
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies if \drhook region entry and exit calls must use the same label.

Notes
^^^^^
\drhook region entry and exit calls can take a string, which is treated as a label for the region. However, while \drhook doesn't use the exit call label itself, extensions that hijack \drhook calls may need the label as the unique identifier. This flag will cause \drhook to crash instead of passing it to the extension.

Any non-zero valid integer value will be treated as ``1``.

If this option isn't specified and :ref:`DR_HOOK_NVTX <DR_HOOK_NVTX>` is disabled, then it will default to ``0``. If :ref:`DR_HOOK_NVTX <DR_HOOK_NVTX>` is enabled, then :ref:`DR_HOOK_STRICT_REGIONS <DR_HOOK_STRICT_REGIONS>` will be enabled regardless of the value given.

.. ###############################################

.. _DR_HOOK_NVTX:

DR_HOOK_NVTX
------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1'

Purpose
^^^^^^^
Specifies if NVTX should be enabled at runtime or not.

Notes
^^^^^
.. todo:: Link the ENABLEDR_HOOK_NVTX compile time flag

Enables Nvidia's `NVTX <https://github.com/NVIDIA/NVTX>`_ at runtime. This assumes that NVTX has been enabled and requested at compile time of \drhook using :ref:`ENABLEDR_HOOK_NVTX <ENABLEDR_HOOK_NVTX>`.

If :ref:`DR_HOOK_NVTX <DR_HOOK_NVTX>` is enabled, then :ref:`DR_HOOK_STRICT_REGIONS <DR_HOOK_STRICT_REGIONS>` will also be enabled. It will also enable ``walltime`` and ``count`` from :ref:`DR_HOOK_OPT <DR_HOOK_OPT>`.

Setting ``DR_HOOK_TIMELINE`` to a non-zero value also causes \drhook to check the following options:

* :ref:`DR_HOOK_NVTX_SPAM_CALL_COUNT <DR_HOOK_NVTX_SPAM_CALL_COUNT>`
* :ref:`DR_HOOK_NVTX_SPAM_WT <DR_HOOK_NVTX_SPAM_WT>`

Any non-zero valid integer value will be treated as ``1``.

If this option isn't specified, then it will default to ``0``.

.. ###############################################

.. _DR_HOOK_NVTX_SPAM_CALL_COUNT:

DR_HOOK_NVTX_SPAM_CALL_COUNT
----------------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> | <valid_value> '0'
| digit ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies the spam call count for NVTX.

Notes
^^^^^
Spam call count is the number of times a \drhook region has to be called, without a cumulative runtime longer than the :ref:`DR_HOOK_NVTX_SPAM_WT <DR_HOOK_NVTX_SPAM_WT>` time, for \drhook to skip subsequent calls of that region for the functionality of NVTX. It will not skip core \drhook profiling.

This option is only available if NVTX is enabled via :ref:`DR_HOOK_NVTX <DR_HOOK_NVTX>`.

A value less than ``0`` will be set to the definition of ``nvtx_SCC_default``, typically ``10``. While it is possible to specify ``0``, this will effectively disable NVTX as all regions will be skipped - unless they can accumulate sufficient runtime to satisfy :ref:`DR_HOOK_NVTX_SPAM_WT <DR_HOOK_NVTX_SPAM_WT>` in their first call.

The size is limited to the size of :c:`int`.

If this option isn't specified, then it will default to the definition of ``nvtx_SCC_default``.

.. ###############################################

.. _DR_HOOK_NVTX_SPAM_WT:

DR_HOOK_NVTX_SPAM_WT
--------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <number> | 'number' '.' <number>
| number ::= <digit> | <double_part> <digit>
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies the spam wall time for NVTX.

Notes
^^^^^
Spam wall time is the cumulative runtime a \drhook region must have if it is not to be skipped for NVTX functionality after exceeding :ref:`DR_HOOK_NVTX_SPAM_CALL_COUNT <DR_HOOK_NVTX_SPAM_CALL_COUNT>`. It will not skip core \drhook profiling.

This option is only available if NVTX is enabled via :ref:`DR_HOOK_NVTX <DR_HOOK_NVTX>`.

:ref:`DR_HOOK_NVTX_SPAM_WT <DR_HOOK_NVTX_SPAM_WT>` is measured in seconds.

A value less than ``0`` will be set to the definition of ``nvtx_SWT_default``, typically ``0.001``.

The size is limited to the size of :c:`double`.

If this option isn't specified, then it will default to the definition of ``nvtx_SWT_default``.

.. ###############################################

.. _DR_HOOK_OPT:

DR_HOOK_OPT
-----------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <option> |  <valid_value> <delim> <option>
| delim ::= ',' | ' ' | '\t' | '/'
| option ::= <all> | <memory> | <heap> | <stack> | <rss> | <paging> | <walltime> | <cputime> | <count> | <memprof> | <cycles> | <cpuprof> | <trim> | <self> | <noself> | <noprop> | <nosize> | <cluster> | <callpath> | <papi>
| all ::= 'ALL'
| memory ::= 'MEM' | 'MEMORY'
| time ::= 'TIME' | 'TIMES'
| heap ::= 'HWM' | 'HEAP'
| stack ::= 'STK' | 'STACK'
| rss ::= 'RSS'
| paging ::= 'PAG' | 'PAGING'
| walltime ::= 'WALL' | 'WALLTIME'
| cputime ::= 'CPU' | 'CPUTIME'
| count ::= 'CALLS' | 'COUNT'
| memprof ::= 'MEMPROF'
| cycles ::= 'PROF' | 'WALLPROF' | 'CYCLES'
| cpuprof ::= 'CPUPROF'
| trim ::= 'TRIM'
| self ::= 'SELF'
| noself ::= 'NOSELF'
| noprop ::= 'NOPROP' | 'NOPROPAGATE' | 'NOPROPAGATE_SIGNALS'
| nosize ::= 'NOSIZE' | 'NOSIZEINFO'
| cluster ::= 'CLUSTER' | 'CLUSTERINFO'
| callpath ::= 'CALLPATH'
| papi ::= 'COUNTERS'

Purpose
^^^^^^^

Specifies a range of options relating to profiling parameters and outputs.

Notes
^^^^^

.. todo:: What is any_memstat?

.. todo:: paging seems to be unimplemented in main

.. todo:: what does memprof do?
.. unsure, seems to track memory being allocated and freed in regions, but can't find where it's called?
.. Also adds printing functions to ``atexit()``.

.. todo:: cycles look into cycles of child regions

.. todo:: what does cpuprof do?
.. seems to be something to do with cpu profiling and keyptr
.. could be tracking flops apparently?

.. todo:: what does nosize do?
..  Just says "\# of data elements, bytes, etc"
.. only examples I can find are '0' or external variables

.. todo:: elaborate on cluster
.. seems to be related to process & threads. i.e. (processID, thread count)

.. table:: DR_HOOK_OPT Options
  :widths: 4 10 5 6 12
  :class: longtable

  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | Flag     | Implements                                                                                             | Enables    | Increments any_memstat? | None                                                                                                                                |
  +==========+========================================================================================================+============+=========================+=====================================================================================================================================+
  | all      | None                                                                                                   | * heap     | Yes                     | None                                                                                                                                |
  |          |                                                                                                        | * stack    |                         |                                                                                                                                     |
  |          |                                                                                                        | * rss      |                         |                                                                                                                                     |
  |          |                                                                                                        | * paging   |                         |                                                                                                                                     |
  |          |                                                                                                        | * walltime |                         |                                                                                                                                     |
  |          |                                                                                                        | * cputime  |                         |                                                                                                                                     |
  |          |                                                                                                        | * cycles   |                         |                                                                                                                                     |
  |          |                                                                                                        | * count    |                         |                                                                                                                                     |
  |          |                                                                                                        | * papi     |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | memory   | None                                                                                                   | * heap     | Yes                     | None                                                                                                                                |
  |          |                                                                                                        | * stack    |                         |                                                                                                                                     |
  |          |                                                                                                        | * rss      |                         |                                                                                                                                     |
  |          |                                                                                                        | * count    |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | times    | None                                                                                                   | * walltime | No                      | None                                                                                                                                |
  |          |                                                                                                        | * cputime  |                         |                                                                                                                                     |
  |          |                                                                                                        | * count    |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | heap     | * Track and print current and max heap memory usage.                                                   | * count    | Yes                     | * Can also be enabled by :ref:`DR_HOOK_FUNCENTER <DR_HOOK_FUNCENTER>` or :ref:`DR_HOOK_FUNCEXIT <DR_HOOK_FUNCEXIT>` being enabled.  |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | stack    | * Track and print current and max stack memory usage.                                                  | * count    | Yes                     | * Can also be enabled by :ref:`DR_HOOK_FUNCENTER <DR_HOOK_FUNCENTER>` or :ref:`DR_HOOK_FUNCEXIT <DR_HOOK_FUNCEXIT>` being enabled.  |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | rss      | * Track and print current and max resident set size.                                                   | * count    | Yes                     | None                                                                                                                                |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | paging   | * Track and print current number of allocated pages.                                                   | * count    | Yes                     | None                                                                                                                                |
  |          | * Also tracks the maximum number of pages allocated per \drhook region.                                |            |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | walltime | * Tracks total and per \drhook region walltime.                                                        | * count    | No                      | * ``walltime`` is measured in seconds.                                                                                              |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | cputime  | * Tracks total and per \drhook region cputime per process.                                             | * count    | No                      | * ``cputime`` is measured in CPU ticks.                                                                                             |
  |          |                                                                                                        |            |                         | * Terminated child processes' time will also be included in this figure, i.e., multiprocessing will be reflected in the count.      |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | count    | * Tracks the total number of \drhook regions entered (``calls``).                                      | None       | No                      | * \drhook uses ``status`` purely for tracking if it is currently in a region, and does not care about the depth.                    |
  |          | * Also tracks how deep \drhook is in nested regions (``status``).                                      |            |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | memprof  | * Unsure                                                                                               | * heap     | Yes                     | None                                                                                                                                |
  |          |                                                                                                        | * stack    |                         |                                                                                                                                     |
  |          |                                                                                                        | * rss      |                         |                                                                                                                                     |
  |          |                                                                                                        | * paging   |                         |                                                                                                                                     |
  |          |                                                                                                        | * count    |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | cycles   | * Tracks CPU cycles (``cycles``).                                                                      | * walltime | No                      | * Adds printing functions to ``atexit()``.                                                                                          |
  |          | * Also tracks walltime (``wallprof``) for each \drhook region.                                         | * count    |                         | * Disables cpuprof.                                                                                                                 |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | cpuprof  | * Unsure                                                                                               | * cputime  | No                      | * Disables cycles.                                                                                                                  |
  |          |                                                                                                        | * count    |                         | * Also adds printing functions to ``atexit()``.                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | trim     | * Trims \drhook region names to remove leading spaces and characters after the first subsequent space. | None       | No                      | None                                                                                                                                |
  |          |                                                                                                        |            |                         |                                                                                                                                     |
  |          |   * e.g. "  Hello World!" becomes "Hello".                                                             |            |                         |                                                                                                                                     |
  |          | * Also converts \drhook region names to upper case.                                                    |            |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | self     | * Includes \drhook in profiling, also prints it.                                                       | None       | No                      | * Very expensive                                                                                                                    |
  |          |                                                                                                        |            |                         | * The default is to include \drhook in profiling, but doesn't print it.                                                             |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | noself   | * Excludes \drhook from profiling.                                                                     | None       | No                      | * The default is to include \drhook in profiling, but doesn't print it.                                                             |
  |          |                                                                                                        |            |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | noprop   | * Does not propagate handled signals beyond \drhook.                                                   | None       | No                      | None                                                                                                                                |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | nosize   | * Unsure                                                                                               | None       | No                      | None                                                                                                                                |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | cluster  | * Prints cluster ID and size.                                                                          | None       | No                      | None                                                                                                                                |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | callpath | * Tracks and outputs the callpath and depth of \drhook regions.                                        | None       | No                      | * Creates *much* more overhead.                                                                                                     |
  |          |                                                                                                        |            |                         | * Enables callpath mode and associated arguments.                                                                                   |
  |          |                                                                                                        |            |                         | * By default, this is to a max depth of 50, but can be changed by :ref:`DR_HOOK_CALLPATH_DEPTH <DR_HOOK_CALLPATH_DEPTH>`.           |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+
  | papi     | * Enables PAPI mode                                                                                    | * cycles   | No                      | * Start and stops PAPI instrumentation with \drhook regions                                                                         |
  |          |                                                                                                        | * walltime |                         | * Counters being monitored by PAPI can be set with :ref:`DR_HOOK_PAPI_COUNTERS <DR_HOOK_PAPI_COUNTERS>`                             |
  |          |                                                                                                        | * calls    |                         | * Disables cpuprof                                                                                                                  |
  |          |                                                                                                        | * cycles   |                         |                                                                                                                                     |
  +----------+--------------------------------------------------------------------------------------------------------+------------+-------------------------+-------------------------------------------------------------------------------------------------------------------------------------+

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_CALLPATH_INDENT:

DR_HOOK_CALLPATH_INDENT
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' 

Purpose
^^^^^^^
Specifies the number of spaces to indent callpath output by.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CALLPATH`` set.

If ``DR_HOOK_CALLPATH_INDENT`` :math:`< 1` or ``DR_HOOK_CALLPATH_INDENT`` :math:`> 8`, then it will be set to ``callpath_indent_default``, which evaluates to ``2``.

If this option isn't specified, then it will default to ``callpath_indent_default``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_CALLPATH_DEPTH:

DR_HOOK_CALLPATH_DEPTH
----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> 
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Set the maximum depth for tracking callpaths of nested \drhook regions.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CALLPATH`` set.

Caution should be used when picking this value, as being too high will greatly increase both the processing and memory overhead of \drhook.

The size is limited to the size of :c:`int`.

If ``DR_HOOK_CALLPATH_DEPTH`` is less than 0, then it will be set to ``callpath_depth_default``, which evaluates to ``50``. A size of zero will only print the first \drhook region in the callpath.

If this option isn't specified, then it will default to ``callpath_depth_default``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_CALLPATH_PACKED:

DR_HOOK_CALLPATH_PACKED
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1' 

Purpose
^^^^^^^
Outputs callpath information in a more compact format.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CALLPATH`` set.

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Compare the two
.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_CALLTRACE:

DR_HOOK_CALLTRACE
-----------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= '0' | '1' 

Purpose
^^^^^^^
Specifies if calltrace mode should be enabled or not.

Notes
^^^^^
This will only be enabled if :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CALLPATH`` set.

.. todo:: elaborate

Any non-zero valid integer value will be set to ``1``.

If this option isn't specified, then it will default to ``0``.

.. todo:: Not tested

.. ###############################################

.. _DR_HOOK_WATCH_PRINT_MAX:

DR_HOOK_WATCH_PRINT_MAX
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <digit> | <valid_value> <digit> 
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

Purpose
^^^^^^^
Specifies the max number of elements per array to be printed per watchpoint.

Notes
^^^^^
If ``DR_HOOK_WATCH_PRINT_MAX`` :math:`\geq 0`, and less than the number of elements, then the number of elements up to the value of ``DR_HOOK_WATCH_PRINT_MAX`` will be printed.

The size is limited to the size of :c:`int`.

If this option isn't specified, then it will default to ``-1``.

.. todo:: Not tested

.. ##############################################

.. _DR_HOOK_PAPI_COUNTERS:

DR_HOOK_PAPI_COUNTERS
-----------------------

Valid Values
^^^^^^^^^^^^
| valid_value ::= <counter> | <valid_value> <delim> <counter>
| delim ::= ',' | ' ' | '\t' | '/'
| counter ::= <char> | <char> <char>
| char ::= <letter> | <digit> | <symbol>
| letter ::= <lower> | <upper>
| upper ::= 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M' | 'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z'
| lower ::= 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z'
| digit ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
| symbol ::= '_'

Purpose
^^^^^^^
Specifies the counters to be monitored when in PAPI mode.

Notes
^^^^^
`PAPI <https://icl.utk.edu/papi/>`_ counters are machine specific and can displayed with the :command:`papi avail` command.

PAPI mode is enabled through :ref:`DR_HOOK_OPT <DR_HOOK_OPT>`.

The output from PAPI mode is in csv format and the file path is described, and changed, by :ref:`DR_HOOK_PROFILE <DR_HOOK_PROFILE>`.

A maximum of 4 counters can be specified. Any counters over this limit will be silently dropped.

If this option isn't specified, then it will default to the following 4 counters:

| ``API_TOT_CYC``
| ``PAPI_FP_OPS``
| ``PAPI_L1_DCA``
| ``PAPI_L2_DCM``

.. ###############################################