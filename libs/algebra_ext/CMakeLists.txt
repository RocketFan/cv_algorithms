cmake_minimum_required(VERSION 3.16.3)

project(algebra_ext CXX)

set(INCLUDE_DIR include/${PROJECT_NAME})
set(SOURCES_DIR src)

set(HEADERS
    ${INCLUDE_DIR}/line_ext.h
    ${INCLUDE_DIR}/eigen_ext.h
)

set(SOURCES
    ${SOURCES_DIR}/line_ext.cpp
    ${SOURCES_DIR}/eigen_ext.tpp
)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)