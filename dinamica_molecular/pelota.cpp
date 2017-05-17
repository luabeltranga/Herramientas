#include <iostream>
#include <cmath>

const double G = 9.81;
const double DT = 0.001;
const double K = 199.87;
const double LX = 125;

struct particle{
  double x{0}, y{0}, vx{0}, vy{0}, fx{0}, fy{0};  
  double mass{0}, rad{0};
};

void compute_forces(particle & bola);
void time_step(particle & bola, const double &dt);
int main (void){
  particle ball;

  //initial conditions
  ball.y = 9.8765434;
  ball.mass = 2.65;
  ball.rad = 0.15;
  ball.vx = 2.7;
  
  std::cout << "0.0" <<" "  << ball.x << "\t" << ball.y << "\t" << ball.vx << "\t" << ball.vy <<  std::endl;
  
   for(int ii = 1 ; ii < 100000  ; ii++){
     compute_forces(ball);
     time_step(ball,DT);
     std::cout << ii*DT <<" "  << ball.x << "\t" << ball.y << "\t" << ball.vx << "\t" << ball.vy <<  std::endl;
   }
  
  return 0;
}


void compute_forces(particle & bola){
  //reset forces
  bola.fx = 0.0;
  bola.fy = 0.0;

  //add gravity
  bola.fy += -bola.mass*G;

  //force with floor
  double h1 = bola.rad - bola.y;
  if (h1 > 0){
    bola.fy += K*h1; 
  }

  //force with wall
  double h2 = bola.rad + bola.x-LX;
  if (h2 > 0){
    bola.fx += -K*h2; 
  }
}

void time_step(particle & bola, const double &dt){

  bola.x = bola.x + dt*bola.vx + 0.5*dt*dt*bola.fx/bola.mass;
  bola.y = bola.y + dt*bola.vy + 0.5*dt*dt*bola.fy/bola.mass;

  bola.vx = bola.vx + dt*bola.fx/bola.mass;
  bola.vy = bola.vy + dt*bola.fy/bola.mass;
  
}


