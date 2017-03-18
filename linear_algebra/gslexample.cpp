#include <cstdio>
#include <gsl/gsl_linalg.h>

const int n = 4;
const int nn = 4;
int
main (void)
{
  double a_data[] = { 1.0, 0, 0, 0,
                      0, 1.0, 0, 0,
                      0, 0, 1.0, 0,
                      0, 0, 0, 1.0};
  
  double b_data[] = { 1.0, 2.0 , 3.0 , 4.0};
  
  gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, n, nn);
  
  gsl_vector_view b
    = gsl_vector_view_array (b_data, nn);
  
  gsl_vector *x = gsl_vector_alloc (nn);
  
  int s;
  
  gsl_permutation * p = gsl_permutation_alloc (n);
  
  gsl_linalg_LU_decomp (&m.matrix, p, &s);
  
  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);
  
  printf ("x = \n");
  gsl_vector_fprintf (stdout, x, "%g");
  
  gsl_permutation_free (p);
  gsl_vector_free (x);
  return 0;
}
