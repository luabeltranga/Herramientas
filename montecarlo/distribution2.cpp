#include <iostream>
#include <random>
#include <fstream>

int main(void){
  std::ofstream lui ;

  std::mt19937_64 g1(10);
  std::normal_distribution<double> h1(-1,1);
  std::normal_distribution<double> h2(-2,2);
  double x = 0;
  double y = 0;
  lui.open("test2.dat");
  for(int jj = 0; jj<2000 ; jj++){
    x = h1(g1);
    y = h2(g1);

    if(x*x+(y*y/4)<1){
      lui<<x<<" "<<y<<"\n";
    }
    
    
  }
  
  lui.close();
  return 0;
}
