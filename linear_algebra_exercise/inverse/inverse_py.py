import numpy as np
import scipy as sc
from scipy import linalg


A=np.array([[4,-2, 1], [3 , 6 , -4] , [2 , 1 , 8]])

print "La matriz m: \n", A

print "el determinante de m:",sc.linalg.det(A)

print "que cumple con: \n ",sc.linalg.inv(A)*sc.linalg.det(A)

print "Con precision: \n" ,A.dot(sc.linalg.inv(A))
