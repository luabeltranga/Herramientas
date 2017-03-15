#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

typedef double REAL;
//typedef float REAL;

int main(void)
{
  complex<double> z1, z2, zroot;
  
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
  
  zroot = sqrt(complex<double>(b*b - 4*a*c));
  z1 = (-b + zroot)/(2*a);
  z2 = (-b - zroot)/(2*a);
  
  cout << z1 << endl;
  cout << z2 << endl;
  
  return 0;
}
