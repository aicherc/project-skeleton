import numpy as np

def py_positive_definite_inverse(A, x, k):
    """ Python Implementation of inverse"""
    b = np.linalg.solve(A, x)
    return b


def py_multi_positive_definite_inverse(A, x, k):
    """ Python Implementation of inverse to the k-th power"""
    b = x
    for ii in xrange(0, k):
        b = np.linalg.solve(A, b)
    return b

def py_crazy_operation(A, x, k):
    """ Python Implementation of crazy function"""
    b = x
    for ii in xrange(0, k):
        b = np.linalg.solve(A, b) + x
    return b


