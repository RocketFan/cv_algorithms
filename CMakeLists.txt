cmake_minimum_required(VERSION 3.16.3)

project(cv_algorithms)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

add_subdirectory(libs)
add_subdirectory(topics)
