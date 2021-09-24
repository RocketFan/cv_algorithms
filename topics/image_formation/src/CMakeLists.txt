cmake_minimum_required(VERSION 3.16.3)

# Add exercise exectuables to bin/<project_name> folder to show results
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME})
add_executable(ex_1
    ex_1.cpp
    least_squares_basic.cpp
)

target_link_libraries(ex_1 ${OpenCV_LIBS} Eigen3::Eigen)