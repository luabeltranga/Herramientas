#include<iostream>
#include<Eigen/Dense>

void solve(void);


int main(int argv,char** argc){

  solve();
  //  std::cout<<A<<std::endl;
  
  return 0;
}

void solve(void){
  Eigen::Matrix3d A;
  A(0,0)=4, A(0,1)=-2, A(0,2)=1;
  A(1,0)=3 ,A(1,1)=6,A(1,2)=-4;
  A(2,0)=2 , A(2,1)=1 , A(2,2)=8;

  Eigen::Vector3d b1;
  b1(0)=12, b1(1)=-25, b1(2)=32;
  Eigen::Vector3d x1 = A.lu().solve(b1);
  std::cout<<"La solucion al primer problema: \n"<<x1<<std::endl<<std::endl;
  
  Eigen::Vector3d b2;
  b2(0)=4, b2(1)=-10, b2(2)=22;
  Eigen::Vector3d x2 = A.lu().solve(b2);
  std::cout<<"La solucion al segundo problema: \n"<<x2<<std::endl<<std::endl;
  
  Eigen::Vector3d b3;
  b3(0)=20, b3(1)=-30, b3(2)=40;
  Eigen::Vector3d x3 = A.lu().solve(b3);
  std::cout<<"La solucion al tercer problema: \n"<<x3<<std::endl<<std::endl;
}
