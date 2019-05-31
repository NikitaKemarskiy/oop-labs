cmake_minimum_required(VERSION 3.12)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab4 src/cpp/main.cpp src/cpp/Database.cpp src/header/Database.h src/cpp/Table.cpp src/header/Table.h src/cpp/Tree.cpp src/header/Tree.h src/cpp/Node.cpp src/header/Node.h src/cpp/Index.cpp src/header/Index.h libs/cpp/md5.cpp libs/header/md5.h)