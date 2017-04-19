#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "papi.h"

const int N = 2048; // matrix size
const int csize = 64;


void code_to_be_measured(const double * A,const double * B, double *C);

int main(int argc, char **argv)
  
{
  
  // Matrix declaration : Modeled as 1D array
  
  // Declare as pointers and ask for memory to use the heap
  
  double *A = new double [N*N];
  double *B = new double [N*N];
  double *C = new double [N*N];
  
  // initialize matrices
  
  for (int ii =0; ii < N; ++ii) {
    
    for (int jj =0; jj < N; ++jj) {
      A[ii*N + jj] = 1.0 ;
      
      B[ii*N + jj] = 2.0 ;
      
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
  
  // printf("%d %11.10e %11e\n",csize, proc_time,mflops);
  
  //print C[]
  long rete = 0;
  for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
     rete+=C[ii*N+jj];
    }
  }
  long tmpN = N;
  long retetheo = 2*std::pow(tmpN, 3);
  std::cout << rete << "  " << retetheo << std::endl;
  printf("%d %11.10e %11e\n",csize, proc_time,mflops);
  delete [] A;
  
  delete [] B;

  delete [] C;
  A=nullptr;
  B=nullptr;
  C=nullptr;
  delete A;
  delete B;
  delete C;
  return 0;
  
}

void code_to_be_measured(const double * A,const  double * B, double *C)
  
{  
  //cache matrix multiplication

  double buffer = 0; 
  for (int i = 0; i < N; i += csize){
    for (int j = 0; j < N; j += csize){
      for (int k = 0; k < N; ++k){
	for (int i2 = i ; i2<i+csize ; ++i2){
	  buffer = A[k*N+i2];  
	  for (int j2 = j; j2 <j+csize ; ++j2){
	    C[k*N+j2] += buffer * B[i2*N+j2];
	  }	    
	}
      }
    }
  }
 
}
