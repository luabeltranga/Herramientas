#include <iostream>

int main(void)
{

 float eps=1.0 , one;



 for (int n = 0; n < 10; ++n)
    {
      eps /= 2.0;
      one= 1.0 + eps;
      std::cout<<n<<"\t"<<one<<"\t"<<eps<<std::scientific<<std::endl;
    }



  return 0;
}



/* para medir la precision de una maquina para las variables float y double */
