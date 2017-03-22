#include <iostream>
#include <Eigen/Dense>

void inverse(void);


int main (void){

  inverse();

  return 0;
}

void inverse(void){

  Eigen::Matrix3d m;
  //Eigen::Matrix3d z = Eigen::Matrix3d::Identity();
  m << 4 ,-2 , 1 , 3 , 6 ,-4 , 2 , 1 , 8; 

 

  std::cout<<"The matrix m: \n"<<m<<std::endl;
  std::cout<<"the determinant of m : "<<m.determinant()<<std::endl;
  std::cout<<"the inverse of m : \n"<<m.inverse()<<std::endl;
  std::cout<<"Which satisfies: \n"<<m.inverse()*m.determinant()<<std::endl;
  std::cout<<"With the precision of: \n"<<m.inverse()*m<<std::endl;



}

