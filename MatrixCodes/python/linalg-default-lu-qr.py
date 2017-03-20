#!/bin/env python 

import sys   # for reading argc and argv 
import numpy as np
import scipy as sp
from scipy import linalg

# Read command line arguments
N = int(sys.argv[1]) # repetitions
M = int(sys.argv[2]) # Problem size

# seed 
sp.random.seed(10)

# WARNING: Active only one solver at a time

ii = 0
while ii < N:
    # Array Declaracion
    A = sp.random.random((M, M)) 
    b = sp.random.random(M)
    
    # Default solve
   #x = sp.linalg.solve(A, b)
    
    # lu solve
    x = sp.linalg.lu_solve(sp.linalg.lu_factor(A), b)
    
    # qr solve
    #Q, R = sp.linalg.qr(A)
    #y = np.dot(Q.T, b)
    #x = sp.linalg.solve(R, y)
    
    # increment counter
    ii = ii + 1
    print x
    
# Printing
#print x
