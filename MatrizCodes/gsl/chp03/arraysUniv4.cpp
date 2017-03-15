// ejemplos de arrays unidimensionales
// ejemplo:
// tipo name[int size];
// ejemplo de funciones con arrays unidimensionales
// los areglos siempre se pasan por referencia

#include <iostream>
using namespace std;

typedef double REAL;
// typedef float REAL;

template <class T>
void printArray(const T array[], const int size);

template <class T>
T getMaxFromArray(const T array[], const int size);

template <class T>
void setArray(T array[], const int size, const T valToSet);

#define SIZE 7

int main(void)
{
  // declarar arreglo de int 
  int arrayInt[SIZE] = {-3, -44, 56, 123};
  
  printArray(arrayInt, SIZE);
  cout << getMaxFromArray(arrayInt, SIZE) << endl;
  
  // declarar arreglo de REAL
  REAL arrayReal[SIZE + 2] = {1};
  
  cout << endl;
  cout << endl;
  cout << endl;
  printArray(arrayReal, SIZE);
  setArray(arrayReal, SIZE, -6.765);
  printArray(arrayReal, SIZE);

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

template <class T>
T getMaxFromArray(const T array[], const int size)
{
  T maxval = array[0];
  
  for (int i = 1; i < size; i++)
    if (array[i] > maxval) 
      maxval = array[i];

  return maxval;
}


template <class T>
void setArray(T array[], const int size, const T valToSet)
{
  for (int i = 0; i < size; i++) {
    array[i] = valToSet;
  }
}
