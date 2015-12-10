#include <stdint.h> /* intN_t */
#include <stdlib.h> /* NULL   */
#include <mpi.h>

int main(void)
{
    int8_t c = 0;
    MPI_Send(NULL,c,MPI_BYTE,0,0,MPI_COMM_SELF);
    return 0;
}
