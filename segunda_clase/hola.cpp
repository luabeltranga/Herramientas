#include<iostream>
#define LOL


int main(void)
{
  #ifdef LOL
  std::cout<<"Hola mundo"<<std::endl;
  std::cerr<<"Error"<<std::endl;
  #endif


  return 10;
}
