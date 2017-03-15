// ejemplos de arrays unidimensionales
// ejemplo:
// tipo name[int size];

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL;

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
  int i;
  for (i = 0; i < SIZE; i++) {
    cout << arrayInt[i] << "\t";
  }
  cout << endl;
  cout << endl;
  
  for (i = 0; i < SIZE; i++) {
    cout << arrayReal[i] << "\t";
  }
  cout << endl;
  cout << endl;

  // Como asignar los valores inciales?
  // declarar otros arreglos  REAL
  REAL arrayReal2[SIZE + 2] = {0}; // todos a cero
  REAL arrayReal3[SIZE + 2] = {1,2,3,4,55,66,77,88,99}; // uno a uno
  REAL arrayReal4[SIZE + 2] = {1,2,3,4}; // algunos, el resto a cero
  REAL arrayReal5[] = {1,2,3,4}; // cuatro elementos
  

  cout << "Todos a cero" << endl;
  for (i = 0; i < SIZE; i++) {
    cout << arrayReal2[i] << "\t";
  }
  cout << endl;
  cout << endl;

  cout << "Uno a uno" << endl;
  for (i = 0; i < SIZE; i++) {
    cout << arrayReal3[i] << "\t";
  }
  cout << endl;
  cout << endl;

  cout << "Algunos, resto a cero" << endl;
  for (i = 0; i < SIZE; i++) {
    cout << arrayReal4[i] << "\t";
  }
  cout << endl;
  cout << endl;

  cout << "Cuatro elementos automatico, error en "
    "impresion (tamanho incorrecto)" << endl;
  for (i = 0; i < SIZE; i++) {
    cout << arrayReal5[i] << "\t";
  }
  cout << endl;
  cout << endl;
  
  cout << "Cuatro elementos automatico, NO error en "
    "impresion (tamanho correcto)" << endl;
  for (i = 0; i < sizeof(arrayReal5)/sizeof(REAL); i++) {
    cout << arrayReal5[i] << "\t";
  }
  cout << endl;
  cout << endl;


  return 0;
}
