#include <stdio.h>
#include <mpi.h>

static unsigned int num_init = 0;
static unsigned int num_send = 0;
static unsigned int num_recv = 0;
static unsigned int num_finalize = 0;

int MPI_Init(int *argc, char ***argv) 
{
    int ret;
    
    ret = PMPI_Init(argc, argv);
    num_init++;
    return ret;
}

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest,
             int tag, MPI_Comm comm)
{
    int ret;

    ret = PMPI_Send(buf, count, datatype, dest, tag, comm);
    num_send++;
    return ret;
}


int MPI_Recv(void *buf, int count, MPI_Datatype datatype,
            int source, int tag, MPI_Comm comm, MPI_Status *status)
{
    int ret;
    
    ret = PMPI_Recv(buf, count, datatype, source, tag, comm, status);
    num_recv++;
    return ret;
}

int MPI_Finalize()
{
    int ret;

    ret = PMPI_Finalize();
    num_finalize++;
    printf("Number of MPI_Init() called : %d\n", num_init);
    printf("Number of MPI_Send() called : %d\n", num_send);
    printf("Number of MPI_Recv() called : %d\n", num_recv);
    printf("Number of MPI_Finalize() called : %d\n", num_finalize);
    
    return ret;
}

    
