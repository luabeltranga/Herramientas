#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

const int N = 600; //iterations

struct point {
  double x;
  double y;
};

void fractal(point &pinit,int n);


int main (int argc , char ** argv){

  int n = atoi(argv[1]);
  
  point p;
  p.x = 1.0;
  p.y = 1.0;
  
  fractal(p,n);
  
  return 0;
}



void fractal(point &pinit, int n){
  std::ofstream babas;
  std::mt19937_64 g(3999999);
  std::uniform_int_distribution<int> h(1,6);
  point p1 ,p2 , p3 ;  
  p1.x = -2.0; p1.y = 0.0;
  p2.x = 2.0; p2.y = 0.0;
  p3.x= 0.0; p3.y=4.0;

  int dice = 0;
  
  babas.open("fractal.txt");
  
  for (int kk = 0; kk< n ; kk++){
    dice = h(g);
    
    if(dice == 1 || dice == 2){
      pinit.x = (pinit.x+p1.x)*0.5;
      pinit.y = (pinit.y+p1.y)*0.5; 
    }
    else if(dice == 3 || dice == 4){
      pinit.x = (pinit.x+p2.x)*0.5;
      pinit.y = (pinit.y+p2.y)*0.5; 
    }
    else if(dice == 5 || dice == 6){
      pinit.x = (pinit.x+p3.x)*0.5;
      pinit.y = (pinit.y+p3.y)*0.5; 
    }

    babas << pinit.x << " " << pinit.y << "\n";
  }
  
  babas.close();

  babas.open("fractal.gp");
  babas << "plot 'fractal.txt'" << "\n";
  babas << "pause -1" << "\n";
  
  babas.close();
}

