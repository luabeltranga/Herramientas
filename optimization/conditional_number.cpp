#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv)
  
{
  const int N=std::atoi(argv[1]);
  
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);

  
  Eigen::MatrixXd M=Eigen::MatrixXd::Random (N, N);
 
  double norm = M.norm();
  double norminverse = M.inverse().norm();
  
  std::cout <<norm*norminverse<< std::endl;
 
 
 
 return 0;
 
}

