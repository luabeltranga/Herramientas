#include "mpi.h"
#include <stdio.h>

int main(int argc, char **argv) 
{
  /* MPI Variables */
  int dest, noProcesses, processId, src, tag;
  MPI_Status status;
  
  /*Problem variables*/
  int sum;
  double range = 1000;
  double range_b = 0;
  int total ;
  
  /* MPI setup */
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &noProcesses);
  MPI_Comm_rank(MPI_COMM_WORLD, &processId);
  
  /* Adjust problem size for sub-process */
  range_b = range/noProcesses;
  
  /* Calculate sum for subproblem */ 
  sum = 0;
  for (int i = 0; i < range_b; ++i) {
    sum += 1;
  }
  
  /* Collect info and print results */
  tag = 0;
  if (0 == processId) { /* Master */
    total = sum; 
    for (src = 1; src < noProcesses; ++src) {
      MPI_Recv(&sum, 1, MPI_DOUBLE, src, tag, MPI_COMM_WORLD, &status);
      total += sum;
    }
    fprintf(stderr, "The sum is : %25d\n",total);
  }
  else { /* slaves only send */
    dest = 0; 
    MPI_Send(&sum, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
  }
  
  /* finish */
  MPI_Finalize();
  
  return 0;
}
