#include<iostream>

int main(void)
{
  const int N=940;
  double under =1.0,over=1.0;

  for(int i=1;i<=N;i++)
    {
      under /= 2;
      over *=  2;
      std::cout<<i<<"\t"<<under<<"\t"<<over<<std::endl;
    }

 
  return 0;
}
