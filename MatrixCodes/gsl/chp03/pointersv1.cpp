// un  puntero guarda direcciones de memoria
// ejemplo de punteros: como declararlos, como usarlos

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL;

int main(void)
{
  int i, *iptr; // i es una variable normal, iptr es un puntero

  i = -10;
  
  iptr = &i; // asignar la direccion de la variable i a iptr
  //iptr = i; // error, iptr guarda direcciones, no valores

  cout << i << endl; 
  cout << &i << endl; 
  cout << iptr << endl;
  cout << &iptr << endl;
  cout << *iptr << endl;
  cout << endl; 

  *iptr = 12345; // desreferenciar iptr y guardar el valor nuevo, i = 12345
  
  cout << i << endl; 
  cout << &i << endl; 
  cout << iptr << endl;
  cout << &iptr << endl;
  cout << *iptr << endl;
  cout << endl; 

  return 0;
}
