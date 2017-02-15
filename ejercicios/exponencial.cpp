#include <iostream>
#include <cmath>
#include <cstdio>

double suma (double x);

int main(){
  double z=1;
  for (double i=-50;i<=50;i++){
    z=i*0.2;

    printf ("%.3e %30.50e \n",z,suma(z));
    

  }

  
  return 0;
}

double suma ( double x )

{
  double iterator=1, suma=1, eps=pow(10,-8),j=1;
  
  do{
    iterator*=-x/j;
    suma+=iterator;
    j++;
      }
  while (iterator/suma>eps );
  return suma;
}


