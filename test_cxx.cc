/* inspired by and derived from https://github.com/nspark/shmemx */

#include "mpi.h"


int main(int argc, char *argv[])
{
    short s = 3;
    MPI_Send("short",s,MPI_BYTE,0,0,MPI_COMM_WORLD);
    s = -3;
    MPI_Send("short neg",s,MPI_BYTE,0,0,MPI_COMM_WORLD);

    MPI_Send("int const",17,MPI_BYTE,0,0,MPI_COMM_WORLD);
#if 0
    MPI_Send("long const",18L,MPI_BYTE,0,0,MPI_COMM_WORLD);
#endif
    MPI_Send("long long const",19LL,MPI_BYTE,0,0,MPI_COMM_WORLD);

#if 0
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
#endif

    MPI_Count c = 9223372036854775809ULL;
    MPI_Send("MPI_Count",c,MPI_BYTE,0,0,MPI_COMM_WORLD);

    const int x = 3;
    MPI_Send("const int",x,MPI_BYTE,0,0,MPI_COMM_WORLD);
    volatile int y = 3;
    MPI_Send("volatile int",y,MPI_BYTE,0,0,MPI_COMM_WORLD);

    return 0;
}
