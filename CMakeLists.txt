cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(example CXX)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Eigen3 REQUIRED)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

find_package(SWIG REQUIRED)
find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)

execute_process(
  COMMAND "${PYTHON_EXECUTABLE}" -c
  "from numpy import get_include; print(get_include())"
  OUTPUT_VARIABLE NUMPY_INCLUDE_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE)

find_path( NUMPY_INCLUDE_DIR
  NAMES numpy/arrayobject.h
  HINTS ${NUMPY_INCLUDE_PATH} ${PYTHON_INCLUDE_PATH} )

include(${SWIG_USE_FILE})
include_directories(${PYTHON_INCLUDE_PATH})
include_directories(SYSTEM ${NUMPY_INCLUDE_DIR})

set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/example.i PROPERTIES CPLUSPLUS ON SWIG_FLAGS "-py3")
swig_add_module(example python ${CMAKE_CURRENT_SOURCE_DIR}/example.i)
swig_link_libraries(example ${PYTHON_LIBRARIES})

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
    message(FATAL "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
  ${CMAKE_CURRENT_SOURCE_DIR}/test.py
  ${CMAKE_CURRENT_BINARY_DIR}/test.py)
