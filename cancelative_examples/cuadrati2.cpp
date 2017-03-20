#include <iostream>
#include <cmath>

double bas1 (double a, double b, double c);
double bas2 (double a, double b, double c);

int main (void){
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double a = 1.0e-17;
  double b = -1.0e17;
  double c = 1.0e17;
  unsigned char r =241;
  if (a == 0 && b == 0){
    std::cout<<"No hay solucion"<<std::endl;
  }
  else if(a==0 && b!=0){
    std::cout<<"La unica raiz: "<<-c/b<<std::endl;
  }
  else if(a!=0 && b==0){
    if(c<=0){
      std::cout<<"Las raices: +-"<<std::sqrt(-c/a) <<std::endl;
    }
    else{
      std::cout<<"Las raices: i"<<std::sqrt(c/a) <<std::endl;
    }
  }
  
  
  else{
    std::cout<<bas1(a,b,c)<<std::endl;
    std::cout<<bas2(a,b,c)<<std::endl;
  }

  return 0;
}

double bas1 (double a, double b, double c){

  return (b/2/a)*(-1+std::sqrt(1-(4*a*c/b/b)));

}

double bas2 (double a, double b, double c){

  return -(b/2/a)*(1+std::sqrt(1-(4*a*c/b/b)));

}
