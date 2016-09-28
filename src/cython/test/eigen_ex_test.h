// Eigen Ex Test Suite
#include <cxxtest/TestSuite.h>
#include <eigen_ex.h>
#include <Eigen/Dense>
#include <sstream>
#include <string>

using namespace Eigen;
using namespace eigen_ex;

template<class Base>
const std::string to_string(const Base &base){
  std::ostringstream oss;
  oss << '\n' << base;
  return oss.str();
}

template<class Base>
const bool compare(const Base &lhs, const Base &rhs){
  return (lhs - rhs).norm() < 1E-6;

}

class EigenExTestSuite : public CxxTest::TestSuite {
  private:
    MatrixXd A1 = MatrixXd(2,2);
    VectorXd x1 = VectorXd(2);
    VectorXd b1 = VectorXd(2);

    MatrixXd A2 = MatrixXd(3,3);
    VectorXd x2 = VectorXd(3);
    VectorXd b2 = VectorXd(3);
    int k2;
    VectorXd c2 = VectorXd(3);

    MatrixXd A3 = MatrixXd(4,4);
    VectorXd x3 = VectorXd(4);
    VectorXd b3 = VectorXd(4);
    int k3;
    VectorXd c3 = VectorXd(4);

    MatrixXd A4 = MatrixXd(5,5);
    VectorXd x4 = VectorXd(5);
    VectorXd b4 = VectorXd(5);

  public:
    void setUp(void){
      A1 << 2, 0,
            0, 1;
      x1 << 1, 1;
      b1 << 0.5, 1;

      A2 << 4, 2, 1,
            2, 3, 0,
            1, 0, 2;
      x2 << -1, -2, 0;
      b2 << 0.15384615, -0.76923077, -0.07692308;
      k2 = 100;
      c2 << 0.33333333, -0.33333333, -0.33333333;

      A3 << 3, 0, 0, 1,
            0, 2, 0, 0,
            0, 0, 1, 1,
            1, 0, 1, 2;
      x3 << 0, 2, 1, 2;
      b3 << -0.5,  1. , -0.5,  1.5;
      k3 = 3;
      c3 << -4.125,   0.25 , -14.875,  11.125;

      A4 << MatrixXd::Identity(5,5) * 4;
      x4 << 4, 2, 1, 0, -2;
      b4 << 1, 0.5, 0.25, 0, -0.5;
    }

    void testDefault(void){
      MatrixXd A(2,2);
      VectorXd b(2);
      VectorXd x(2);
      A << 2, 0,
           0, 1;
      x << 1,1;
      b << 0.5, 1;
      VectorXd b_ldlt = A.ldlt().solve(x);
      TS_ASSERT(compare(b, b_ldlt));

      TS_ASSERT(compare(b1, VectorXd(A1.ldlt().solve(x1))));
      TS_ASSERT(compare(b2, VectorXd(A2.ldlt().solve(x2))));
      TS_ASSERT(compare(b3, VectorXd(A3.ldlt().solve(x3))));
      TS_ASSERT(compare(b4, VectorXd(A4.ldlt().solve(x4))));
    }

    void test_positive_definite_inverse(void){
      TS_ASSERT(compare(b1, positive_definite_inverse(A1, x1)));
      TS_ASSERT(compare(b2, positive_definite_inverse(A2, x2)));
      TS_ASSERT(compare(b3, positive_definite_inverse(A3, x3)));
      TS_ASSERT(compare(b4, positive_definite_inverse(A4, x4)));
    }

    void test_positive_definite_inverse_size_4(void){
      auto A = Matrix4d(A3.topLeftCorner<4,4>());
      auto x = Vector4d(x3.head<4>());
      auto b = Vector4d(b3.head<4>());
      TS_ASSERT(compare(b, positive_definite_inverse_size_4(A, x)))
    }

    void test_multi_positive_definite_inverse(void){
      TS_ASSERT(compare(x1, multi_positive_definite_inverse(A1, x1, 0)));
      TS_ASSERT(compare(x2, multi_positive_definite_inverse(A2, x2, 0)));
      TS_ASSERT(compare(x3, multi_positive_definite_inverse(A3, x3, 0)));
      TS_ASSERT(compare(x4, multi_positive_definite_inverse(A4, x4, 0)));

      TS_ASSERT(compare(b1, multi_positive_definite_inverse(A1, x1, 1)));
      TS_ASSERT(compare(b2, multi_positive_definite_inverse(A2, x2, 1)));
      TS_ASSERT(compare(b3, multi_positive_definite_inverse(A3, x3, 1)));
      TS_ASSERT(compare(b4, multi_positive_definite_inverse(A4, x4, 1)));

      TS_ASSERT(compare(c2, multi_positive_definite_inverse(A2, x2, k2)));
      TS_ASSERT(compare(c3, multi_positive_definite_inverse(A3, x3, k3)));
    }

    void test_multi_positive_definite_inverse_size_4(void){
      auto A = Matrix4d(A3.topLeftCorner<4,4>());
      auto x = Vector4d(x3.head<4>());
      auto b = Vector4d(b3.head<4>());
      auto c = Vector4d(c3.head<4>());

      TS_ASSERT(compare(x, multi_positive_definite_inverse_size_4(A, x, 0)))
      TS_ASSERT(compare(b, multi_positive_definite_inverse_size_4(A, x, 1)))
      TS_ASSERT(compare(c, multi_positive_definite_inverse_size_4(A, x, k3)))
    }

};
