cmake_minimum_required(VERSION 3.20)
project(Bank_Management_Simulator)

set(CMAKE_CXX_STANDARD 14)

set(Headers User.h HashTable.h Tester.h Simulator.h)

add_executable(Bank_Management_Simulator ${PROJECT_SOURCE_DIR}/ main.cpp User.cpp HashTable.cpp Tester.cpp Simulator.cpp)
