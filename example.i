%module example

%{
#define SWIG_FILE_WITH_INIT
#include "NumpyUtils.h"
#include "Traits.h"
#include "example.hpp"
%}

%init %{
import_array();
%}

%include "exception.i"

// Convert C++ exceptions to Python exceptions
// http://www.swig.org/Doc1.3/Library.html#Library_stl_exceptions
%exception {
  try {
    $action
  } catch (const std::exception& e) {
    SWIG_exception(SWIG_RuntimeError, e.what());
  }
}

%include "dtypes.h"

%define MAKE_NUMPY_TYPEMAP(TYPE...)
  %typemap(out) TYPE        { $result = numpy::convert<numpy::copy>( $1); }
  %typemap(out) TYPE &      { $result = numpy::convert<numpy::view>(*$1); }
  %typemap(out) TYPE const&
  {
    $result = numpy::convert<numpy::view>(*const_cast<
      traits::pointer_add_const< decltype($1) >::type >($1));
  }
  %typemap(in) TYPE // SWIG omits the exception handler here
  {
    try {
      $1 = numpy::as<TYPE>($input);
    } catch(std::exception &e) {
      SWIG_exception(SWIG_RuntimeError, e.what());
    }
  }
%enddef

MAKE_NUMPY_TYPEMAP(Eigen::VectorXd);
MAKE_NUMPY_TYPEMAP(Eigen::MatrixXcd);
MAKE_NUMPY_TYPEMAP(Eigen::SparseMatrixXcd);

//%typemap(in) Eigen::MatrixXcd   { $1 = numpy::to < Eigen::MatrixXcd  >($input); }
//%typemap(in) Eigen::MatrixXcd & { $1 = numpy::to < Eigen::MatrixXcd& >($input); }


%include "example.hpp"
