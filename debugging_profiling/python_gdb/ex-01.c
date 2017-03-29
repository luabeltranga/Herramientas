#include<stdio.h>


int main(void) {
  
  const int nrow = 4;
  const int ncol = 3;
  
  double x[nrow * ncol];
  for(int i = 0; i < nrow; i++) {
    
    for(int j = 0; j < ncol; j++) {      
      x[i * ncol + j] = i * j;      
    }
  }
  // BREAK here
  return 0;
}
