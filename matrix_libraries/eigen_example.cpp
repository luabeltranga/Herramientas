#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
int main()
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
   Matrix3d A;
   Vector3d b;
   A << 1,2,3,  4,5,6,  7,8,9;
   b << 3, 3, 4;
   std:: cout << "Here is the matrix A:\n" << A << std::endl;
   std::cout << "Here is the vector b:\n" << b << std::endl;
   Vector3d x = A.colPivHouseholderQr().solve(b);
   // Vector3d x = A.colPivHouseholderQr();
   std::cout << "The solution is:\n" << x << std::endl;
   std::cout << "The precision is:\n" << (A*x-b).norm() << std::endl;
}
