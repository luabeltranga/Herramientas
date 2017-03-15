// matrices: Son arrays bidimensionales. Tambien se pueden declarar arrays 
// multidimensionales. Maximo numero de indices: depende del compilador,
// normalmente son 32

#include <iostream>
using namespace std;

typedef double REAL;
//typedef float REAL;

// matrix mxn: m rows and n comlumns
const int m = 2, n = 3;

// imprimir la matrix
// importante: pasar el tamanho del indice >= 2
void printMatrix(const int M[][n], const int size1); 


int main(void)
{
  int M1[m][n];
  printMatrix(M1, m);

  // three-dimensional array: type NAME[][][];

  // initialization
  int M2[m][n] = {0}; // all zero
  printMatrix(M2, m);

  int M3[m][n] = {{1, 2, 3}, {4, 5, 6}}; // explicit
  printMatrix(M3, m);

  int M4[m][n] = {{1, 2}, {4, 5, 6}}; // some explicit, some zero
  printMatrix(M4, m);

  int M5[m][n] = {1, 2, 3, 4, 5, 6}; // explicit without braces
  printMatrix(M5, m);

  int M6[m][n] = {1, 2, 3,
		  4, 5, 6}; // explicit without braces
  printMatrix(M6, m);

  int M7[][n] = {1, 2, 3,
		 4, 5, 6}; // explicit without braces
  printMatrix(M7, m);
  
  
  // sizeof
  cout << sizeof(M1) << endl;
  cout << sizeof(M1[0]) << endl;

  // memoria
  // el indice e la derecha es el que varia mas rapido
  // organizacion en la memoria:
  // M1[0][0] M1[0][1] M[0][2]
  // M1[1][0] M1[1][1] M[1][2]


  return 0;
}

void printMatrix(const int M[][n], const int size1)
{
  cout.precision(4);
  for (int i = 0; i < size1; i++) {
    for (int j = 0; j < n; j++) {
      cout.width(14);
      cout << M[i][j] ;//<< "\t" ;
    }    
    cout << endl;
  }
  cout << endl;
  cout << endl;
}
