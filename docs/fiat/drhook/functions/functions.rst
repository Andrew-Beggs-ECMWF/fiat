.. role:: c(code)
   :language: c

Functions
=========

.. _backtrace():

backtrace()
-----------

Signature
^^^^^^^^^

:c:`static int backtrace(void **buffer, int size)`

Purpose
^^^^^^^

Assumption: Used to provide a dummy function implementation, which is commonly defined by compilers other than the *NEC* compiler

Notes
^^^^^

Behind preprocessor guard :c:`#ifdef__NEC__`

.. ###############################################