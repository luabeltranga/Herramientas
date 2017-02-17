#include <iostream>
#include <cmath>
#include <cstdio>

double suma1(int N), suma2(int M);

int main (void){

  double con =M_PI*M_PI/6;
  
  for(int j=1;j<=10000;j++ ){  
    printf("%d %25.20e %25.20e  \n", j , 100*fabs((suma1(j)-con)/con),100*fabs((suma2(j)-con)/con) );
  }




  return 0;
}






double suma1(int N){
 
  double suma=0;

  for(double i=1;i<=N;i++){
    suma+= 1/(i*i);
    
  }

   return suma;
}


double suma2(int N){
 
  double suma=0;

  for(double i=N;i>=1;i--){
    suma+= 1/(i*i);
    
  }

   return suma;
}
