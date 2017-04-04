#include <iostream>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <cmath>

void newton( gsl_complex &z);

int main(void){
  gsl_complex test={40.0,0.0};
  const gsl_complex r1 = {1.0,0.0};    //raices de z*z*z -1
  const gsl_complex r2 = {-0.5 ,std::sqrt(3)/2.0};
  const gsl_complex r3 = {-0.5 ,-1*std::sqrt(3)/2.0};
  /*for (int jj = 0; jj< 10 ;jj++){
    GSL_SET_COMPLEX(&a,jj,jj-1.0);
    
    std::cout<<GSL_REAL(a)<<std::endl;
    std::cout<<GSL_IMAG(a)<<std::endl;
    std::cout<<gsl_complex_abs(a)<<std::endl;
    
    }
  */
  
  //std::cout<<GSL_REAL(r1)<<std::endl; //imprime la parte real
  //std::cout<<GSL_IMAG(r1)<<std::endl;//imprime la parte imaginaria
  //std::cout<<gsl_complex_abs(r1)<<std::endl; // imprime la norma del numero complejo
  
  // calcula el numero complejo por el metodo de newton
  for(int jj=1;jj<20;jj++ ){
    for(int ii = 0;ii<2;ii++){
      GSL_SET_COMPLEX(&test,jj,0.0);
      newton(test);
      std::cout<<" "<<GSL_REAL(test)<<" "<<GSL_IMAG(test)<<" "<<gsl_complex_abs(gsl_complex_sub(r1,test))<<std::endl;
    }
  }
  //imprime la raiz
  //std::cout<<GSL_REAL(test)<<std::endl;
  //std::cout<<GSL_IMAG(test)<<std::endl;
  std::cout<<gsl_complex_abs(test)<<std::endl;
  
  return 0;
}


void newton( gsl_complex &z){
  gsl_complex f =gsl_complex_sub_real(gsl_complex_pow_real (z,3.0),1.0);
  gsl_complex f_der =gsl_complex_mul_real(gsl_complex_pow_real (z,2.0),3.0);
  z=gsl_complex_sub(z,gsl_complex_div(f,f_der));
  if(gsl_complex_abs(f)==0){
    break;
  }
  else{
    newton(z);
  }
}
