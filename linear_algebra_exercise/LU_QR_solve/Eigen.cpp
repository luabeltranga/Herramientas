#include <iostream>
#include <Eigen/Dense>
#include <cmath>
#include <Eigen/Eigenvalues>
void solver(void);

int main(void){
  
  solver();
  return 0;
}


void solver(void){

  Eigen::MatrixXd a(4,4);
  Eigen::Matrix4d A;
   A << 0.18, 0.60, 0.57, 0.96,
    0.41, 0.24, 0.99, 0.58,
    0.14, 0.30, 0.97, 0.66,
    0.51, 0.13, 0.19, 0.85;

   Eigen::Vector4d b;
  b<< 1.0, 2.0, 3.0, 4.0;

  //Eigen::Vector4d x=A.lu().solve(b);
  //Eigen::Vector4d x=A.Qr():solve(b);
  //Eigen::Vector4d x=A.solve(b);
  
  for (int n = 0; n < 4; ++n){
    
    for (int m = 0; m < 4; ++m){
      
      if (n == m+1) {
	a(n,m) += A(n,m)*A(n,m);
      }
      if (n == m-1){
	a(n,m) += 1;
      }
    }
    
  }
  Eigen::VectorXd y=a.eigenvalues().real();
  std::cout<<y*A<<std::endl;
        

}
