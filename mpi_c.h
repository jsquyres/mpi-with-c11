#ifndef MPI_C_H
#define MPI_C_H

#if !defined(MPI_H)
#error do not include this file directly; include mpi.h
#endif

int MPI_Send(const char *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);

int MPI_Send_x(const char *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);

#undef WANT_GENERICS
// Don't define the generics when we're building libmpi itself
#if defined(BUILDING_LIBMPI) && BUILDING_LIBMPI
#    define WANT_GENERICS 0
#elif defined(c_plusplus) || defined(__cplusplus)
#    define WANT_GENERICS 0
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L)
#    define WANT_GENERICS 1
#else
#    error You do not have C11 generics
#endif

#if WANT_GENERICS
#define MPI_Send(buf,count,type,dest,tag,comm)                          \
    _Generic((count),                                                   \
             int:       MPI_Send,                                       \
             MPI_Count: MPI_Send_x,                                     \
             default:   MPI_Send)(buf,count,type,dest,tag,comm)
#endif

#endif // MPI_C_H
