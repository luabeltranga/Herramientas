#include <iostream>
#include <cmath>

double serie (double x)
{
  double suma =x;
  double it=x;
  

  for(double j=1;j<=100;j++)
    {
      it*=-x*x/(2*j+1)/(2*j);
      
      suma+=it;

    }


  return suma;

}







int main(void)

{
  double z=1;
  
  std::cout.precision(16);

  for (int ii=1;ii<=1000;ii++)
    {
      z=ii*0.2;
      std::cout<<z<<"\t"<<fabs((sin(z)-serie(z))/sin(z))<<std::scientific<<std::endl;

    }
  
  
  std::cout<<serie(M_PI)<<std::scientific<<std::endl;
  std::cout<<serie(0)<<std::scientific<<std::endl;

  return 0;
}
