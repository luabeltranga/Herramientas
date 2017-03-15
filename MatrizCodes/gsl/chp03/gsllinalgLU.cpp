// LU descomposition
/*
  int gsl_linalg_LU_decomp (gsl_matrix * A, gsl_permutation *p, int *signum)
  
  These functions factorize the square matrix A into the LU 
  decomposition PA = LU. On output the diagonal and upper triangular 
  part of the input matrix A contain the matrix U. The lower triangular
  part of the input matrix (excluding the diagonal) contains L. The 
  diagonal elements of L are unity, and are not stored.    The 
  permutation matrix P is encoded in the permutation p. The j-th column 
  of the matrix P is given by the k-th column of the identity matrix, 
  where k = p_j the j-th element of the permutation vector. The sign of
  the permutation is given by signum. It has the value (-1)^n, where n 
  is the number of interchanges in the permutation.    The algorithm 
  used in the decomposition is Gaussian Elimination with partial 
  pivoting (Golub & Van Loan, Matrix Computations, Algorithm 3.4.1). 
  
  int gsl_linalg_LU_solve (const gsl_matrix * LU, const gsl_permutation * p, const gsl_vector * b, gsl_vector * x)
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
  for (i = 0; i < m*n; i++) {
    a[i] = i*(i+1);
    //a[i] = 0;
  }
  //a[0] = a[5] = a[10] = a[15] = 1; // identidad
  
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
  // crear la matriz permutacion
  gsl_permutation *p = gsl_permutation_alloc(m);
  
  // descomponer en LU=PA
  int s;
  gsl_linalg_LU_decomp(&M1view.matrix, p, &s);
  // resolver el sistema usando la descomposici\'on
  gsl_linalg_LU_solve(&M1view.matrix, p, &v1view.vector, x);
  
  // imprimir
  printf ("x = \n");
  gsl_vector_fprintf (stdout, x, "%g");
  
  // liberar memoria
  gsl_permutation_free (p);
  gsl_vector_free (x);
  return 0;
}
