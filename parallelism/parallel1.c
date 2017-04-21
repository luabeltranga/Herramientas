#include <stdio.h>
#include <omp.h>

int main(void){

#pragma omp parallel num_threads (4)
  {
  int id = omp_get_thread_num();
  printf("HELLO, world., from thread %d!\n",id);
  }
  return 0;
}
