#ifndef MPI_CXX_H
#define MPI_CXX_H

#if !defined(MPI_H)
#error do not include this file directly; include mpi.h
#endif

extern "C" {
    int MPI_Send(const char *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);

    int MPI_Send_x(const char *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
}

int MPI_Send(const char *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);

#endif // MPI_CXX_H
