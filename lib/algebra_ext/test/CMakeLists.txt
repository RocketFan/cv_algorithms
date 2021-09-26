cmake_minimum_required(VERSION 3.16.3)

set(TEST_NAME ${PROJECT_NAME}_test)

set(SOURCES
    eigen_ext_test.cpp
    line_ext_test.cpp
)

add_executable(${TEST_NAME} ${SOURCES})
target_link_libraries(${TEST_NAME} PUBLIC
    gtest_main
    ${PROJECT_NAME}
)

add_test(
    NAME ${TEST_NAME}
    COMMAND ${TEST_NAME}
)