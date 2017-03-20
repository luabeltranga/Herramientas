#include <iostream>

typedef double babas;

int main (void){

  babas x = 0.2;
  babas * test;

  test= &x;

  std::cout<<test<<std::endl;

  test++;
  std::cout<<test<<std::endl;
  return 0;
}
