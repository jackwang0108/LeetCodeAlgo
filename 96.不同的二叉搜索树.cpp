/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <iostream>
#include <set>
#include <vector>

using std::cout;
using std::vector;

// @lc code=start
class Solution {
public:
	// 数学的解法
	int numTrees1(int n) {
		if (n == 0)
			return n;

		// 王道书上讲过的卡特兰数
		// C0 = 1, Cn+1 = 2(2n + 1) / (n + 2) * Cn
		// C1 = 1, C2 = 2, C3 = 5
		// Cn = 2(2n - 1) / (n + 1) * Cn-1
		return calculate(n);
	}

	long long calculate(long n) {
		if (n == 1)
			return 1;
		return 2 * (2 * n - 1) * calculate(n - 1) / (n + 1);
	}


	// 递归的解法
	// 二叉搜索树的中序遍历得到的就是一个递增序列
	// [1, 2, 3, 4, 5, 6, 7]
	// 所以这个序列就是所有二叉搜索树中序遍历输出的结果
	// 在这个基础上, 每次用i节点作为根节点, i节点左边的就是左子树中序遍历输出的结果, 右边就是右子树中序遍历输出的结果
	int numTrees(int n) {
		if (n == 0 || n == 1)
			return n;

		return (int) processNumTrees(n, 0, n - 1);
	}

	long processNumTrees(int n, int left, int right) {
		// 边界条件
		if (left >= right)
			return 1;

		long sum = 0;
		for (int rootIdx = left; rootIdx <= right; rootIdx++) {
			// 左子树的种类数量 * 右子树的种类数量
			sum += processNumTrees(n, left, rootIdx - 1) * processNumTrees(n, rootIdx + 1, right);
		}

		return sum;
	}
};
// @lc code=end


int main() {
	cout << Solution().numTrees(3);
}