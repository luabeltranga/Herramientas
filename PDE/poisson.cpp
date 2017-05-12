#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "finite_diff.h"

const double L  = 10 ;
const int NSTEPS = 1000  ;
const int N = 50 ;
double rho(int ix , int iy);
void relax_poisson(std::vector<double> & mat, double (*rho)(int,int));


int main (void){  
  std::vector<double> mat (N*N);
  std::vector<double> mat_tmp ;
  initial_conditions(mat);
  //boundary_conditions(mat);
  start_gnuplot();
  for (int ii = 0 ; ii < NSTEPS; ++ii){
    mat_tmp = mat;
    relax_poisson(mat,rho);
    print_gnuplot(mat);
    if (compare(mat,mat_tmp) == true){
      break;   
    }
  }
  //print(mat);

  
  return 0;
}


double rho(int ix , int iy){
  if(ix == N/2 && iy == N/2){
    return 500.3;
    }
  return 0;
}

void relax_poisson(std::vector<double> & mat, double (*rho)(int,int)){
  int N = std::sqrt(mat.size());
  const double DELTA  = L/(N-1) ;
  for(int ii = 1; ii <= N-2; ++ii){
    for(int jj = 1; jj <= N-2; ++jj){
      //if (ii == 3*N/4 && N/3 <= jj && jj <= 2*N/3) continue;
      //if (ii == N/4 && N/3 <= jj && jj <= 2*N/3) continue;
      mat[ii*N + jj] = (mat[(ii+1)*N + jj] + mat[(ii-1)*N + jj] + mat[ii*N + jj + 1] + mat[ii*N + jj - 1])/4.0 + M_PI*rho(ii,jj)*DELTA*DELTA;
    }
  }
}
