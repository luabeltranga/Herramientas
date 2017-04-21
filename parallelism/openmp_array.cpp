#include <omp.h>
#include <cstdio>
#include <cmath>
#include <iostream>
int main(void) {
  
  const long N = 10;
  long sum  ;
  int i, *a;
  a=new int[N];
#pragma omp parallel num_threads (4)  
  {
#pragma omp parallel for
  for(i = 0; i < N; i++)
    
    a[i] = 1 ;
  }
  
#pragma omp parallel 
  
  {
#pragma omp  for   reduction(+:sum) 
    for(int  i = 0; i < N; i++)
      {
	sum +=  a[i];
	
      }
    
  }
  std::cout << sum << std::endl;
  delete [] a;
  return 0;
}
