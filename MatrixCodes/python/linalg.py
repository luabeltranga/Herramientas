#!/bin/env python 

import numpy as np
import scipy as sp
from scipy import linalg

a = np.array([[3,2,0],[1,-1,0],[0,5,1]])
b = np.array([2,4,-1])
x = sp.linalg.solve(a,b)
print x
x = sp.linalg.lu_solve(sp.linalg.lu_factor(a), b)
print x
