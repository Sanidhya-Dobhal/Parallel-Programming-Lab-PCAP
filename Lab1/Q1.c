/* Q1) Write a simple MPI program to find out pow (x, rank) for all the processes where ‘x’ is the integer constant and ‘rank’ is the rank of the process */

#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>
int main(int argc,char * argv[])
{
  int x = atoi(argv[1]); //This takes command line argument and converts it from ASCII to Integer(atoi)
  int rank;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  printf("The rank is %d and %d^rank = %d\n",rank,x,(int)pow(x,rank));
  MPI_Finalize();
  return 0;
}
//For this code to run while 'mpirun -np <number of processes> ./a.out', we need to add a last argument that is the value of x
//Therefore run this program as mpirun -np 4 ./a.out 3, 
//where x=3