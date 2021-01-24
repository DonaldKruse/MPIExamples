This example creates a shared library "my_mpi.so" from my_mpi.c that
counts the number of times MPI_Send/Recv/Init/Finalize is called.

This allows the user to make changes to those routines in order to profile
or modify them without having to recompile the executable that is using the
MPI routines.
