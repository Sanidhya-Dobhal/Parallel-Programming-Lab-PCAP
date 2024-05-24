//Q2) Write a program in MPI where even ranked process prints “Hello” and odd ranked process prints “World”.

#include <stdio.h>
#include "mpi.h"
 int main(int argc, char * argv[])
 {
   int rank;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    if (rank%2==0)
         printf("Hello %d\n",rank);
    else
      printf("World %d\n",rank);
   MPI_Finalize();
 }