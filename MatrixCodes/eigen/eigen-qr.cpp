#include <iostream>
#include <Eigen/Dense>

void solvesystem(const int & n);



int main(int argc, char **argv)
{
  const int N = atoi(argv[1]); // Repetitions
  const int M = atoi(argv[2]); // Matrix size

  for (int rep = 0; rep < N; ++rep) {
    solvesystem(M);
  }
}

void solvesystem(const int & n)
{
  Eigen::MatrixXd A; A.setRandom(n, n);
  Eigen::VectorXd b; b.setRandom(n);
  // A << 1,2,3,  4,5,6,  7,8,10;
  // b << 3, 3, 4;
  Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
  std::cout << "The solution is:\n" << x << std::endl;
}
