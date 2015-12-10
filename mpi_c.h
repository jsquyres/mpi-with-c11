#ifndef MPI_C_H
#define MPI_C_H

#if !defined(MPI_H)
#error do not include this file directly; include mpi.h
#endif

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
             default:   MPI_Send_x)(buf,count,type,dest,tag,comm)
#endif

#endif // MPI_C_H
