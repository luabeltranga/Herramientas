// Matrices y arreglos unidimensionales: Como escribir una matriz en un
// arreglo unidimensional? ESTILO GSL
//
// La posicion en memoria del elemento a_{ij} de la matriz A de tamanho mXn
//  est\'a dada  por la f\'ormula:
// index(a_{ij}) = &a[0][0] + i*n + j, con 0 <= i <= m-1, 0 <= j <= n-1 

#include <iostream>
using namespace std;

typedef double REAL;
//typedef float REAL;

const int m = 3;
const int n = 2;

// funcion que retorna el indice unidimensional
int getIndex(const int i, const int j, const int numColumns) {
  return i*numColumns + j;
}

int main(void)
{
  // declaracion de una matriz con dos indices
  int M2d[m][n] = {1, 2, 3, 
		   4, 5, 6};
  
  // declaracion de una matriz con un solo indice
  int M1d[m*n] = {1, 2, 3, 4, 5, 6};
  
  // impresion de resultados para verificar;
  cout << M2d[0][1] << endl;
  cout << M1d[getIndex(0,1,n)] << endl;

  cout << M2d[1][1] << endl;
  cout << M1d[getIndex(1,1,n)] << endl;

  cout << M2d[2][1] << endl;
  cout << *(M2d[0] + getIndex(2, 1, n))  << endl;
  cout << M1d[getIndex(2,1,n)] << endl;

  return 0;
}
