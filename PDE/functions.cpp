#include <iostream>
#include <functional>
#include <vector>
#include <fstream>
#include <cmath>
#include "finite_diff.h"

const double L  = 10 ;


void test(std::vector<double> & mat){
  std::cout << mat.size() << std::endl;
}

void initial_conditions (std::vector<double> & mat){
  int N = std::sqrt(mat.size());
  for (int ii = 0 ; ii < N ; ++ii){
    for (int jj = 0 ; jj < N ; ++jj){
      mat[ii*N +jj]=0.0;
    }
  }
}
void boundary_conditions(std::vector<double> & mat)
{
  int N = std::sqrt(mat.size());
  int ii, jj;
  
  ii = 0;
  for(jj = 0; jj < N; ++jj){
    mat[ii*N + jj] = 0.0;
  }
  ii = N-1;
  for(jj = 0; jj < N; ++jj){
    mat[ii*N + jj] = 0.0;
  }
  jj = 0;
  for(ii = 1; ii < N; ++ii){
    mat[ii*N + jj] = 0.0;
  }
  jj = N-1;
  for(ii = 1; ii < N; ++ii){
    mat[ii*N + jj] = 0.0;
  }
  
  
  ii = 3*N/4;
  for(jj = N/3; jj <= 2*N/3; ++jj){
    mat[ii*N + jj] = 200.0;
  }
  
  ii = N/4;
  for(jj = N/3; jj <= 2*N/3; ++jj){
    mat[ii*N + jj] = -200.0;
  }
  
  
}

void relax_laplace(std::vector<double> & mat)
{
  int N = std::sqrt(mat.size());
  for(int ii = 1; ii <= N-2; ++ii){
    for(int jj = 1; jj <= N-2; ++jj){
      if (ii == 3*N/4 && N/3 <= jj && jj <= 2*N/3) continue;
      if (ii == N/4 && N/3 <= jj && jj <= 2*N/3) continue;
      mat[ii*N + jj] = (mat[(ii+1)*N + jj] + mat[(ii-1)*N + jj] + mat[ii*N + jj + 1] + mat[ii*N + jj - 1])/4.0;
    }
  }
}


void print (const std::vector<double> & mat){
  int N = std::sqrt(mat.size());
  const double DELTA  = L/(N-1) ;
  double x = 0.0;
  double y = 0.0;
  std::ofstream laplace ;
  laplace.precision(16);
  laplace.setf(std::ios::scientific);
  laplace.open("Laplace2.gp");
  laplace << "set pm3d" << "\n";
  laplace << "splot 'Laplace2.dat' w l" << "\n";
  laplace << "unset key" << "\n";
  laplace << "set xlabel \"x\" " <<" " << "\n";
  laplace << "set ylabel \"y\" " << " " << "\n";
  laplace << "pause -1" << "\n";
  laplace.close();
  laplace.open("Laplace2.dat");
  for (int ii = 0 ; ii < N ; ++ii){
    x = ii*DELTA; 
    for (int jj = 0 ; jj < N ; ++jj){
      y = jj*DELTA;
      laplace << x << "  " << y << " " << mat[ii*N +jj] << "\n";
    }
    laplace << "\n";
  }
  laplace.close();
}

void print_gnuplot (const std::vector<double> & mat){
  int N = std::sqrt(mat.size());
  const double DELTA  = L/(N-1) ;
  std::cout << "splot '-'  t 'laplace' w pm3d" << std::endl; 
  double x = 0.0;
  double y = 0.0;
  for (int ii = 0 ; ii < N ; ++ii){
    x = ii*DELTA; 
    for (int jj = 0 ; jj < N ; ++jj){
      y = jj*DELTA;
      std::cout << x << "  " << y << " " << mat[ii*N +jj] << std::endl;
    }
    std::cout << std::endl;
  }
  std::cout << "e" << std::endl;
  
}

void start_gnuplot (void){
  std::cout << "set contour " << std::endl;
  std::cout << "set cntrparam levels 20 " << std::endl;
  std::cout << "set size ratio -1 " << std::endl;
  std::cout << "set terminal gif animate  " << std::endl;
  std::cout << "set out 'test.gif' " << std::endl;
  std::cout << "unset key " << std::endl;
  
  
}


bool compare (const std::vector<double> & mat,const std::vector<double> & mat_tmp){
   int N = std::sqrt(mat.size());
  for (int ii = 0 ; ii < N ; ii++){
    for (int jj = 0 ; jj < N ; jj++){
      if (std::fabs(mat[ii*N+jj]-mat_tmp[ii*N+jj])/mat_tmp[ii*N+jj] > 0.01) return false;
    }
  }
  return true;
}



