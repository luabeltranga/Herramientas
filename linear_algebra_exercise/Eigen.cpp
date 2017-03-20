#include <iostream>
#include <Eigen/Dense>

void solver(void);

int main(void){
  
  solver();
  return 0;
}


void solver(void){

  Eigen::Matrix4d A;
  A << 0.18, 0.60, 0.57, 0.96,
    0.41, 0.24, 0.99, 0.58,
    0.14, 0.30, 0.97, 0.66,
    0.51, 0.13, 0.19, 0.85;
  Eigen::Vector4d b;
  b<< 1.0, 2.0, 3.0, 4.0;

  Eigen::Vector4d x=A.lu().solve(b);
  
  
  std::cout<<x<<std::endl;
        

}
