#include <iostream>
#include <random>
#include <fstream>

int main(void){
  std::ofstream lui ;

  std::mt19937_64 g1(100);
  std::uniform_real_distribution<double> h1(-2,2);
  std::uniform_real_distribution<double> h2(-2,2);
  double x = 0;
  double y = 0;
  lui.open("test1.dat");
  for(int jj = 0; jj<2000 ; jj++){
    x = h1(g1);
    y = h1(g1);

    if(x*x+4*y*y<4){
      lui<<x<<" "<<y<<"\n";
    }
    
    
  }
  lui.close();

  lui.open("rete.gp");
  lui<<"set parametric"<<"\n";
  lui<<"plot 'test1.dat' , 2*sin(t),cos(t)"<<"\n";
  lui<<"pause -1"<<"\n";
  lui.close();
  
  return 0;
}
