#include <iostream>
#include <cmath>

double armonic(int j);

int main(void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);

  for (int jj=1;jj<=5000;jj++){
    if(jj%100==0){
      std::cout<<jj<<" "<<armonic(jj)-std::log(jj)<<" "<<armonic(jj)-std::log(jj+0.5)<<std::endl;
      }
  }
  
  return 0;
}



double armonic( int k){
  double x = k, s=0;

  for(int ii = k;ii>0;ii--){
    s+=1.0/x;
    x--;
  }
  
  
  return s;
}
