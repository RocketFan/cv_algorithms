cmake_minimum_required(VERSION 3.16.3)

project(eigen_ext CXX)

add_library(${PROJECT_NAME} STATIC include/eigen_ext.h)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)