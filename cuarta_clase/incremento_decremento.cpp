#include <iostream>

int main(void){
  int y,x=7;
  y=++x-3;  // primero incrementa y luego asigna
  std::cout<<y<<std::endl;
  x=7;
  y=x++ +3; //primero asigna y luego incrementa
  std::cout<<y<<std::endl;


  return 0;
}
