.. role:: c(code)
   :language: c

Definitions
===========

.. _\_DRHOOK_C_:

_DRHOOK_C_
----------

Value
^^^^^

:c:`1`

Purpose
^^^^^^^

.. todo:: Unknown purpose

Never used within :file:`drhook.c`

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

None

.. ###############################################

.. _\_DRHOOK_FILE_:

_DRHOOK_FILE_
-------------

Value
^^^^^

:file:`drhook.c`

Purpose
^^^^^^^

Used within error handling to specify the source file where it occurred.

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

None

.. ###############################################

.. _\_GNU_SOURCE:

_GNU_SOURCE
-----------

Value
^^^^^

No value defined

Purpose
^^^^^^^

.. todo:: Unknown

Never used within :file:`drhook.c`.

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

None

.. ###############################################

.. _HOST_NAME_MAX:

HOST_NAME_MAX
-------------

Value
^^^^^

:c:`_POSIX_HOST_NAME_MAX`

Purpose
^^^^^^^

Used to set the max size of char arrays for node HOSTNAME.

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

:c:`!defined(HOST_NAME_MAX) && defined(_POSIX_HOST_NAME_MAX)`

.. ###############################################

.. _HOST_NAME_MAX:

HOST_NAME_MAX
-------------

Value
^^^^^

:c:`_SC_HOST_NAME_MAX`

Purpose
^^^^^^^

Used to set the max size of char arrays for node HOSTNAME.

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

:c:`!defined(HOST_NAME_MAX) && defined(_SC_HOST_NAME_MAX)`

.. ###############################################

.. _EC_HOST_NAME_MAX:

EC_HOST_NAME_MAX
----------------

Value
^^^^^

:c:`HOST_NAME_MAX`

Purpose
^^^^^^^

Used to set the max size of char arrays for node HOSTNAME.

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

:c:`defined(HOST_NAME_MAX)`

.. ###############################################

.. _EC_HOST_NAME_MAX:

EC_HOST_NAME_MAX
----------------

Value
^^^^^

:c:`512`

Purpose
^^^^^^^

Used to set the max size of char arrays for node HOSTNAME.

Preprocessor Guards
^^^^^^^^^^^^^^^^^^^

:c:`!defined(HOST_NAME_MAX)`
