#include<iostream>
#include<Eigen/Dense>
#include<Eigen/Geometry>

using namespace Eigen;
//using namespace std;
void eigen_solver(void);

int main(void){

  eigen_solver();
  
  return 0;
}

void eigen_solver(void){
  Eigen::Matrix3d A;
  A << -2, 2, -3,
    2, 1, -6,
    -1, -2, 0;       
  
  Eigen::EigenSolver<Eigen::MatrixXd> es(A);
  std::cout << "The eigenvalues of A are:" << std::endl <<es.eigenvalues() << std::endl;
  std::cout << "The matrix of eigenvectors, V, is:" << std::endl <<es.eigenvectors() << std::endl << std::endl;

  Eigen::Vector3cd c = es.eigenvectors().col(1);
  Eigen::Vector3d h;
  h<<-1,-2,1;
  std::cout<<"The eigen vector corresponding to lambda = 5, is:\n"<<h<<std::endl;
  std::cout<<"To check if both vectors are proportional to each other, use cross product:\n"<<h.cross(c)<<std::endl;

  /*  EigenSolver<MatrixXd> es(A);
cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;
complex<double> lambda = es.eigenvalues()[0];
cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
VectorXcd v = es.eigenvectors().col(0);
cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
cout << "... and A * v = " << endl << A.cast<complex<double> >() * v << endl << endl;
MatrixXcd D = es.eigenvalues().asDiagonal();
MatrixXcd V = es.eigenvectors();
cout << "Finally, V * D * V^(-1) = " << endl << V * D * V.inverse() << endl;
  */
}

