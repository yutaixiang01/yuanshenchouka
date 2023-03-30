cmake_minimum_required(VERSION 3.24)
project(sln)

set(CMAKE_CXX_STANDARD 17)

add_executable(sln DrawCards_sln/main.cpp DrawCards_sln/drawCards.cpp DrawCards_sln/drawCards.h DrawCards_sln/common.h
        DrawCards_sln/drawCards.cpp DrawCards_sln/drawCards.h DrawCards_sln/main.cpp DrawCards_sln/common.h help.cpp)

