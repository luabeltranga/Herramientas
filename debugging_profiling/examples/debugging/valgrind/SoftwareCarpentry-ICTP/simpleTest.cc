#include <stdio.h>

/**
Borrows from 
http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/
*/

int main(void)
{
  char *p ;
  unsigned  short  sz=1;
  p = new char[sz];
  delete[] p;
  p = new char[12];
  delete[] p;
  p = new char[16];
  delete[] p;
  printf("Size is %d\n" , sz);

  //  delete p;
  
  return 0;
}
