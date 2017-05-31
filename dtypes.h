#pragma once
#include <Eigen/SparseCore>

namespace Eigen {
  typedef SparseMatrix<double> SparseMatrixXd;
  typedef SparseMatrix<std::complex<double>> SparseMatrixXcd;
}
