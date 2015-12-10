#include <stdio.h>

#include "mpi.h"

int MPI_Send(const char *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    printf("C MPI_Send (%s): %d\n", buf, count);
    return MPI_SUCCESS;
}

int MPI_Send_x(const char *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    printf("C MPI_Send_x (%s): %llu\n", buf, count);
    return MPI_SUCCESS;
}
