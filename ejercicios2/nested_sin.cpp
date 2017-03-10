#include <iostream>
#include <cmath>
const int N_MAX = 3200;

double sum (double x);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  

  for(double jj = -1; jj<1;jj+=0.001){
    std::cout<<jj<<" "<<sum(jj)<<" "<<jj-std::sin(jj)<<std::endl;
  }


  return 0;
}



double sum(double x){
  double it = 1;
  double suma = 0;
  int sign = -1;

  if (N_MAX%2 == 0){
    sign = -1;
  }
  else {
    sign = 1;
  }
  
  for(int ii = N_MAX;ii>=1;ii--){
    if (ii=1){
      it=x*x*x*it/2/3;
    }
    else{
    it=1+it*sign*x*x/(2*ii)/(2*ii+1);
    // suma+=it;
    sign*=-1;
    }
  }
  return it;
}
