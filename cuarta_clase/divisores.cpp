#include <iostream>

int main (void){
  int a=1;
  std::cout<<"Introduzca un numero: ";
  std::cin>>a;

  if (a%3 == 0 ){
  std::cout<<"El numero si es divisible por tres"<<std::endl;
    
  }
  else { 

  std::cout<<"El numero no es divisible por tres"<<std::endl;    

  }


  return 0;
}


