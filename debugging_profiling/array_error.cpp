#include<iostream>

int main(void){
  double array2[2000]{0};
  double array[11]{0,1,2,3,4,5,6,7,8,9,10};
 
  for(auto &x : array2) x=10;

  std::cout<<array2[11]<<std::endl;

  for (int jj : array){
    std::cout<<array[jj]<<std::endl;  }
    std::cout<<array[200]<<std::endl;  
  return 0;
}
