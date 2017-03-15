#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_linalg.h>

void init(double Adata[], double bdata[], const int n);
void solve(double Adata[], double bdata[], const int n);

int
main (void)
{
  srand48(0);

  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size


  /*
  double a_data[] = { 0.18, 0.60, 0.57, 0.96,
                      0.41, 0.24, 0.99, 0.58,
                      0.14, 0.30, 0.97, 0.66,
                      0.51, 0.13, 0.19, 0.85 };
  double b_data[] = { 1.0, 2.0, 3.0, 4.0 };
  */
  double *a_data, *b_data;
  a_data = malloc(N*N*sizeof(double));
  b_data = malloc(N*sizeof(double));

  int step;
  for (step = 0; step < N; ++step) {
    init(a_data, b_data, M);
    solve(a_data, b_data, M);
  }

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

void solve(double Adata[], double bdata[], const int n)
{
  gsl_matrix_view m 
    = gsl_matrix_view_array (Adata, n, n);

  gsl_vector_view b
    = gsl_vector_view_array (bdata, n);

  gsl_vector *x = gsl_vector_alloc (n);
  
  int s;

  gsl_permutation * p = gsl_permutation_alloc (n);

  gsl_linalg_LU_decomp (&m.matrix, p, &s);

  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);

  //printf ("x = \n");
  //gsl_vector_fprintf (stdout, x, "%g");

  gsl_permutation_free (p);
  gsl_vector_free (x);
}
