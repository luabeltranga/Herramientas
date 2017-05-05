#include <iostream>
#include <vector>

const int N = 50 ;
const int NSTEPS = 10000 ;
const double L  = 10 ;
const double DELTA  = L/(N-1) ;

void initial_conditions (std::vector<double> & mat);
void boundary_conditions (std::vector<double> & mat);
void relax (std::vector<double> & mat);
void print (const std::vector<double> & mat);

int main (void){
  std::vector<double> mat (N*N);
  initial_conditions(mat);
  boundary_conditions(mat);
  for (int ii = 0 ; ii < NSTEPS; ++ii){
    relax(mat);
  }
  print(mat);

  
  return 0;
}

void initial_conditions (std::vector<double> & mat){
  for (int ii = 0 ; ii < N ; ++ii){
    for (int jj = 0 ; jj < N ; ++jj){
      mat[ii*N +jj]=0.0;
    }
  }
}
void boundary_conditions (std::vector<double> & mat){
  int ii , jj ;
  ii = 0;
  for (jj = 0 ; jj < N ; ++jj){
    mat[ii*N +jj]=100.0;
  }
  ii= N-1;
  for (jj = 0 ; jj < N ; ++jj){
    mat[ii*N +jj] = -100.0;
  }
}
void relax (std::vector<double> & mat){
  for (int ii = 1 ; ii < N-1 ; ++ii){
    for (int jj = 1 ; jj < N-1 ; ++jj){
      mat[ii*N +jj] = (mat[(ii+1)*N + jj] + mat[(ii-1)*N+jj] + mat[ii*N+jj+1] +mat[ii*N+jj-1])/4.0;
    }
  }
}

void print (const std::vector<double> & mat){
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
}
