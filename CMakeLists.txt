cmake_minimum_required(VERSION 3.21)
project(AlgFlow)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgFlow main.cpp ICommonAlg.h AlgLib.h IMakeAlg.h CMakeAlgs.h CCompositeAlgs.h)
