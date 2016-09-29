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

    cdef VectorXd _multi_positive_definite_inverse \
            "eigen_ex::multi_positive_definite_inverse" \
            (Map[MatrixXd] &, Map[VectorXd] &, int &)

    cdef Vector4d _multi_positive_definite_inverse_size_4 \
            "eigen_ex::multi_positive_definite_inverse_size_4" \
            (Map[Matrix4d] &, Map[Vector4d] &, int &)

    cdef VectorXd _crazy_operation \
            "eigen_ex::crazy_operation" \
            (Map[MatrixXd] &, Map[VectorXd] &, int &)

    cdef Vector4d _crazy_operation_size_4 \
            "eigen_ex::crazy_operation_size_4" \
            (Map[Matrix4d] &, Map[Vector4d] &, int &)


def _check_inputs(A, x, k = 1, fixed_size = False):
    if(A.ndim != 2 or A.shape[0] != A.shape[1]):
        raise ValueError("A must be a square matrix")
    if(_np.any(_np.linalg.eigvals(A) <= 0)):
        raise ValueError("A must be positive definite")
    if(x.ndim != 1):
        raise ValueError("x must be a vector")
    if(A.shape[0] != x.shape[0]):
        raise ValueError("A and x are incompatible sizes")
    if(type(k) is not int):
        raise TypeError("k must be an int")
    if(k < 0):
        raise ValueError("k must be nonnegative")
    if(fixed_size):
        if(x.shape[0] != 4):
            raise ValueError("x must be a vector of size 4")
    return


def c_positive_definite_inverse(np.ndarray A, np.ndarray x):
    """ Eigen Implementation of inverse """
    # Check inputs
    _check_inputs(A, x)

    bT = ndarray_copy(
            _positive_definite_inverse(Map[MatrixXd](A), Map[VectorXd](x))
            )
    b = bT.T # Eigen is column-major, python is row-major
    return b

def c_multi_positive_definite_inverse(np.ndarray A, np.ndarray x, int k):
    """ Eigen Implementation of inverse to the k-th power"""
    # Check inputs
    _check_inputs(A, x, k)

    bT = ndarray_copy(
            _multi_positive_definite_inverse(
                Map[MatrixXd](A), Map[VectorXd](x), k)
            )
    b = bT.T # Eigen is column-major, python is row-major
    return b

def c_multi_positive_definite_inverse_size_4(np.ndarray A, np.ndarray x, int k):
    """ Eigen Implementation of inverse to the k-th power for dimension 4 """
    # Check inputs
    _check_inputs(A, x, k, fixed_size=True)

    bT = ndarray_copy(
            _multi_positive_definite_inverse_size_4(
                Map[Matrix4d](A), Map[Vector4d](x), k)
            )
    b = bT.T # Eigen is column-major, python is row-major
    return b

def c_crazy_operation(np.ndarray A, np.ndarray x, int k):
    """ Eigen Implementation of crazy function"""
    # Check inputs
    _check_inputs(A, x, k)

    bT = ndarray_copy(
            _crazy_operation(Map[MatrixXd](A), Map[VectorXd](x), k)
            )
    b = bT.T # Eigen is column-major, python is row-major
    return b

def c_crazy_operation_size_4(np.ndarray A, np.ndarray x, int k):
    """ Eigen Implementation of crazy function for dimension 4 """
    # Check inputs
    _check_inputs(A, x, k, fixed_size=True)

    bT = ndarray_copy(
            _crazy_operation_size_4(Map[Matrix4d](A), Map[Vector4d](x), k)
            )
    b = bT.T # Eigen is column-major, python is row-major
    return b





