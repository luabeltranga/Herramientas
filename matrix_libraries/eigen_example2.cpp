#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main(int argc, char **argv)
{
  int N = atoi(argv[1]); 
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  MatrixXd A = MatrixXd::Random(N,N);
  MatrixXd b = MatrixXd::Random(N,N/2);
  MatrixXd x = A.fullPivLu().solve(b);
  double relative_error = (A*x - b).norm() / b.norm(); // norm() is L2 norm
  cout << "The relative error is:\n" << relative_error << endl;
}
