cmake_minimum_required(VERSION 4.2)
project(project_2___TobaccoShop)

set(CMAKE_CXX_STANDARD 20)

add_executable(project_2___TobaccoShop main.cpp
        Product.h
        Product.cpp
        Vape.h
        Vape.cpp
        Cigarettes.h
        Cigarettes.cpp
        Snus.h
        Snus.cpp
        Customer.h
        Customer.cpp
        Exceptions.h)
