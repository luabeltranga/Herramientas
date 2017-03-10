//g++ -I$HOME/local/include/ -L $HOME/local/lib 2.cpp -lgsl -lgslcblas -lm

#include <cstdio>
#include<gsl/gsl_ieee_utils.h>

int main (void){
  double d = 1.0/3.0;
  float  f = 2.0/3.0;

  std::printf("Introduzca un numero de punto flotante tipo float =");
  std::scanf("%f",&f);

  std::printf("Introduzca un numero de punto flotante tipo double =");
  std::scanf("%f",&d);
  
  std::printf ("En representacion ieee en precision float   = ");
  gsl_ieee_printf_float(&f);
  std::printf("\n");


  std::printf ("En representacion ieee en precision double   = ");
  gsl_ieee_printf_double(&d);
  std::printf ("\n");

  return 0;
}
