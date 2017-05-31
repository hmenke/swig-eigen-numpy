#pragma once

#include "dtypes.h"
#include <iostream>
#include <vector>

class Test
{
public:
  Eigen::VectorXd * v;
  Eigen::VectorXd const& rv;
  Eigen::MatrixXcd * m;
  Eigen::SparseMatrixXcd * sm;

  Test()
    : v (new Eigen::VectorXd(6))
    , rv(*v)
    , m(new Eigen::MatrixXcd(3,3))
    , sm(new Eigen::SparseMatrixXcd(3,3))
    {
      *v << 1,2,3,4,5,6;
      *m << 1,2,3, 4,5,6, 7,8,9;
      Eigen::MatrixXcd tmp(3,3);
      tmp << 1,0,0, 2,3,0, 0,0,4;
      *sm = tmp.sparseView();
    }

  ~Test()
    {
      if (v)  delete v;
      if (m)  delete m;
      if (sm) delete sm;
    }

  Eigen::VectorXd& viewvec() { return *v; }
  Eigen::VectorXd  copyvec() { return *v; }
  Eigen::MatrixXcd& viewmat() { return *m; }
  Eigen::MatrixXcd  copymat() { return *m; }
  Eigen::SparseMatrixXcd& viewspmat() { return *sm; }
  Eigen::SparseMatrixXcd  copyspmat() { return *sm; }

  void getvec(Eigen::VectorXd mat)          { std::cout << mat << '\n'; }
  void getmat(Eigen::MatrixXcd mat)         { std::cout << mat << '\n'; }
  void getspmat(Eigen::SparseMatrixXcd mat) { std::cout << mat << '\n'; }

  void showvec()   { if (v)  std::cout << *v  << '\n'; else std::cout << "v = NULL\n";  }
  void showmat()   { if (m)  std::cout << *m  << '\n'; else std::cout << "m = NULL\n";  }
  void showspmat() { if (sm) std::cout << *sm << '\n'; else std::cout << "sm = NULL\n"; }

  void killvec()   { delete v;  v = nullptr; }
  void killmat()   { delete m;  m = nullptr; }
  void killspmat() { delete sm; sm = nullptr; }
};
