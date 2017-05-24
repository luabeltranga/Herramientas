#include <omp.h>
#include <cstdio>
#include <cmath>
#include <iostream>
int main(void) {
  
  const long N = 100000;
  long sum=0 ;
  int i, *a;
  a=new int[N];
#pragma omp parallel num_threads(4)
  {
#pragma omp parallel for
    for(i = 0; i < N; i++)
      
      a[i] = 1 ;
  }
  
#pragma omp parallel  for  reduction(+:sum) num_threads(5) 
  for(int  i = 0; i < N; i++)
    {
      sum +=  a[i];
      
      }
  
  
  std::cout << sum << std::endl;
  delete [] a;
  return 0;
}
