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

add_executable(
    297
    "297.二叉树的序列化与反序列化.cpp"
)

add_executable(
    404
    "404.左叶子之和.cpp"
)

add_executable(
    437
    "437.路径总和-iii.cpp"
)

add_executable(
    19
    "19.删除链表的倒数第-n-个结点.cpp"
)

add_executable(
    21
    "21.合并两个有序链表.cpp"
)

add_executable(
    24
    "24.两两交换链表中的节点.cpp"
)

add_executable(
    25
    "25.k-个一组翻转链表.cpp"
)

add_executable(
    61
    "61.旋转链表.cpp"
)

add_executable(
    92
    "92.反转链表-ii.cpp"
)

add_executable(
    109
    "109.有序链表转换二叉搜索树.cpp"
)

add_executable(
    143
    "143.重排链表.cpp"
)

add_executable(
    147
    "147.对链表进行插入排序.cpp"
)

add_executable(
    148
    "148.排序链表.cpp"
)

add_executable(
    160
    "160.相交链表.cpp"
)

add_executable(
    206
    "206.反转链表.cpp"
)

add_executable(
    234
    "234.回文链表.cpp"
)

add_executable(
    71
    "71.简化路径.cpp"
)

add_executable(
    225
    "225.用队列实现栈.cpp"
)

add_executable(
    316
    "316.去除重复字母.cpp"
)

add_executable(
    CD188
    "CD188.单调栈结构(进阶).牛客网.cpp"
)

add_executable(
    907
    "907.子数组的最小值之和.cpp"
)

add_executable(
    HOR4
    "HOR4.大鱼吃小鱼.牛客网.cpp"
)

add_executable(
    28
    "28.找出字符串中第一个匹配项的下标.cpp"
)

add_executable(
    572
    "572.另一棵树的子树.cpp"
)

add_executable(
    67
    "67.二进制求和.cpp"
)

add_executable(
    69
    "69.x-的平方根.cpp"
)

add_executable(
    70
    "70.爬楼梯.cpp"
)

add_executable(
    119
    "119.杨辉三角-ii.cpp"
)

add_executable(
    125
    "125.验证回文串.cpp"
)

add_executable(
    LuoGuP4391
    "LuoGu.P4391.cpp"
)