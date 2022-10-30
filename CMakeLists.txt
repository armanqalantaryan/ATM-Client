project(ATM-Client)

cmake_minimum_required(VERSION 3.23)


set(CMAKE_CXX_STANDARD 11)

add_executable(ATM-Client main.cpp ClientSocket/ClientSocket.cpp)
