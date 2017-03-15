#include <iostream>
using namespace std;

typedef double REAL;
//typedef float REAL;

int main(void)
{

  REAL b[2] = {6.0, 0.02}; // allocated last
  REAL a[2] = {0.01, 0.3}; // allocated first

  cout << a << endl;
  cout << b << endl;

  if (a > b) 
    cout << " a > b" << endl;
  else 
    cout << " b > a" << endl;

  // positions in memory
  // a[0] a[1] b[0] b[1]
  
  cout << b[0] << endl; 
  cout << b[-1] << endl; 
  cout << a[2] << endl; 
    
  cout << (a[0]*a[0] + a[1]*a[1] + a[2]*a[2]) << endl;

  return 0;
}
