// memoria din\'amica
// operadores new y delete
#include <iostream>
#include <cassert>
using namespace std;

typedef double REAL;
//typedef float REAL;

int main(void)
{
  // un arreglo 1d con dimensi\'on desconocida
  REAL *x; // pointer, no memory reserved yet
  int n; 

  cout << "Por favor escriba el tamanho del arreglo: " << endl;
  cin >> n;

  cout << x << endl; // ver la direcci\'on inicial de x

  // crear el arreglo de acuerdo a la entrada del usuario
  x = new REAL [n];
  // PRECAUCION: verificar que la memoria se asigno
  assert(x != NULL); // aborta si no se asigno la memoria, n = 999999999
  
  cout << x << endl; // ver la direccion final de x
  
  // listo, se puede usar el arreglo x[0], x[1], ... , x[n -1]  x[0] = 1;
  x[2] = 3;
  x[3] = x[0] + x[2];
  cout << x[0] << endl;
  cout << x[1] << endl;
  cout << x[2] << endl;
  cout << x[3] << endl;
 
  // liberar la memoria
  delete [] x;
  x = NULL;
 
  return 0;
}
