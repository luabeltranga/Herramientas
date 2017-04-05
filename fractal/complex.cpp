#include <iostream>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <cmath>
#include <fstream>
void newton( gsl_complex &z);
void color( gsl_complex &z,int &a);

int main(void){
  gsl_complex test={0.0,1.0};
  int a=0;
  std:: ofstream fout;
  // calcula el numero complejo por el metodo de newton
  fout.open("n_parte.dat");
  for(double ii=-1;ii<1;ii+=0.01 ){
    for(double jj = -1;jj<1;jj+=0.01){
      GSL_SET_COMPLEX(&test,ii,jj);
      newton(test);
      color(test,a);
      if(a==1){	
	fout<<" "<<ii<<" "<<jj<<" "<<"\n";
      }
    }
  }
  fout.close();
  
  return 0;
}

//metodo de newton
void newton( gsl_complex &z){
  gsl_complex f =gsl_complex_sub_real(gsl_complex_pow_real (z,3.0),1.0);
  gsl_complex f_der =gsl_complex_mul_real(gsl_complex_pow_real (z,2.0),3.0);
  z=gsl_complex_sub(z,gsl_complex_div(f,f_der));
  if(gsl_complex_abs(f)>=1.0e-10){
    newton(z);
  }
}
//asigna color dependiendo del valor al que llega la raiz
void color( gsl_complex &z,int &a){
  const gsl_complex r1 = {1.0,0.0};    //raices de z*z*z -1
  const gsl_complex r2 = {-0.5 ,std::sqrt(3)/2.0};
  const gsl_complex r3 = {-0.5 ,-1*std::sqrt(3)/2.0};

  if(gsl_complex_abs(gsl_complex_sub(z,r1))<=1.0e-10){
    a=1;
  }
  else if(gsl_complex_abs(gsl_complex_sub(z,r2))<=1.0e-10){
    a=2;
  }
  else{
    a=3;
  }
}
