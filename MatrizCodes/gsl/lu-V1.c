#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>

void init(double Adata[], double bdata[], const int n);

int
main (void)
{
  srand48(0);
  /*
  double a_data[] = { 0.18, 0.60, 0.57, 0.96,
                      0.41, 0.24, 0.99, 0.58,
                      0.14, 0.30, 0.97, 0.66,
                      0.51, 0.13, 0.19, 0.85 };
  double b_data[] = { 1.0, 2.0, 3.0, 4.0 };
  */
  double *a_data, *b_data;
  a_data = malloc(4*4*sizeof(double));
  b_data = malloc(4*sizeof(double));
  
  init(a_data, b_data, 4);

  gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, 4, 4);

  gsl_vector_view b
    = gsl_vector_view_array (b_data, 4);

  gsl_vector *x = gsl_vector_alloc (4);
  
  int s;

  gsl_permutation * p = gsl_permutation_alloc (4);

  gsl_linalg_LU_decomp (&m.matrix, p, &s);

  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);

  printf ("x = \n");
  gsl_vector_fprintf (stdout, x, "%g");

  gsl_permutation_free (p);
  gsl_vector_free (x);
  free(a_data);
  free(b_data);

  return 0;
}


void init(double Adata[], double bdata[], const int n)
{
  int ii, jj;
  for (ii = 0; ii < n; ++ii) {
    bdata[ii] = drand48();      
    for (jj = 0; jj < n; ++jj) {
      Adata[ii*n + jj] = drand48();      
    }
  }
}
