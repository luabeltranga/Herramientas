//  g++ -lgsl -lgslcblas blasV2.c
#include <stdio.h>
#include <gsl/gsl_blas.h>

int
main (void)
{
  // arreglos que repsentan las matrices
  double a[] = { 0.11, 0.12, 0.13,
                 0.21, 0.22, 0.23 }; 

  double b[] = { 1011, 1012,
                 1021, 1022,
                 1031, 1032 };

  double c[] = { 0.00, 0.00,
                 0.00, 0.00 };

  double d[] = { 0.00, 0.00, 0.00, 
                 0.00, 0.00, 0.00, 
                 0.00, 0.00, 0.00 };

  // las vistas permiten "ver" los arreglos como matrices
  // pero los resultados se guardan en los arreglos
  gsl_matrix_view A = gsl_matrix_view_array(a, 2, 3);
  gsl_matrix_view B = gsl_matrix_view_array(b, 3, 2);
  gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);
  gsl_matrix_view D = gsl_matrix_view_array(d, 3, 3);
  
  /* Compute C = alpha*A B + beta*C */
  /* alpha = 1.0 beta = 0.0 */
  gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
                  1.0, &A.matrix, &B.matrix,
                  0.0, &C.matrix);
  
  printf ("[ %g, %g\n", c[0], c[1]);
  printf ("  %g, %g ]\n", c[2], c[3]);
  

  /* Compute CT = alpha*BT AT + beta*CT */
  /* alpha = 1.0 beta = 0.0 */
  gsl_blas_dgemm (CblasTrans, CblasTrans,
                  1.0, &B.matrix, &A.matrix,
                  0.0, &C.matrix);
  
  printf ("[ %g, %g\n", c[0], c[1]);
  printf ("  %g, %g ]\n", c[2], c[3]);
  
  /* Compute D = A^T B^T */
  gsl_blas_dgemm (CblasTrans, CblasTrans,
                  1.0, &A.matrix, &B.matrix,
                  0.0, &D.matrix);
  
  printf ("[ %g, %g, %g  \n", d[0], d[1], d[2]);
  printf ("  %g, %g, %g  \n", d[3], d[4], d[5]);
  printf ("  %g, %g, %g ]\n", d[6], d[7], d[8]);

  return 0;  
}
