#include <iostream>

int main(void){
  double array[10]{1,2,3,4,5,6,7,8,9,10};  
  double array2[2000] {0};   //si se cambia el orden de la declaracion ocurre un error

  for(auto & val :array2) val=-10;
  std::cout<<array[0]<<std::endl;
  std::cout<<array[2000]<<std::endl;
  
  return 0;
}
