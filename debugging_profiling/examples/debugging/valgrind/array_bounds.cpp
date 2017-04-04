#include <iostream>

void print_array(const double data[], const int & size);

int main(void)
{
  const int NX = 2, NY = 3, NZ = 4;
  double *x=nullptr;
  double y[NY]={10,9,8};
  double z[NZ]={10,5,6,3};
  x = new double [NX];
  int ii=1, jj=20, kk=50;
  //print_array(x, NX); 
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;
  
  for (ii = 0; ii < NX; ii++) {
    x[ii] = ii; 
  }
  print_array(x, NX); 
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;
  
  for (jj = 0; jj < NY; ++jj) {
    //x[jj] = ii; 
    y[jj] = jj; 
  }
  print_array(x, NX); 
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;
  
  for (kk = 0; kk < NZ; ++kk) {
    //x[kk] = ii; 
    //y[kk] = jj; 
    z[kk] = ii; 
  }
  print_array(x, NX); 
  print_array(y, NY); 
  print_array(z, NZ);
  std::cout << std::endl;
  delete [] x;
  
  
  return EXIT_SUCCESS;
}

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ii++) {
    std::cout << data[ii] << "  " ;
  }
}
