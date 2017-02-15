#include <iostream>

int main(void){
  int a = 10;
  std::cout<<&a<<std::endl;

  {
    int a=6;
    std::cout<<a<<std::endl;  //scope: el alcance de una variable 

  }

  std::cout<<a<<std::endl;
  return 0;
}



/* el operdor & muestra la posicion de la variable en la memoria */ 
