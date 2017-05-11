#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
const int N = 50 ;
const int NSTEPS = 1000  ;
const double L  = 10 ;
const double DELTA  = L/(N-1) ;

void initial_conditions (std::vector<double> & mat);
void boundary_conditions (std::vector<double> & mat);
void relax (std::vector<double> & mat);
void print (const std::vector<double> & mat);
void print_gnuplot (const std::vector<double> & mat);
void start_gnuplot (void);
bool compare (const std::vector<double> & mat,const std::vector<double> & mat_tmp);
double rho(int ix , int iy);
int main (void){
  std::vector<double> mat (N*N);
  std::vector<double> mat_tmp ;
  initial_conditions(mat);
  boundary_conditions(mat);
  start_gnuplot();
  for (int ii = 0 ; ii < NSTEPS; ++ii){
    mat_tmp = mat;
    relax(mat);
    print_gnuplot(mat);
    if (compare(mat,mat_tmp) == true){
      break;   
    }
  }
  //print(mat);

  
  return 0;
}

void initial_conditions (std::vector<double> & mat){
  for (int ii = 0 ; ii < N ; ++ii){
    for (int jj = 0 ; jj < N ; ++jj){
      mat[ii*N +jj]=0.0;
    }
  }
}
void boundary_conditions(std::vector<double> & mat)
{
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
    mat[ii*N + jj] = -100.0;
  }
  
  ii = N/4;
  for(jj = N/3; jj <= 2*N/3; ++jj){
    mat[ii*N + jj] = -100.0;
  }
  
  
}

double rho(int ix , int iy){
  if(ix == N/2 && iy == N/2){
    return 500.3;
    }
  return 0;
}

void relax(std::vector<double> & mat)
{
  for(int ii = 1; ii <= N-2; ++ii){
    for(int jj = 1; jj <= N-2; ++jj){
      if (ii == 3*N/4 && N/3 <= jj && jj <= 2*N/3) continue;
      if (ii == N/4 && N/3 <= jj && jj <= 2*N/3) continue;
      mat[ii*N + jj] = (mat[(ii+1)*N + jj] + mat[(ii-1)*N + jj] + mat[ii*N + jj + 1] + mat[ii*N + jj - 1])/4.0 + M_PI*rho(ii,jj)*DELTA*DELTA;
    }
  }
}


void print (const std::vector<double> & mat){
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
  std::cout << "splot '-' w pm3d t 'laplace'" << std::endl; 
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
  std::cout << "set terminal gif animate  " << std::endl;
  std::cout << "set out 'poisson.gif' " << std::endl;
  std::cout << "unset key " << std::endl; 
}

bool compare (const std::vector<double> & mat,const std::vector<double> & mat_tmp){
  for (int ii = 0 ; ii < N ; ii++){
    for (int jj = 0 ; jj < N ; jj++){
      if (std::fabs(mat[ii*N+jj]-mat_tmp[ii*N+jj])/mat_tmp[ii*N+jj] > 0.01) return false;
    }
  }
  return true;
}
