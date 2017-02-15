#include <iostream>


int main (void){
  int a=2 , b=7, c;
  
  c= (a>b) ? a : b;

  std::cout<<c<<std::endl;


  return 0;
}
/* operador ? incluye una expresion que puede ser verdadera o falsa
   las opciones se escribe "si es verdadero : si es falso"  */ 
