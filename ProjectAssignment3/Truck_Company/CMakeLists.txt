cmake_minimum_required(VERSION 3.27)
project(S_2_ProjectAssignment3_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(S_2_ProjectAssignment3_1 main.cpp
        Employee.cpp
        Employee.h
        Mechanic.cpp
        Mechanic.h
        Driver.cpp
        Driver.h
        Director.cpp
        Director.h
        Delivery.cpp
        Delivery.h)
