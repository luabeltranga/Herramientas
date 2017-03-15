// ejemplos de arrays unidimensionales
// ejemplo:
// tipo name[int size];

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL;

int main(void)
{
  int size = 25;
  // declarar arreglo de int 
  int arrayInt[size];

  // declarar arreglo de REAL
  REAL arrayReal[size + 32];

  // ejemplos 
  arrayInt[0] = 12345;
  arrayInt[1] = 54321;

  cout << arrayInt[0] << endl;
  cout << arrayInt[1] << endl;  
  cout << arrayInt[2] << endl;
  cout << endl;

  cout << arrayInt << endl;
  cout << &arrayInt[0] << endl;

  return 0;
}
