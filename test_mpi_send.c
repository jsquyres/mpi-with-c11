/* inspired by and derived from https://github.com/nspark/shmemx */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/******************************/

/* mpi.h                      */
typedef int MPI_Datatype;
typedef int MPI_Comm;
typedef size_t MPI_Aint;
typedef uint64_t MPI_Count;

#define MPI_BYTE 134
#define MPI_COMM_WORLD 9999999
#define MPI_SUCCESS 0

/******************************/


int MPI_Send(const char *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    printf("MPI_Send (%s): %d\n", buf, count);
    return MPI_SUCCESS;
}


int MPI_Send_x(const char *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
    printf("MPI_Send_x (%s): %llu\n", buf, count);
    return MPI_SUCCESS;
}


#if defined(__STDC_VERSION__) && (__STDC_VERSION__ == 201112L)

/*
 * "default" selector FTW!
 */
#define MPI_Send(buf,count,type,dest,tag,comm)                          \
    _Generic((count),                                                   \
             int:       MPI_Send,                                       \
             MPI_Count: MPI_Send_x,                                     \
             default:   MPI_Send)(buf,count,type,dest,tag,comm)
#else
#error you do not have c11 generics
#endif

int main(void)
{
    short s = 3;
    MPI_Send("short",s,MPI_BYTE,0,0,MPI_COMM_WORLD);
    s = -3;
    MPI_Send("short neg",s,MPI_BYTE,0,0,MPI_COMM_WORLD);

    MPI_Send("int const",17,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send("long const",18L,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send("long long const",19LL,MPI_BYTE,0,0,MPI_COMM_WORLD);

    // 2^31+1
    unsigned u = 2147483649;
    MPI_Send("unsigned",u,MPI_BYTE,0,0,MPI_COMM_WORLD);

    // 2^63+1
    unsigned long ul = 9223372036854775809UL;
    MPI_Send("unsigned long",ul,MPI_BYTE,0,0,MPI_COMM_WORLD);
    unsigned long long ull = 9223372036854775809ULL;
    MPI_Send("unsigned long long",ull,MPI_BYTE,0,0,MPI_COMM_WORLD);

    MPI_Aint a = 27;
    MPI_Send("MPI_Aint",a,MPI_BYTE,0,0,MPI_COMM_WORLD);

    MPI_Count c = 9223372036854775809ULL;
    MPI_Send("MPI_Count",c,MPI_BYTE,0,0,MPI_COMM_WORLD);

    const int x = 3;
    MPI_Send("const int",x,MPI_BYTE,0,0,MPI_COMM_WORLD);
    volatile int y = 3;
    MPI_Send("volatile int",y,MPI_BYTE,0,0,MPI_COMM_WORLD);

    return 0;
}
