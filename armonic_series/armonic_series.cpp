#include <iostream>
#include <cstdio>
#include <cmath>

double suma1(unsigned int n), suma2 (double n);


int main(void){
  double test=0;
  for(int j=1;j<=1000;j++){
    test = log10(fabs((suma1(j)-suma2(j))/(suma1(j)+suma2(j))));
    
    std::printf("%.16e %20.16e \n",log10(j),test);
  }



  return 0;
}




double suma1(unsigned int n){
  double sum=0;

  for (int i=1; i<=n; i++){
    sum+=1.0/i;
  }

  return sum;
}

double suma2(double n){
  double sum=0;

  for (double i=n; i>=1; i--){
    sum+=1.0/i;
  }

  return sum;
}
