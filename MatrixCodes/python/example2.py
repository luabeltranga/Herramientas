import numpy as np
import scipy.linalg

# define the matrix
A = np.array([[1,2,3],[4,5,6],[7,8,8]])
print ("The matrix A is :\n", A)

# compute the determinant
print ("The det(A) is :\n", scipy.linalg.det(A))

# Compute the LU decomposition
P, L, U = scipy.linalg.lu(A)
print ("P*L*U : \n", np.dot(P, np.dot(L, U)))

# Compute the eigen vals
EW, EV = scipy.linalg.eig(A)
print ("Eigen values :\n", EW)
print ("Eigen vectors:\n", EV)

# Solving a system of linear equation
v = np.array([[2,3,5]])
s = scipy.linalg.solve(A, np.transpose(v))
print ("The linear system solutions is:\n", s)
print ("Checking :\n", np.dot(A, s) - np.transpose(v))
