cmake_minimum_required(VERSION 3.12)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 cpp/main.cpp cpp/Riff.cpp headers/Riff.h cpp/Wav.cpp headers/Wav.h cpp/Fmt.cpp headers/Fmt.h cpp/Data.cpp headers/Data.h cpp/Functions.cpp headers/Functions.h)