#include <iostream>
#include <cstdio>
#include <cmath>


typedef double babas;


babas suma1(int N) , suma2 (int N) , suma3 (int N);


int main(void){

  for (int j=1; j<=10000 ;j++){
    
    std::printf("%d %6.16e %6.16e \n",j,std::fabs((suma1(j)-suma3(j))/suma3(j)),std::fabs((suma1(j)-suma2(j))/suma2(j))) ;
    // printf("%d %10.3e %10.3e %10.3e \n",j,suma1(j),suma2(j),suma3(j)) ;
  }




  return 0;
}


babas suma1(int N){

  babas  sum = 0;
  int sign =-1;
  for (babas i=1 ;i<=2*N;i++){
    sum+=sign*i/(i+1.0);
    sign*=-1;
    }
  return sum;
}


babas suma2(int N){

  babas  sum1 = 0,sum2=0;

  for (babas i=1 ;i<=N;i++){
    sum1+=1.0-1.0/(2*i);
    sum2+=2*i/(2*i+1.0);
    }
  return sum2-sum1;
}



babas suma3(int N){

  babas  sum = 0;

  for (babas i=1 ; i<=N;i++){
    sum+=1/(2*i)/(2*i+1);
    }
  return sum;
}





/* trucos: para signos alternantes deinir una variable con -1 y cuando la use multiplicarla por -1 y viceversa
   

   typedef para colocar un apodo al declarar euna variable:
   
   typedef double babas;

   cada vez que se escriba la palabra babas el programa lo interpeta como double. 
*/




