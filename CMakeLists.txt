cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(
    LeetCode算法
    VERSION 0.1
    DESCRIPTION "LeetCode刷题时候的代码"
    LANGUAGES CXX
)

set(CMAKE_C_STANDARD 20)
set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(
    2
    "2.两数相加.cpp"
)

add_executable(
    3
    "3.无重复字符的最长子串.cpp"
)
