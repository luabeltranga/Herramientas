// introducci\'on a la GSL
// para compilar : 
// g++ introGSL.cpp -lgsl -o introGSL.exe

#include <iostream>
#include <cstdio> // #include <stdio.h>
#include <gsl/gsl_sf_bessel.h>
using namespace std;

int
main (void)
{
  double x = 5.0;
  double y = gsl_sf_bessel_J0 (x);
  printf ("# J0(%g) = %.18e\n", x, y);
  x = 6.0;
  y = gsl_sf_bessel_J0 (x);
  printf ("# J0(%g) = %.18e\n", x, y);
  x = 7.0;
  y = gsl_sf_bessel_J0 (x);
  printf ("# J0(%g) = %.18e\n", x, y);


  // bessel_J0 entre -10 y 10 en saltos de a 0.1
  int steps = (10 - (-10))/0.1;
  for (int i = 0; i < steps; i++) {
    x = -10.0 + 0.1*i;
    cout << x << "\t" << gsl_sf_bessel_J0 (x) << endl; 
  }


  return 0;
}
