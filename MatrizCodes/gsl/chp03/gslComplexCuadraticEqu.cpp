// Ecuacion cuadratica con complejos de la gsl
// compilar como:
//  g++ gslComplexCuadraticEqu.cpp -lgsl

#include <iostream>
using namespace std;

#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

typedef double REAL;
//typedef float REAL;

int main(void)
{
  gsl_complex z1, z2, zroot;
  
  double a, b, c;
  
  cout << "Por favor escriba los coeficientes de la ecuaci\'on cuadr\'atica:"; 
  cout  << endl;
  cout << "a = " ;
  cin >> a;
  cout  << endl;
  cout << "b = " ;
  cin >> b;
  cout  << endl;
  cout << "c = " ;
  cin >> c;
  
  zroot = gsl_complex_sqrt_real(b*b - 4*a*c);
  GSL_SET_COMPLEX(&z1, 0, 0);
  z1 = gsl_complex_add_real(z1, -b);
  z1 = gsl_complex_add(z1, zroot);
  z1 = gsl_complex_div_real(z1, 2*a);

  GSL_SET_COMPLEX(&z2, 0, 0);
  z2 = gsl_complex_add_real(z2, -b);
  z2 = gsl_complex_sub(z2, zroot);
  z2 = gsl_complex_div_real(z2, 2*a);

  cout << "Las raices son:" << endl;
  cout << "( " << z1.dat[0] << ", " << z1.dat[1] << ")" << endl;
  cout << "( " << z2.dat[0] << ", " << z2.dat[1] << ")" << endl;
  
  return 0;
}
