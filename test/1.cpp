#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "papi.h"

const int N = 1024; // matrix size
const int csize = 1024;
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) ) //for blocking with no factor number

void code_to_be_measured(const double * A,const double * B, double *C);

int main(int argc, char **argv)
  
{
  
  // Matrix declaration : Modeled as 1D array
  
  // Declare as pointers and ask for memory to use the heap
  
  double *A = new double [N*N], *B = new double [N*N], *C = new double [N*N];
  
  // initialize matrices
  
  for (int ii =0; ii < N; ++ii) {
    
    for (int jj =0; jj < N; ++jj) {
      A[ii*N + jj] = 0.0 ;
      
      B[ii*N + jj] = 0.0 ;
      
      C[ii*N+jj]= 0.0;
    }
    
  }
  
  // PAPI vars
  
  float real_time, proc_time,mflops;
  
  long long flpops;
  float ireal_time, iproc_time, imflops;
  
  long long iflpops;
  
  int retval;
  
  // PERFOMANCE MEASURE
  
  // start PAPI counters
  
  if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
    
    {
      
      printf("Could not initialise PAPI_flops \n");
      
      printf("Your platform may not support floating point operation event.\n");
      
      printf("retval: %d\n", retval);
      
      exit(1);
      
    }
  
  code_to_be_measured(A, B, C);
  
  if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
    
    {
      
      printf("retval: %d\n", retval);
      
      exit(1);
      
    }
  
  printf("%d %11.10e %11e\n",csize, proc_time,mflops);
  
  //print C[]

  /*for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      std::cout<<C[ii*N+jj]<<" ";
    }
    std::cout<<std::endl;
  }
  */
  delete [] A;
  
  delete [] B;

  delete [] C;
  
  return 0;
  
}

void code_to_be_measured(const double * A,const  double * B, double *C)
  
{  
  //cache matrix multiplication

  double babas = 0; // auxiliar to buffer a value 
  for (int i = 0; i < N; i += csize){
    for (int j = 0; j < N; j += csize){
      for (int k = 0; k < N; ++k){
	for (int i2 = i ; i2<min(i+csize,N) ; ++i2){
	  babas = A[k*N+i2];  
	  for (int j2 = j; j2 <min(j+csize,N) ; ++j2){
	    C[k*N+j2] += babas * B[i2*N+j2];
	  }	    
	}
      }
    }
  }
 
}
