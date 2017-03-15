// ejemplos de arrays unidimensionales
// ejemplo:
// tipo name[int size];
// ejemplo de funciones con arrays unidimensionales

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL;

template <class T>
void printArray(const T array[], const int size);

#define SIZE 7

int main(void)
{
  // int size = 5;
  // declarar arreglo de int 
  int arrayInt[SIZE];
  
  // declarar arreglo de REAL
  REAL arrayReal[SIZE + 2];

  // Cual es el tamanho de los arrays?
  cout << sizeof(arrayInt) << endl;
  cout << sizeof(int) << endl;
  cout << sizeof(arrayReal) << endl;
  cout << sizeof(REAL) << endl;

  // el valor inicial de los arreglos es aleatorio porque 
  // no se declararon con valor inicial, imprimirlos para ver
  printArray(arrayInt, SIZE);
  
  printArray(arrayReal, SIZE);

  // Como asignar los valores inciales?
  // declarar otros arreglos  REAL
  REAL arrayReal2[SIZE + 2] = {0}; // todos a cero
  REAL arrayReal3[SIZE + 2] = {1,2,3,4,55,66,77,88,99}; // uno a uno
  REAL arrayReal4[SIZE + 2] = {1,2,3,4}; // algunos, el resto a cero
  REAL arrayReal5[] = {1,2,3,4}; // cuatro elementos
  

  cout << "Todos a cero" << endl;
  printArray(arrayReal2, SIZE);

  cout << "Uno a uno" << endl;
  printArray(arrayReal3, SIZE);

  cout << "Algunos, resto a cero" << endl;
  printArray(arrayReal4, SIZE);

  cout << "Cuatro elementos automatico, error en "
    "impresion (tamanho incorrecto)" << endl;
  printArray(arrayReal5, SIZE);
  
  cout << "Cuatro elementos automatico, NO error en "
    "impresion (tamanho correcto)" << endl;
  printArray(arrayReal5, sizeof(arrayReal5)/sizeof(REAL));

  return 0;
}

template <class T>
void printArray(const T array[], const int size)
{
  for (int i = 0; i < size; i++) {
    cout << array[i] << "\t";
  }
  cout << endl;
  cout << endl;
}
