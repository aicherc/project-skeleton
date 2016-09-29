#include "eigen_ex.h"

namespace eigen_ex {

  VectorXd positive_definite_inverse(MatrixXd A, VectorXd x){
    VectorXd b = A.ldlt().solve(x);
    return b;
  }

  Vector4d positive_definite_inverse_size_4(Matrix4d A, Vector4d x){
    Vector4d b = A.ldlt().solve(x);
    return b;
  }

  VectorXd multi_positive_definite_inverse(MatrixXd A, VectorXd x, int k){
    VectorXd b = x;
    LDLT<MatrixXd> Ainv(A.rows());
    Ainv.compute(A);
    for(int ii = 0; ii < k; ii++){
      b = Ainv.solve(b);
    }
    return b;
  }

  Vector4d multi_positive_definite_inverse_size_4(Matrix4d A, Vector4d x, int k){
    VectorXd b = x;
    LDLT<MatrixXd> Ainv(A.rows());
    Ainv.compute(A);
    for(int ii = 0; ii < k; ii++){
      b = Ainv.solve(b);
    }
    return b;
  }

  VectorXd crazy_operation(MatrixXd A, VectorXd x, int k){
    VectorXd b = x;
    LDLT<MatrixXd> Ainv(A.rows());
    Ainv.compute(A);
    for(int ii = 0; ii < k; ii++){
      b = Ainv.solve(b) + x;
    }
    return b;
  }

  Vector4d crazy_operation_size_4(Matrix4d A, Vector4d x, int k){
    VectorXd b = x;
    LDLT<MatrixXd> Ainv(A.rows());
    Ainv.compute(A);
    for(int ii = 0; ii < k; ii++){
      b = Ainv.solve(b) + x;
    }
    return b;
  }


} // namespace eigen_ex


