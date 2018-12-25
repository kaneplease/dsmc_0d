cmake_minimum_required(VERSION 3.12)
project(dsmc_0d)

set(CMAKE_CXX_STANDARD 14)

add_executable(dsmc_0d main.cpp particles.cpp particles.h MyDSMC.cpp MyDSMC.h)