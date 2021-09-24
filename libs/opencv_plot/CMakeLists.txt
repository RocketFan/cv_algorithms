cmake_minimum_required(VERSION 3.16.3)

project(opencv_plot)

set(INCLUDE_DIR include/opencv_plot)
set(SOURCE_DIR src)

set(HEADERS
    ${INCLUDE_DIR}/plot.h
)

set(SOURCES
    ${SOURCE_DIR}/plot.cpp
)

add_library(${PROJECT_NAME} STATIC 
    ${SOURCES}
    ${HEADERS}
)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
