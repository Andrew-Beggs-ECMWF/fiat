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
   :widths: 20, 15, 65
   :header-rows: 1
   :class: longtable

   * - Header
     - Unit
     - Description
   * - #
     - Unitless count
     - The order of the \drhook regions by self time.
   * - %\ Time (self)
     - Percentage
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
   * - N/A (Packed callpath)
     - Unitless
     - Prints the callpath for this \drhook region in packed mode. This is up to the maximum specified by  :ref:`DR_HOOK_CALLPATH_DEPTH <DR_HOOK_CALLPATH_DEPTH>`, which defaults to 50. This is only part of the output when :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CALLPATH`` set and :ref:`DR_HOOK_CALLPATH_PACKED <DR_HOOK_CALLPATH_PACKED>` is enabled.
   * - Routine@<thread-id>
     - Unitless label
     - This is the name of a \drhook region and the thread ID that it ran on. If included, \drhook will also display the filename the region was called from. When running multithreaded, a ``*`` prefix indicates that this is from the thread with the maximum self time.
   * - [Cluster:(id,size)]
     - Unitless label
     - ``id`` is the cluster ID a \drhook region and thread combination a measurement belongs to. This is to differentiate between the same region on different threads, but with a guarantee that the range of IDs will be linear and complete. Note that this is purely for the user's readability, and there is no deterministic mapping between the cluster ID and the thread ID. ``cluster_size`` is the number of times this \drhook region was called by different threads - this is not necessarily the max thread count. This is only part of the output when :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CLUSTERINFO`` set.
   * - N/A (Unrolled callpath)
     - Unitless
     - Prints the callpath for this \drhook region in unrolled mode. This is up to the maximum specified by  :ref:`DR_HOOK_CALLPATH_DEPTH <DR_HOOK_CALLPATH_DEPTH>`, which defaults to 50. This is only part of the output when :ref:`DR_HOOK_OPT <DR_HOOK_OPT>` has ``CALLPATH`` set and :ref:`DR_HOOK_CALLPATH_PACKED <DR_HOOK_CALLPATH_PACKED>` is disabled.

.. todo:: Routine@<thread-id> how is filename included? Seems to be ``call DR_HOOK_FILE`` in yomhook, but this needs its own inteface section or somthing.

.. todo:: opt_sizeinfo
Notes
^^^^^

The default filename is :c:`drhook.prof.%d`

.. ###############################################