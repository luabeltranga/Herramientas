#include <iostream>
#include <ctime>
#include <random>
const int N = 16; //tamaño de la matriz N*N
const int SM = 8; //tamaño bloque para el cache
void matrix_mul(void);


int main(void){
  
  
  matrix_mul(); //funcion que multiplica las matrices

  
  
  return 0;
}


void matrix_mul(void){
  int mul1[N*N]={0};//declaracion de matrices
  int mul2[N*N]={0};
  int res[N*N]={0};
  clock_t cputime1, cputime2; //relojes
  std::mt19937 g1(10),g2(11); //random semilla
  std::uniform_real_distribution<double> test(0,1); //distribucion normal

  //rellenando las matrices de numeros aleatorios
  for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      //mul1[ii*N+jj]=test(g1);
      //mul1[ii*N+jj]=test(g1);
      if(ii==jj){
      mul1[ii*N+jj]=2;
      mul2[ii*N+jj]=2;
      }
    }
  }
  /*
  //formula rapida para el producto de matrices
  cputime1 = clock();
  for (int i = 0; i < N; i += SM){
    for (int j = 0; j < N; j += SM){
      for (int k = 0; k < N; k += SM){
	for (int i2 = 0, *rres = &res[i*N+j],
	       *rmul1 = &mul1[i*N+k]; i2 < SM;
	     ++i2, rres += N, rmul1 += N)
	  for (int k2 = 0, *rmul2 = &mul2[k*N+j];
	       k2 < SM; ++k2, rmul2 += N){
	    for (int j2 = 0; j2 < SM; ++j2){
	      rres[j2] += rmul1[k2] * rmul2[j2];
	    }
	  }
      }
    }
  }
  cputime2=clock() - cputime1;
  std::cout<<"Time with faster algorithm for matrix multiplication: "<<((double)cputime2)/CLOCKS_PER_SEC<<std::endl;
  
  //segunda forma de multiplicar matrices
  
  */
  cputime1 = clock();
  for (int i = 0; i < N; i ++){
    for (int j = 0; j < N; j ++){
      for (int k = 0; k < N; k ++){
	res[k*N+j]+=mul1[k*N+i]*mul2[i*N+j];
      }
    }
  }
  cputime2=clock() - cputime1;
  std::cout<<"Time with slower algorithm for matrix multiplication: "<<((double)cputime2)/CLOCKS_PER_SEC<<std::endl;
   
 for(int ii = 0;ii<N;ii++){
    for(int jj= 0;jj<N;jj++){
      std::cout<<res[ii*N+jj]<<" ";
    }
    std::cout<<std::endl;
  }
  
  
}

