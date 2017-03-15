// compile as g++ gslMatrixBasic.cpp  -lgsl
#include <iostream>
using namespace std;

#include <gsl/gsl_matrix.h>

typedef double REAL;
//typedef float REAL;

int main(void)
{
  int m = 4, n = 3;
  
  // asignar memoria para la matriz y crearla
  gsl_matrix *M = gsl_matrix_calloc(m, n);

  // accesing elements
  gsl_matrix_get(M, 3, 2); // M[3][2]

  // setting elements
  gsl_matrix_set(M, 2, 1, -9999.98776);

  // printing the matrix
  gsl_matrix_fprintf(stdout, M, "%8.4f ");

  // las view permiten extraer una columna, una fila, la diagonal,
  // la upper diagonal, etc

  // liberar la memoria
  gsl_matrix_free(M);

  return 0;
}
