ebpf kernel probe
===================

Idea
====

In order to get the information about the process that tries to initiate the connection and make
sure no surrogate process, like socat, is used to conceal the real initiator an ebpf
kernel probe can be used to trace the execve syscalls (in order to get which processes started which processes)
and gather the parent process, its program file and argument vector, as well as the program file and argument vector
of the child process at child creation time.

In order to make the direct correlation between the syscalls for establishing connections and sending packets
to the processes, an ebpf kernel probe for the sendmsg and tcp_connect syscalls can be used.

Some go functions get the information from the probes and send them to the parent process where the data is cached until needed or the process exits.

The information stored is used in order to determine the real process.