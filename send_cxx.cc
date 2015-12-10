#include <stdio.h>

#include "mpi.h"

int MPI_Send(const char *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    printf("CXX MPI_Send count (%s): %llu\n", buf, count);
    return MPI_SUCCESS;
}
