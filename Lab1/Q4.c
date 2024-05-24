//Q4) Write a program in MPI to toggle the character of a given string indexed by the rank of the process.  
//Hint:  Suppose  the  string is HELLO and there are 5 processes,then process 0 toggle ‘H’ to ‘h’, process 1 toggle ‘E’ to ‘e’ and so on.    

#include <stdio.h>
#include "mpi.h"
#include <string.h>
int main(int argc,char * argv[])
{
  int rank;
  char  * str = argv[1];
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
  if(str[rank]>=65 && str[rank]<=90)
    str[rank] = str[rank]+32;
  else if(str[rank]>=97 && str[rank]<=122)
    str[rank] = str[rank]-32;
  printf("%s\n",str);
  MPI_Finalize();
}
//Here a command Line argument is required
//Therefore sample input "mpirun -np 5 ./a.out HelLo"