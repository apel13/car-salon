cmake_minimum_required(VERSION 3.10)

project(car-salon)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        "./sources" ,
        "./sources/Car" ,
        "./sources/Catalog" ,
        "./sources/Commands" ,
        "./sources/Customer" ,
        "./sources/Salon"
)

add_executable(car-salon
        main.cpp
        sources/Car/car.cpp
        sources/Catalog/catalog.cpp
        sources/Commands/commands.cpp
        sources/Customer/customer.cpp
        sources/Salon/salon.cpp
        )