#include <iostream>
#include <random>
#include <Eigen/Dense>

const int  N = 100;
const int size = 2;
int main (void){
  Eigen::MatrixXf A(size,size);
  std::random_device g2 ;
  std::mt19937_64 g1 (134);
  std::normal_distribution<double> h(-1,1);
  double trace = 0;
  double det = 0;
  double saddle = 0;
  double nodes = 0;
  double spiral = 0;
  double star_deg_nod = 0;
  
  for(int k = 0;k<N;k++){
    for (int i = 0;i<size;i++){
      for (int j =0;j<size;j++){
	A(i,j)=h(g2);
      }
    }
    det=A.determinant();
    trace=A.trace();
    if(det<0){
      ++saddle;
    }
    else if(det>0 && trace*trace-4*det>0){
      ++nodes;
    }
    else if(det>0 && trace*trace-4*det<0){
      ++spiral;
    }
    
    else if(det==0){
      ++star_deg_nod;
    }
  }
  std::cout<<saddle/N<<std::endl;
  std::cout<<nodes/N<<std::endl;
  std::cout<<spiral/N<<std::endl;
  std::cout<<star_deg_nod/N<<std::endl;
  //std::cout<<A<<std::endl;  
  return 0;
}
