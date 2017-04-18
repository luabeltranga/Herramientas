#include <iostream>
#include <ctime>
#include <random>
const int N = 4; //tamaño de la matriz N*N
const int csize =2 ; //tamaño bloque para el cache
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
void matrix_mul(void);


int main(void){
  
  
  matrix_mul(); //funcion que multiplica las matrices
  
  
  
  return 0;
}


void matrix_mul(void){
  int mul1[N*N]={0};//declaracion de matrices
  int mul2[N*N]={0};
  int res[N*N]={0};
  int babas = 0;
  clock_t cputime1, cputime2; //relojes
  std::mt19937 g1(10),g2(11); //random semilla
  std::uniform_real_distribution<double> test(0,1); //distribucion normal
  
  //rellenando las matrices de numeros aleatorios
  for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      //mul1[ii*N+jj]=test(g1);
      //mul1[ii*N+jj]=test(g1);
      
      mul1[ii*N+jj]=ii;
      mul2[ii*N+jj]=ii;
      
    }
  }
  
  //formula rapida para el producto de matrices
  cputime1 = clock();
  for (int i = 0; i < N; i += csize){
    for (int j = 0; j < N; j += csize){
      for (int k = 0; k < N; ++k){
	for (int i2 = i ; i2< min(i+csize,N) ; ++i2){
	  babas = mul1[k*N+i2];  
	  for (int j2 = j; j2 < min(j+csize,N) ; ++j2){
	    res[k*N+j2] += babas * mul2[i2*N+j2];
	  }	    
	}
      }
    }
  }
  cputime2=clock() - cputime1;
  std::cout<<"Time with faster algorithm for matrix multiplication: "<<((double)cputime2)/CLOCKS_PER_SEC<<std::endl;
  
  //segunda forma de multiplicar matrices
  /*
  cputime1 = clock();
  for (int i = 0; i < N; i ++){
  for (int j = 0; j < N; j ++){
  for (int k = 0; k < N; k ++){
  res[i*N+j]+=mul1[i*N+k]*mul2[k*N+j];
  }
  }
  }
  cputime2=clock() - cputime1;
  std::cout<<"Time with slower algorithm for matrix multiplication: "<<((double)cputime2)/CLOCKS_PER_SEC<<std::endl;
  */
  for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      std::cout<<mul1[ii*N+jj]<<" ";
    }
    std::cout<<std::endl;
  }
  
  
}

