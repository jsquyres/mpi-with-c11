#ifndef MPI_CXX_H
#define MPI_CXX_H

#if !defined(MPI_H)
#error do not include this file directly; include mpi.h
#endif

int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    return MPI_SUCCESS;
}

int MPI_Send(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    return MPI_SUCCESS;
}

template <class T>
int MPI_Send(const void *buf, T count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    return MPI_Send(buf,static_cast<MPI_Count>(count),datatype,dest,tag,comm);
}

#endif // MPI_CXX_H
