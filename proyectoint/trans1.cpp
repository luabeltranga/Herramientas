#include <iostream>

const int N = 16; //tamaño de la matriz N*N
const int csize = 8; //tamaño bloque para el cache
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
void matrix_trans(void);


int main(void){
  
  
  matrix_trans(); //funcion que transpone las matrices

  
  
  return 0;
}


void matrix_trans(void){
  int MT[N*N]={0};//declaracion de matrices
  int M[N*N]={0};
  
  //rellenando la matriz
  for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      if(ii<jj){
	M[ii*N+jj]=2;
      }
    }
  }
  
  //formula rapida para la transposicion de matrices
  for (int ii=0; ii<N; ii+=csize){
    for (int jj=0; jj<N; jj+=csize){
      for (int i=ii; i<=min(N,ii+csize-1); ++i){
	for (int j=jj; j<=min(N,jj+csize-1); ++j){
	  MT[i*N+j] = M[j*N+i];	    
	}
      }
    }
  }
  
  for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      std::cout<<M[ii*N+jj]<<" ";
    }
    std::cout<<std::endl;
  }
  
  
}

