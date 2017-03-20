import numpy as np
import scipy as sp
from scipy import linalg

a = np.array([[0.18,0.60,0.57,0.96],[0.41,0.24,0.99,0.58],[0.14,0.30,0.97,0.66],[0.51,0.13,0.19,0.85]])
b = np.array([1.0,2.0,3.0,4.0])

x=sp.linalg.lu_solve(sp.linalg.lu_factor(a),b)

print np.transpose(x)
           
