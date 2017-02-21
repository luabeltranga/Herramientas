#include <iostream>
#include <cmath>
#include <cstdio>

double root1(int a ,int b, double c,int n ), root2(int a ,int b, double c,int n); 

int main(void){

    double z = 0.1;
    
  
  for(int i = 1; i<= 20; i++){
    printf("%d %30.100e %30.100e \n",i,fabs(root1(1,1,z,1)-root2(1,1,z,1)),fabs(root1(1,1,z,2)-root2(1,1,z,2)));
    z/=10.0;
  }
  return 0;
}


double root1(int a ,int b, double c, int n) {

  double x=0;
  
  if(n==1){
    x = (-b+std::sqrt(b*b-4*a*c))/2*a;
  }
  else if(n==2){
    x = (-b-std::sqrt(b*b-4*a*c))/2*a;  
  }

  return x;

}


double root2 (int a, int b,double c, int n){
  double x, y;
  x = (-b+std::sqrt(b*b-4*a*c))/2*a;

  if(n == 1){
  return x;
  }
  else if(n == 2){
    y=c/x;
    return y;

  }
}
