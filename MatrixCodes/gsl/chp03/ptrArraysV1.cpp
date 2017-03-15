// ejemplos de arrays unidimensionales
// ejemplo:
// tipo name[int size];

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL;

void printByIndex(const REAL array[], const int size);
void printByPtr(const REAL array[], const int size);
void printByPtrDir(const REAL *array, const int size);

const int size = 5;

int main(void)
{
  // declarar arreglo de tipo REAL
  REAL arrayReal[size + 2];

  cout << arrayReal << endl;
  cout << &arrayReal[0] << endl;

  // declarar un puntero tipo REAL
  REAL *ptr; 
  
  // asignar la direccion de memoria del arreglo arrayReal a ptr
  ptr = arrayReal;
  //ptr = &arrayReal[0]; // equivalente a la anterior

  cout << arrayReal << endl;
  cout << &arrayReal[0] << endl;
  cout << arrayReal[0] << endl;
  cout << ptr << endl;
  cout << *ptr << endl;
  
  // manipular el array por indices o por punteros
  // primero elemento por indice
  arrayReal[0] = -23.654; // == *(arrayReal + 0) = -23.654 
  // segundo elemento por puntero array
  *(arrayReal + 1) = 76.987;
  // cuarto elemento por puntero nuevo
  *(ptr + 3) = 12345.6789;

  // imprimir
  printByIndex(arrayReal, size);
  printByPtr(arrayReal, size);

  // impresion especial
  printByPtrDir(arrayReal, size); // from 0 to size-1
  printByPtrDir(arrayReal + 2, size - 2); // from index 2 
  printByPtrDir(arrayReal + 4, size - 4); // from index 4

  return 0;
}

void printByIndex(const REAL array[], const int size)
{
  cout << endl; 
  for (int i = 0; i < size; i++) {
    cout << array[i] << "\t" ;
  }
  cout << endl; 
}

void printByPtr(const REAL array[], const int size)
{
  cout << endl; 
  for (int i = 0; i < size; i++) {
    cout << *(array + i) << "\t" ;
  }
  cout << endl; 
}

void printByPtrDir(const REAL *array, const int size)
{
  cout << endl; 
  for (int i = 0; i < size; i++) {
    cout << *(array + i) << "\t" ;
  }
  cout << endl; 
}
