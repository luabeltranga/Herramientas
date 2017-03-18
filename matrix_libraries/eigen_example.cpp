#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
   Matrix3d A;
   Vector3d b;
   A << 1,2,3,  4,5,6,  7,8,10;
   b << 3, 3, 4;
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   Vector3d x = A.colPivHouseholderQr().solve(b);
   cout << "The solution is:\n" << x << endl;
   cout << "The precision is:\n" << (A*x-b).norm() << endl;
}
