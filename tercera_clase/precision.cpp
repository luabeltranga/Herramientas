#include <iostream>
#include <cstdio>
int main(void)
{

 float eps=1.0 , one;



 for (int n = 0; n <= 150; ++n)
    {
      eps /= 2.0;
      one= 1.0 + eps;
      printf ("%u %20.8e %20.8e \n",n,eps,one );
    }



  return 0;
}



/* para medir la precision de una maquina para las variables float y double */
