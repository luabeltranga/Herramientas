// Cholesky: square matrix
/*
  int gsl_linalg_cholesky_decomp (gsl_matrix * A)
int gsl_linalg_cholesky_solve (const gsl_matrix * cholesky, const gsl_vector * b, gsl_vector * x)
*/


#include <iostream>
using namespace std;

#include <gsl/gsl_linalg.h>

typedef double REAL;
//typedef float REAL;

#define m 4
#define n 4

int main(void)
{
  int i;
  
  // define the system
  double a[m*n] = {0}; // for the matrix
  for (i = 0; i < m*n; i += 2) {
    a[i] = 0;
  }
  a[0] = a[5] = a[10] = a[15] = 10; //  identidad
  
  double b[m] = {0};
  for (i = 0; i < m; i++) {
    b[i] = i;
  }
  
  // crear la matriz view
  gsl_matrix_view M1view = gsl_matrix_view_array(a, m, n);
  // crear el vector de datos
  gsl_vector_view v1view = gsl_vector_view_array(b, m);
  // crear el vector para guardar las soluciones
  gsl_vector *x = gsl_vector_alloc(m);
  
  // resolver  
  gsl_linalg_cholesky_decomp(&M1view.matrix);
  gsl_linalg_cholesky_solve(&M1view.matrix, &v1view.vector, x);
  
  // imprimir
  printf ("x = \n");
  gsl_vector_fprintf (stdout, x, "%g");
    
  // liberar memoria
  gsl_vector_free (x);
  return 0;
}
