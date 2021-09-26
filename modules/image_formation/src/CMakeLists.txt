cmake_minimum_required(VERSION 3.16.3)

# Add exercise exectuables to bin/<project_name> folder to show results
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME})

add_executable(ex_1
    ex_1.cpp
    least_squares_basic.cpp
)

target_link_libraries(ex_1 
    PRIVATE matplotlib_cpp 
    PRIVATE algebra_ext 
    PRIVATE Eigen3::Eigen
)
target_include_directories(ex_1 PRIVATE "${CMAKE_SOURCE_DIR}/lib/matplotlib_cpp")

set_target_properties(ex_1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}")