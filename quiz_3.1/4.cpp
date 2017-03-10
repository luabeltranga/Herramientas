#include <iostream>
#include <cmath>

double f(double x);
double g(double x);

int main(void){
  double x;
  for(x=-1.0e-3;x<=1.0e-3; x+=1.0e-6){
    std::cout<<x<<" "<<f(x)<<" "<<g(x)<<std::endl;
  }
  
  return 0;
}



double f (double x){
  return std::sin(x)-1+std::cos(x);

}

double g(double x){
  double z=x/2;
  return std::sin(x)*(1-2*std::sin(z) );
}
