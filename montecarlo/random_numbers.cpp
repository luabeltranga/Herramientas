#include <iostream>
#include <random>

int main (void){
  std::mt19937 g1 (134);
  std::uniform_int_distribution<int> h(0,10);
  std::cout<<g1()<<" "<<g1()<<std::endl;
  std::cout<<h(g1)<<" "<<h(g1)<<std::endl;
  
  return 0;
}
