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

/* Notes
 * If short or unsigned are not explicitly listed below, the following error results:
 * '_Generic' selector of type 'short int' is not compatible with any association
 * Thus, type promotion is not automatic here.
 */
#define MPI_Send(buf,count,type,dest,tag,comm)                          \
        _Generic((count),                                               \
                 short:     MPI_Send,                                   \
                 int:       MPI_Send,                                   \
                 long:      MPI_Send_x,                                 \
                 long long: MPI_Send_x,                                 \
                 unsigned:  MPI_Send_x,                                 \
                 MPI_Aint:  MPI_Send_x,                                 \
                 MPI_Count: MPI_Send_x)(buf,count,type,dest,tag,comm)

#endif

int main(void)
{
    /* see note above */
    MPI_Send(NULL,(short)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    /* these are all okay */
    MPI_Send(NULL,0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send(NULL,0L,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send(NULL,0LL,MPI_BYTE,0,0,MPI_COMM_WORLD);
    /* see note above */
    MPI_Send(NULL,(unsigned)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    /* these are okay, presumably because they match size_t (not sure) */
    MPI_Send(NULL,(unsigned long)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send(NULL,(unsigned long long)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    /* these are all okay */
    MPI_Send(NULL,(MPI_Aint)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send(NULL,(MPI_Count)0,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Count c = 0;
    MPI_Aint  a = 0;
    MPI_Send(NULL,a,MPI_BYTE,0,0,MPI_COMM_WORLD);
    MPI_Send(NULL,c,MPI_BYTE,0,0,MPI_COMM_WORLD);
    return 0;
}
