#include <iostream>
#include <cmath>
#include <cstdio>

int main (void){
  
  double x=2;
  
  for(int i=1; i<=10; i++){

    x=(1-x);

    printf("%d %10.16e \n", i,x);


  }


  return 0;
}
