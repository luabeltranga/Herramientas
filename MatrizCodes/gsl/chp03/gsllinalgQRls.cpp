// QR decomposition + least squares
/*
int gsl_linalg_QR_decomp (gsl_matrix * A, gsl_vector * tau)
int gsl_linalg_QR_lssolve (const gsl_matrix * QR, const gsl_vector * tau, const gsl_vector * b, gsl_vector * x, gsl_vector * residual)
*/


#include <iostream>
using namespace std;

#include <gsl/gsl_linalg.h>

typedef double REAL;
//typedef float REAL;

#define m 4
#define n 3

int main(void)
{
  int i;
  
  // define the system
  double a[m*n] = {0}; // for the matrix
  for (i = 0; i < m*n; i++) {
    a[i] = i*(i+1);
    //a[i] = 0;
  }
  //a[0] = a[4] = a[8] = a[12] = 1; // casi identidad
  
  double b[m] = {0};
  for (i = 0; i < m; i++) {
    b[i] = i;
  }
  
  // crear la matriz view
  gsl_matrix_view M1view = gsl_matrix_view_array(a, m, n);
  // crear el vector de datos
  gsl_vector_view v1view = gsl_vector_view_array(b, m);
  // crear el vector para guardar las soluciones
  gsl_vector *x = gsl_vector_alloc(n);
  gsl_vector *tau = gsl_vector_alloc(n);
  gsl_vector *res = gsl_vector_alloc(m);
  
  // resolver
  gsl_linalg_QR_decomp(&M1view.matrix, tau);
  gsl_linalg_QR_lssolve(&M1view.matrix, tau, &v1view.vector, x,  res);
  
  // imprimir
  printf ("x = \n");
  gsl_vector_fprintf (stdout, x, "%g");
  printf ("residuals = \n");
  gsl_vector_fprintf (stdout, res, "%g");
  
  // liberar memoria
  gsl_vector_free (x);
  return 0;
}
