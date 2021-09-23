set(EX_1_SOURCES
    main.cpp
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/image_formation)

add_executable(${PROJECT_NAME} ${EX_1_SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} Eigen3::Eigen)