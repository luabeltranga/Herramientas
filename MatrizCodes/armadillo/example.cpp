#include <iostream>
#include <armadillo>
#include <cstdlib>

using namespace std;
using namespace arma;

int main(int argc, char** argv)
{
  srand(10);
  const int N = atoi(argv[1]);
  const int M = atoi(argv[2]);
  
  mat A, B, C;

  for (int ii = 0; ii < N; ++ii) {
    // initialization 
    A = randu<mat>(M,M);
    B = randu<mat>(M,M);
    
    // main processing
    C = A*B.t();
  }

  //std::cout << C << std::endl;

  return 0;
}
