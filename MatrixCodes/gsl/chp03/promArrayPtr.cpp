// ejemplo de apuntadores y arreglos
// calcular el promedio por varias formas

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL

REAL promX1(const REAL *xarray, const int n);
REAL promX2(REAL *xarray, const int n);
REAL promX3(REAL *xarray, const int n);
REAL promX4(REAL *xarray, const int n);


int main(void)
{
  const int size = 10;
  REAL vec[size] = {1.0, 1.2, 1.2, 1.1, 0.9, 0.9, 0.5, 0.8, 1.5, 1.2};
  cout << promX1(vec, size) << endl;
  cout << promX2(vec, size) << endl;
  cout << promX3(vec, size) << endl;
  cout << promX4(vec, size) << endl;

  cout << promX1(vec, 2) << endl; // promedio de x[0] x[1]
  cout << promX1(vec+2, 3) << endl; // promedio de x[2] x[3] x[4]
  cout << promX1(vec+9, 1) << endl; // promedio de x[9] 
  
  return 0;
}

REAL promX1(const REAL *xarray, const int n)
{
  int i; 
  REAL result = 0;
  
  for (i = 0; i < n; i++)
    result += xarray[i];

  return result/n;
}

REAL promX2(REAL *xarray, const int n)
{
  int i; 
  REAL result = 0;
  REAL *p, *pfin; // punteros al incio y al fin del array

  pfin = xarray + n; // aritmetica de apuntadores
  for (p = xarray; p < pfin; p++) // aritmetica de apuntadores
    result += *p; // traer el valor al que apunta p

  return result/n;
}

REAL promX3(REAL *xarray, const int n)
{
  int i; 
  REAL result = 0;
  REAL *p, *pfin; // punteros al incio y al fin del array

  p = xarray; 
  pfin = xarray + n; // aritmetica de apuntadores
  while (p < pfin) {
    result += *p; // traer el valor al que apunta p
    p++;// aritmetica de apuntadores
  }

  return result/n;
}

REAL promX4(REAL *xarray, const int n)
{
  int i; 
  REAL result = 0;
  REAL *p, *pfin; // punteros al incio y al fin del array
  
  p = xarray; 
  pfin = xarray + n; // aritmetica de apuntadores
  while (p < pfin) 
    result += *p++; // traer el valor al que apunta p, operador post ++
  
  return result/n;
}
