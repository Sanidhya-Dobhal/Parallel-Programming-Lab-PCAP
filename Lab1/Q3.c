//Q3) Write a program in MPI to simulate simple calculator. Perform each operation using different process in parallel.  

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
int main(int argc, char * argv[])
{
    int rank;
    int a =atoi(argv[1]);
    int b = atoi(argv[2]);
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if(rank==0)
        printf("%d + %d = %d\n",a,b,a+b);
    else if(rank==1)
        printf("%d - %d = %d\n",a,b,a-b);
    else if(rank==2)
        printf("%d x %d = %d\n",a,b,a*b);
    else if(rank==3)
        printf("%d / %d = %d\n",a,b,a/b);
    else
        printf("This operation is not defined as the number of processes entered are beyond range \n");
    MPI_Finalize();
}
//This program takes a and b as command-line arguments, therefore use it as 
//mpirun -np 4 ./a.out 6 2