#include <iostream>
#include <cmath>
#include <cstdio>

double p (double x ), q(double y ), r (double z );


int main (void){

  double z= 0.992;
  
  for (double i=1; i<=160 ;i++){
    z+=0.0001;
    printf("%.4f %10.2e %10.2e %10.2e \n", z , p(z) , q(z), r(z));
  }
  return 0;
}


double r( double x){

  double sum=0;

  sum=1-8*x+28*std::pow(x,2)-56*std::pow(x,3)+70*std::pow(x,4)-56*std::pow(x,5)+28*std::pow(x,6)-8*std::pow(x,7)+std::pow(x,8);
  
  
  return sum;
}











double q( double x){

  double sum=0;

  sum=1-8*x+28*x*x-56*x*x*x+70*x*x*x*x-56*x*x*x*x*x+28*x*x*x*x*x*x-8*x*x*x*x*x*x*x+x*x*x*x*x*x*x*x;
  
  
  return sum;
}








double p( double x){

  double sum=0;

  sum=std::pow(1-x,8);
  
  
  return sum;
}


