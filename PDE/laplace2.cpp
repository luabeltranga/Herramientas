#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "finite_diff.h"

const int N = 50 ;
const int NSTEPS = 200  ;



int main (void){
  std::vector<double> mat (N*N) ;
  std::vector<double> mat_tmp ;
  initial_conditions(mat);
  boundary_conditions(mat);
  start_gnuplot();
  
  for (int ii = 0 ; ii < NSTEPS; ++ii){
    mat_tmp = mat;
    relax_laplace(mat);
    print_gnuplot(mat);
    if (compare(mat,mat_tmp) == true){
      break;   
    }
  }
  
  
  
  //print(mat);
  
  
  return 0;
}

