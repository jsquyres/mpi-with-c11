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


int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
   printf("MPI_Send\n");
   return MPI_SUCCESS;
}


int MPI_Send_x(const void *buf, MPI_Count count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
{
   printf("MPI_Send_x\n");
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
    printf("(short)0...");
    MPI_Send(NULL,(short)0,MPI_BYTE,0,0,MPI_COMM_WORLD);

    printf("0...");
    MPI_Send(NULL,0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    printf("0L...");
    MPI_Send(NULL,0L,MPI_BYTE,0,0,MPI_COMM_WORLD);
    printf("0LL...");
    MPI_Send(NULL,0LL,MPI_BYTE,0,0,MPI_COMM_WORLD);

    printf("(unsigned)0...");
    MPI_Send(NULL,(unsigned)0,MPI_BYTE,0,0,MPI_COMM_WORLD);

    printf("(unsigned long)0...");
    MPI_Send(NULL,(unsigned long)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    printf("(unsigned long long)0...");
    MPI_Send(NULL,(unsigned long long)0,MPI_BYTE,0,0,MPI_COMM_WORLD);

    printf("(MPI_Aint)0...");
    MPI_Send(NULL,(MPI_Aint)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    printf("(MPI_Count)0...");
    MPI_Send(NULL,(MPI_Count)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Count c = 0;
    MPI_Aint  a = 0;
    printf("MPI_Count c = 0...");
    MPI_Send(NULL,a,MPI_BYTE,0,0,MPI_COMM_WORLD);
    printf("MPI_Aint  a = 0...");
    MPI_Send(NULL,c,MPI_BYTE,0,0,MPI_COMM_WORLD);

    const int x = 3;
    printf("const int x = 3...");
    MPI_Send(NULL,x,MPI_BYTE,0,0,MPI_COMM_WORLD);
    printf("volatile int y = 3...");
    volatile int y = 3;
    MPI_Send(NULL,y,MPI_BYTE,0,0,MPI_COMM_WORLD);

    return 0;
}
