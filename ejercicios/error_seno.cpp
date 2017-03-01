#include <iostream>
#include <cmath>
#include <cstdio>

double serie (double x );

int main(void)

{ 
   

  double z=1; 
  
  

   for (int j=1;j<=1000;j++)
    {
      z=j*0.1;
      std::printf("%f %20.16e \n", z ,fabs((serie(z)-std::sin(z))/std::sin(z)));
    }

  /*  double suma =0, eps = pow(10,-7), x=2M_PI, it=x ;
  int j=1;
  do 
    {suma+=it;
      it*=-x*x/(2*j+1)/(2*j);
      std::printf("%i %20.16e \n", j,fabs(suma-std::sin(x))/std::sin(x) );
      j++;
    }
  while (fabs(it/suma)>eps );*/
  
return 0;
}
double serie (double x)
{
  double suma =0, it=x, eps = pow(10,-7),j=1;
  

 do 
   {suma+=it;
     it*=-x*x/(2*j+1)/(2*j);
      j++;
  }
 while (fabs(it/suma)>eps );

  return suma;

}
