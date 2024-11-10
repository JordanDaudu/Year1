cmake_minimum_required(VERSION 3.27)
project(S_2_ProjectAssignment3_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(S_2_ProjectAssignment3_2 main.cpp
        Worker.cpp
        Worker.h
        Teacher.cpp
        Teacher.h
        Course.cpp
        Course.h
        Researcher.cpp
        Researcher.h
        Article.cpp
        Article.h
        Lecturer.cpp
        Lecturer.h)
