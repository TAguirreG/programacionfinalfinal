cmake_minimum_required(VERSION 3.24)
project(ucc_2023_trabajo_final)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(trabajo_final main.cpp banco.cpp Banco.h cliente.h transaccion.h cliente.cpp transaccion.cpp)
