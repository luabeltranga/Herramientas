#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

const int N = 6;
int main (void){
  std::mt19937_64 g(2);
  std::uniform_int_distribution<int> h(1,6);
  int * A = new int [N] ();
  int * B = new int [6] ();
  std::ofstream babas;
  for (int ii = 0; ii < N;ii++){
    A[ii]=h(g);
  }

  for(int jj = 0; jj<N ; jj++){
    if (A[jj] == 1){
      B[0] += 1;
    }
    else if (A[jj] == 2){
      B[1] += 1;
    }
    else if (A[jj] == 3){
      B[2] += 1;
    }
    else if (A[jj] == 4){
      B[3] += 1;
    }
    else if (A[jj] == 5){
      B[4] += 1;
    }
    else if (A[jj] == 6){
      B[5] += 1;
    }
  }
  babas.open("test.txt");
  
  for (int kk = 0; kk< 6 ; kk++){
    babas << kk+1 << " " << B[kk] << "\n";
  }

  babas.close();
  delete [] A ;
  A = nullptr;
  delete [] B ;
  B = nullptr;
  return 0;
}
