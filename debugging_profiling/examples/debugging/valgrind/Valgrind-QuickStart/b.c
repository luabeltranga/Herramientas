#include <stdio.h>

int main()
{
  int x=0;
  printf ("x = %d\n", x);


  int i=0, j=0;
  int a[10]={1,2,3,4,5,6,7,8,9,0}, b[10]={1,2,3,4,5,6,7,8,9,0};
  for ( i = 0; i < 10; ++i ) {
    j += a[i];
  }
  if ( j == 77 ) {
    printf("hello there\n");
  }
    return 0;
}
