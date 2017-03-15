#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, char** argv)
{
  mat A = randu<mat>(5,5);
  mat B = A.t()*A;
  
  vec eigval;
  mat eigvec;

  eig_sym(eigval, eigvec, B);

  cout << B << endl;
  cout << eigval << endl;
  cout << eigvec(0,1) << endl;

  
  return 0;
}
