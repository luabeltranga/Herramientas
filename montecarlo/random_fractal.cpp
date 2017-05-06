#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

struct point {
  double x;
  double y;
};

void fractal(point &pinit,int n);
void gif(int n);

int main (int argc , char ** argv){

  int n = atoi(argv[1]);
  
  point p;
  p.x = 0.0;
  p.y = 2.0;
  
  fractal(p,n);
  gif(n);
  return 0;
}


void fractal(point &pinit, int n){
  std::ofstream fractal;
  std::mt19937_64 g(3999999);
  std::uniform_int_distribution<int> h(1,3);
  point p1 ,p2 , p3 ;  
  p1.x = -20.0; p1.y = 0.0;
  p2.x = 20.0; p2.y = 0.0;
  p3.x= 0.0; p3.y=40.0;

  int dice = 0;
  
  fractal.open("fractal.txt");
  

  
  for (int kk = 0; kk< n ; kk++){
    dice = h(g);
    fractal << pinit.x << " " << pinit.y << "\n" ;    
    if(dice == 1 ){
      pinit.x = (pinit.x+p1.x)*0.5;
      pinit.y = (pinit.y+p1.y)*0.5; 
    }
    else if(dice == 2 ){
      pinit.x = (pinit.x+p2.x)*0.5;
      pinit.y = (pinit.y+p2.y)*0.5; 
    }
    else if(dice == 3){
      pinit.x = (pinit.x+p3.x)*0.5;
      pinit.y = (pinit.y+p3.y)*0.5; 
    }
  }
}
void gif (int n){
  std::ofstream gif;
  gif.close();
  
  gif.open("fractal.gp");
  gif << "set terminal gif animate" << "\n";
  gif << "set output 'frac.gif'" << "\n";
  gif << "unset key" << "\n";
  
  
  for (int ll = 1 ; ll < n; ll++){
    //gif << "plot [-2:2][0:4] 'fractal.txt' u 1:2 index "<< ll <<"  ps 0.5 pt 7"  << "\n";
    gif << "plot [-30:30][-10:50] 'fractal.txt' u 1:2 every :::: "<< ll <<"  ps 0.3 pt 6 "  << "\n";
  }
  gif.close();
}

