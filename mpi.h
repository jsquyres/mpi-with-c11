#ifndef MPI_H
#define MPI_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef int MPI_Datatype;
typedef int MPI_Comm;
typedef size_t MPI_Aint;
typedef uint64_t MPI_Count;

#define MPI_BYTE 134
#define MPI_COMM_WORLD 9999999
#define MPI_SUCCESS 0

#if defined(c_plusplus) || defined(__cplusplus)
#include "mpi_cxx.h"
#else
#include "mpi_c.h"
#endif

#endif // MPI_H
