// my first pointer
#include <iostream>

int main ()
{
  int firstvalue, secondvalue;
  int * mypointer;

  mypointer = &firstvalue;
  *mypointer = 10;
  mypointer = &secondvalue;
  *mypointer = 20;
  std::cout << "firstvalue is " << firstvalue << '\n';
  std::cout << "secondvalue is " << secondvalue << '\n';
  return 0;
}
