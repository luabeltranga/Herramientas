#include <iostream>
#include <cmath>
#include <Eigen/Dense>

int main (void){
  Eigen::MatrixXf test (4,4);
  Eigen::MatrixXf id = Eigen::MatrixXf::Identity(4,4);

  test(0,0) = 1.0;
  test(1,1) = 0.8 , test(1,2) = 0.3 , test(1,3) = -0.52;
  test(2,1) = -0.6 , test(2,2) = 0.4 , test(2,3) = -0.69;
  test(3,2) = 0.86 , test(3,3) = 0.5;
  std::cout<<test<<std::endl;
  std::cout<<test*test.transpose()-id<<std::endl;
  
  
  
  return 0;
}



  
  
  
  
