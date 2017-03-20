//  g++ -lgsl -lgslcblas blas.c
#include <stdio.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  //double a[] = { 0.11, 0.12, 0.13,
  //               0.21, 0.22, 0.23 };
  gsl_matrix *a = gsl_matrix_calloc(3,3);
  gsl_matrix_set(a,0,0,1); gsl_matrix_set(a,0,1,0); gsl_matrix_set(a,0,2,0); 
  gsl_matrix_set(a,1,0,0); gsl_matrix_set(a,1,1,1); gsl_matrix_set(a,1,2,0);
  gsl_matrix_set(a,2,0,0); gsl_matrix_set(a,2,1,0); gsl_matrix_set(a,2,2,1); 

  //double b[] = { 1011, 1012,
  //               1021, 1022,
  //               1031, 1032 };
  gsl_matrix *b = gsl_matrix_calloc(3,3);
  gsl_matrix_set(b,0,0,1); gsl_matrix_set(b,0,1,0); gsl_matrix_set(b,0,2,0); 
  gsl_matrix_set(b,1,0,0); gsl_matrix_set(b,1,1,1); gsl_matrix_set(b,1,2,0);
  gsl_matrix_set(b,2,0,0); gsl_matrix_set(b,2,1,0); gsl_matrix_set(b,2,2,1);  

  //double c[] = { 0.00, 0.00,
  //               0.00, 0.00 };
  gsl_matrix *c = gsl_matrix_calloc(3,3);
  gsl_matrix_set_zero(c);

  //gsl_matrix_view A = gsl_matrix_view_array(a, 2, 3);
  //gsl_matrix_view B = gsl_matrix_view_array(b, 3, 2);
  //gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);

  /* Compute C = A B */

  //gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
  //                1.0, &A.matrix, &B.matrix,
  //                0.0, &C.matrix);
  gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
                  2.0, a, b,
                  0.0, c);
  
  //printf ("[ %g, %g\n", c[0], c[1]);
  //printf ("  %g, %g ]\n", c[2], c[3]);
  printf ("[ %g, %g %g ]\n", gsl_matrix_get(c,0,0), gsl_matrix_get(c,0,1), gsl_matrix_get(c,0,2));
  printf ("[ %g, %g %g ]\n", gsl_matrix_get(c,1,0), gsl_matrix_get(c,1,1), gsl_matrix_get(c,1,2));
  printf ("[ %g, %g %g ]\n", gsl_matrix_get(c,2,0), gsl_matrix_get(c,2,1), gsl_matrix_get(c,2,2));

  gsl_matrix_free(a);
  gsl_matrix_free(b);
  gsl_matrix_free(c);
  return 0;  
}
