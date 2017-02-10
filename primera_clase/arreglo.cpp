#include <iostream>

int main(void)

{
  int data[10]={1,2,3,4,5,6,7,8,9,10};
  int sum=0;
  for(auto x:data){
    sum+=x;


  }

  std::cout<<sum<<std::endl;


  return 0;
}
