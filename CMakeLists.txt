cmake_minimum_required(VERSION 3.7)
project(bananapim20-gpio VERSION 0.1)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
    src/bananapim20-gpio.c
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ./include
)