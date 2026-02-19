.. role:: c(code)
   :language: c

Output Formats
==============

.. _Profiling_opt3:

Profiling
---------

Purpose
^^^^^^^

Columns
^^^^^^^

.. list-table:: Profiling Output Columns
   :widths: auto
   :header-rows: 1

   * - Header
     - Unit
     - Description
   * - #
     - Unitless count
     - The order of the \drhook regions by self time.
   * - %\ Time (self)
     - Unitless pertcentage
     - The share of total time each \drhook region takes up, i.e. (``Self (sec)``) :math:`/` (total time).
   * - Cumul (sec)
     - Seconds
     - A running total of each \drhook region's self time (``Self(sec)``) as their order (``#``) increases. When running multithreaded, this is from the thread with the maximum self time, as denoted by a ``*`` prefix to the ``Routine@<thread-id>`` column.
   * - Self (sec)
     - Seconds
     - Time spent in a \drhook region, excluding child regions.
   * - Total (sec)
     - Seconds
     - Time spent in a \drhook region, including child regions.
   * - # of calls
     - Unitless count
     - How many times a \drhook region was entered.
   * - Self ms/call
     - Milliseconds
     - Time spent in a \drhook region, excluding child regions, per call. I.e. :math:`1000 *` (``Self (sec)``) :math:`/` (``# of calls``).
   * - Total ms/call
     - Milliseconds
     - Time spent in a \drhook region, including child regions, per call. I.e. :math:`1000 *` (``Total (sec)``) :math:`/` (``# of calls``).

Notes
^^^^^

The default filename is :c:`drhook.prof.%d`

.. ###############################################