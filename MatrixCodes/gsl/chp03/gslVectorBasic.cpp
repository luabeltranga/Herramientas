// compile as g++ gslVectorBasic.cpp  -lgsl

#include <iostream>
using namespace std;

#include <gsl/gsl_vector.h>

typedef double REAL;
//typedef float REAL;

int main(void)
{
  int size = 12, i;
  double val;
  
  // asignar memoria al vector
  gsl_vector *gslv1 = gsl_vector_alloc(size); 
  //gsl_vector *gslv1 = gsl_vector_calloc(size); // all elements to zero 
 
  // get element i = 8
  i = 8;
  val = gsl_vector_get(gslv1, i);
  cout << val << endl;

  // set element i = 8 to -10.9876
  i = 8;
  val = -10.9876;
  gsl_vector_set(gslv1, i, val);
  cout << gsl_vector_get(gslv1, i) << endl; 

  // retornar un puntero a una direccion especifica
  // double * gsl_vector_ptr (gsl_vector * v, size_t i);

  // set all elements
  // gsl_vector_set_all (gsl_vector * v, double x)
  // void gsl_vector_set_zero (gsl_vector * v)
  // int gsl_vector_set_basis (gsl_vector * v, size_t i)

  // print the vector
  // int gsl_vector_fprintf (FILE * stream, const gsl_vector * v, const char * format)
  cout << endl;
  gsl_vector_fprintf (stdout, gslv1, "%8.4f ");

  // extract some sub vector with a view
  //gsl_vector_view gsl_vector_subvector (gsl_vector * v, size_t offset, size_t n)
  // sub vector from [2] to [5]
  // gsl_vector_view gslv1view = gsl_vector_subvector(gslv1, 2, 5);  

  // liberar memoria del vector
  gsl_vector_free(gslv1);

  return 0;
}
