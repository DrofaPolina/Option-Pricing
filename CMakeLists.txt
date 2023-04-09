cmake_minimum_required(VERSION 3.17)
project(BSMmodel)

set(CMAKE_CXX_STANDARD 20)

add_executable(BSMmodel main.cpp pricing.h methods.h bintree.h greeks.h option_class.h)