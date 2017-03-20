#include<iostream>
#include<armadillo>

void resolve(void);

int main(int argc, char**argv){

  resolve();
  
  return 0;
}

void resolve(void){
  arma::mat A(5,5);
  arma::vec b(5);
  A << 0.18 << 0.60 << 0.57 << 0.96 <<arma::endr
  << 0.41 << 0.24 << 0.99 << 0.58 <<arma::endr
  << 0.14 << 0.30 << 0.97 << 0.66 <<arma::endr
  << 0.51 << 0.13 << 0.19 << 0.85 <<arma::endr;
  //A.print("A:");

  b << 1.0 << 2.0 << 3.0 << 4.0 ;
  // b.print();

  //lu_solve

  /*arma::mat P,L,U;
    arma::lu(L, U ,P ,A);
    arma::vec x = solve(trimatu(U),solve(trimatl(L),P*b)); */

  //qr_solve
  
  /*arma::mat Q, R;
  arma::qr(Q,R,A);
  arma::mat x =solve(R,solve(Q,b));*/

  //solve

  arma::mat x=solve(A,b);
  x.print();
}

