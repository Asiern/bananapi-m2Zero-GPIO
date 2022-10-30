cmake_minimum_required(VERSION 3.7)
project(bananapim20-gpio VERSION 0.1)

set(SOURCE_FILES
	src/bpi-m2-0.c
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} 
    PRIVATE
    ./include
)
