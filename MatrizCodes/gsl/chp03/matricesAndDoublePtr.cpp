// relacion entre matrices y apuntadores dobles
// usa memoria dinamica

#include <iostream>
 using namespace std;

 typedef double REAL;
 //typedef float REAL;

 const int m = 4;
 const int n = 3; 

 int main(void)
 {
   REAL **a; // apuntador doble
   int i, j;

   // asignar la memoria: reservar el arreglo de apuntadores a cada fila
   a = new REAL *[m]; // arreglo de m apuntadores
   assert(a != NULL); // verificar que la memoria fue asignada
   // asignar la memoria de cada fila
   for(i = 0; i < m; i++) {
     a[i] = new REAL [n]; // tamanho de cada fila
     assert(NULL != a[i]);
   }

   // imprimir las direcciones para ver como esta organizada la matriz
   for (i = 0; i < m; i++) {
     for (j = 0; j < n; j++) {
       cout << "  &a[" << i << "][" << j << "] = " << int(&a[i][j]);
     }
     cout << endl;
   }
   cout << endl;
   
   for (i = 0; i < m; i++)
     cout << "  a[" << i << "] = " << int(a[i]) << endl;
   cout << endl;
   for (i = 0; i < m; i++)
     cout << "  &a[" << i << "] = " << int(&a[i]) << endl;
   cout << endl;
   
   cout << "  a = " << int(a) << endl;

   // liberar la memoria
   for(j = 0; j < n; j++) {
     delete [] a[i];
   }
   delete [] a;
     
  return 0;
}
