cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(image_formation)

set(INCLUDE_DIR include/${PROJECT_NAME})
set(SOURCE_DIR src)

set(HEADERS
    ${INCLUDE_DIR}/least_squares_basic.h
)

set(SOURCES
    ${SOURCE_DIR}/least_squares_basic.cpp
)

# Add library
add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC Eigen3::Eigen algebra_ext)

# Add executables
include_directories(include)
add_subdirectory(src)

# Setup tests
enable_testing()
add_subdirectory(test)