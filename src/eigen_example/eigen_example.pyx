# distutils: language = c++
# distutils: sources = cython/src/eigen_ex.cpp

# ^ distutils lines are important (do not delete)


# Import Eigen types (e.g. VectorXd, MatrixXd, numpy_copy, np.ndarray)
from eigency.core cimport *
import numpy as _np

# List C++ functions to wrap
cdef extern from "cython/src/eigen_ex.h":
    cdef VectorXd _positive_definite_inverse \
            "eigen_ex::positive_definite_inverse" \
            (Map[MatrixXd] &, Map[VectorXd] &)

def c_positive_definite_inverse(np.ndarray A, np.ndarray x):
    """ Eigen Implementation of inverse """
    # Check inputs
    if(A.ndim != 2 or A.shape[0] != A.shape[1]):
        raise ValueError("A must be a square matrix")
    if(_np.any(_np.linalg.eigvals(A) <= 0)):
        raise ValueError("A must be positive definite")
    if(x.ndim != 1):
        raise ValueError("x must be a vector")
    if(A.shape[0] != x.shape[0]):
        raise ValueError("A and x are incompatible sizes")

    bT = ndarray_copy(
            _positive_definite_inverse(Map[MatrixXd](A), Map[VectorXd](x))
            )
    b = bT.T # Eigen is column-major, python is row-major
    return b


