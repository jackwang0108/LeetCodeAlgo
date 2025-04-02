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

add_executable(
    4
    "4.寻找两个正序数组的中位数.cpp"
)


add_executable(
    76
    "76.最小覆盖子串.cpp"
)

add_executable(
    98
    "98.验证二叉搜索树.cpp"
)

add_executable(
    96
    "96.不同的二叉搜索树.cpp"
)

add_executable(
    101
    "101.对称二叉树.cpp"
)