#include <iostream>
#include <cmath>
#include <cstdio>

double serie (double x );

int main(void)

{ 
   

  double z=1; 
  
  

  for (int ii=0;ii<=1000;ii++)
    {
      z=ii*0.2;
      printf ("%.16e %30.16e\n",z,fabs((serie(z)-sin(z))/sin(z)));

    }
 

  return 0;
}
double serie (double x)
{
  double suma =x, it=x, eps = pow(10,-8),j=1;
  

 do 
   {
     it*=-x*x/(2*j+1)/(2*j);
      
      suma+=it;
      j++;
  }
 while (fabs(it/suma)>eps );

  return suma;

}
