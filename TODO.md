Console
=======

Process
-------
* ~~Create single process~~
* ~~Send signal to process~~
* ~~Generate core dump for process~~
* ~~Parse /proc/pid/stat and /proc/pid/status for process info~~
* ~~Get CPU usage for user and kernel over some amount of time~~
* ~~Get the symlinks of open files of a process, excluding STDIN, STDOUT, STDERR~~
* Parse /proc/pid/maps to get the memory maps, possibly store as string, or parse into array of row structures to properly display

Ape
---
* ~~Instantiate a Process for every process dir in /proc~~
* ~~Update all processes, getting new u_cpu and s_cpu for each~~
* ~~Sort all processes based on CPU usage~~
* Remove processes that have finished execution (no longer in /proc) when updating
