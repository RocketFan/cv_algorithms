cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cv_algorithms)

enable_testing()
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_subdirectory(lib)
add_subdirectory(modules)
add_subdirectory(app)