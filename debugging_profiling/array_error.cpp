#include<iostream>

int main(void){
  double array[10]{1,2,3,4,5,6,7,8,9,10};
  double array2[2000]{0};

 
  for(auto &x : array2) x=10;
  std::cout<<array[0]<<std::endl;
  std::cout<<array[2000]<<std::endl;

  return 0;
}
