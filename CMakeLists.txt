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

include_directories(${PROJECT_SOURCE_DIR}/include)

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

add_executable(
    99
    "99.恢复二叉搜索树.cpp"
)

add_executable(
    103
    "103.二叉树的锯齿形层序遍历.cpp"
)

add_executable(
    105
    "105.从前序与中序遍历序列构造二叉树.cpp"
)

add_executable(
    112
    "112.路径总和.cpp"
)

add_executable(
    106
    "106.从中序与后序遍历序列构造二叉树.cpp"
)

add_executable(
    116
    "116.填充每个节点的下一个右侧节点指针.cpp"
)

add_executable(
    129
    "129.求根节点到叶节点数字之和.cpp"
)

add_executable(
    226
    "226.翻转二叉树.cpp"
)

add_executable(
    230
    "230.二叉搜索树中第-k-小的元素.cpp"
)

add_executable(
    235
    "235.二叉搜索树的最近公共祖先.cpp"
)

add_executable(
    236
    "236.二叉树的最近公共祖先.cpp"
)