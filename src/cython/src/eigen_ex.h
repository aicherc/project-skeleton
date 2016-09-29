// Provides functions:
// Function that takes vector $x$ and matrix $A$ and returns A\x
// Function that takes int k, vector $x$ and matrix $A$ and returns A^k\x
// Function that returns (A \ (...\ (A\x + x) + ...) + x)
// Same functions for fixed dimension 4

#include <Eigen/Dense>

#ifndef EIGEN_EX_H
#define EIGEN_EX_H

using namespace Eigen;

namespace eigen_ex {

  VectorXd positive_definite_inverse(MatrixXd A, VectorXd x);
  Vector4d positive_definite_inverse_size_4(Matrix4d A, Vector4d x);

  VectorXd multi_positive_definite_inverse(MatrixXd A, VectorXd x, int k);
  Vector4d multi_positive_definite_inverse_size_4(Matrix4d A, Vector4d x, int k);

  VectorXd crazy_operation(MatrixXd A, VectorXd x, int k);
  Vector4d crazy_operation_size_4(Matrix4d A, Vector4d x, int k);

} // namespace eigen_ex

#endif
