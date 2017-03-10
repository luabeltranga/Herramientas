//g++ -I$HOME/local/include/ -L $HOME/local/lib 2.cpp -lgsl -lgslcblas -lm
#include <cstdio>
#include <cmath>
#include <gsl/gsl_specfunc.h>

double besseldown_at_one(int n);
double besselup_at_one(int n);

int main (void){
  int n = 0;
  for (n = 0;n<=20;n++){
    std::printf("%10d %25.16e %25.16e %25.16e \n", n ,besseldown_at_one(n),besselup_at_one(n), gsl_sf_bessel_Jn(n,1) );



  }
  return 0;
}

double besseldown_at_one(int n){
  if (n<=0){
    return 0.7651976865;
  }
  if (n==1){
    return 0.4400505857;
  }
  else{
    return 2*(n-1)*besselup_at_one(n-1)-besselup_at_one(n-2);
  }
}







double besselup_at_one(int n){
  if(n>=20){
    return 3.873503009e-25;
  }
  else if(n==19){
    return 1.548478441e-23;
  }
  else {
    return 2*(n+1)*besselup_at_one(n+1)-besselup_at_one(n+2);
  }
}
