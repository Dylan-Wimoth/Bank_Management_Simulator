cmake_minimum_required(VERSION 3.20)
project(Bank_Management_Simulator)

set(CMAKE_CXX_STANDARD 14)

set(Headers User.h Database.h)

add_executable(Bank_Management_Simulator ${PROJECT_SOURCE_DIR}/ main.cpp User.cpp Database.cpp)
