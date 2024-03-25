    cmake_minimum_required(VERSION 3.23)
    project(tablica_dynamiczna)

    set(CMAKE_CXX_STANDARD 20)

    add_executable(tablica_dynamiczna main.cpp dynamicArray.cpp Zapis.cpp test.cpp)
