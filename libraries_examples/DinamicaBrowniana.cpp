#include <iostream>#include <cmath>#include "Random64.h"using namespace std;const double L=100;   const double T=298;const double MASA=22.8916;const double e=1;const double D=0.132;const double kb=0.826;const double Gamma=kb*T/(MASA*D);class Cuerpo{private:   double x,Vx,Fx,Fxpunto,m,R,q;public:  void Inicie(double x0, double Vx0, double Fx0, double m0, double q0, double R0);   void CalculeFuerza(double E, double dt);  void Muevase(double dt, Crandom & ran);  void Dibujese (void);  double Getx(void){return x;}  double GetJ(void){return q*Vx;}};void Cuerpo::Dibujese (void){  cout<< ", " << x << "+"<<R<<"*cos(t),0+"<<R<<"*sin(t)";}void Cuerpo::Inicie(double x0, double Vx0, double Fx0, double m0, double q0, double R0){ x = x0; Vx=Vx0; m=m0; q=q0; R=R0; Fx=Fx0;}void Cuerpo::CalculeFuerza(double E, double dt){  double Fxnew=q*E; Fxpunto=(Fxnew-Fx)/dt; Fx=Fxnew;}void Cuerpo::Muevase(double dt, Crandom & ran){  double sigma = sqrt(2*D*dt);  double xnew = x + (Fx*dt+Fxpunto*dt*dt/2)/(m*Gamma)+ran.gauss(0,sigma);  Vx= (xnew-x)/dt;  x = xnew;   if(x>L)x-=L;  if(x<0) x+=L; // condiciones de frontera periodicas}// ----------------------void InicieAnimacion (void){  cout << "set terminal gif animate" << endl;  cout << "set output 'MiIon.gif' " << endl;  cout << "unset key" << endl;  cout << "set xrange [-10:110]" << endl;  cout << "set yrange [-10:10]" << endl;  cout << "set xzeroaxis" << endl;  cout << "set style fill solid 0.0 border" << endl;  cout << "set size ratio -1" << endl;  cout << "set parametric" << endl;  cout << "set trange [0:7]" << endl;  cout << "set isosamples 12" << endl;}void InicieCuadro(void){  cout << "plot 0,0 ";}void TermineCuadro(void){  cout<<endl;}int main(void){  Cuerpo Ion;  Crandom ran(29);  double t,Deltat = 0.01, tmax = 10;  double E=0;  int i;  double Jprom;  InicieAnimacion ();  //--------( x0, Vx0, Fx0,  m0, q0, R0);   Ion.Inicie( L/2, 0 , 0 , MASA, 1,  2);    for(t=0;t<tmax;t+=Deltat){      // cout <<t<<Ion.Getx()<< endl;      InicieCuadro();      Ion.Dibujese();      TermineCuadro();      Ion.CalculeFuerza(E,Deltat);      Ion.Muevase(Deltat, ran);      }  return 0;}