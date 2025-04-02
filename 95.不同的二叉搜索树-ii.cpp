/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

#include <vector>

using std::vector;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		if (n == 0)
			return {};

		return processGenerateTrees(1, n);
	}

	// 傻逼了, 树的问题就是问左右子树要信息, 综合处理之后再给出自己的信息
	vector<TreeNode *> processGenerateTrees(int left, int right) {
		// 叶子结点
		if (left > right)
			return {nullptr};

		vector<TreeNode *> allTrees;
		for (int rootIdx = left; rootIdx <= right; rootIdx++) {
			// 问左右子树要信息, 就是左右可行的子树数量
			vector<TreeNode *> allLeftTrees = processGenerateTrees(left, rootIdx - 1);
			vector<TreeNode *> allRightTrees = processGenerateTrees(rootIdx + 1, right);

			// 左右子树拼接起来, 获得自己的信息
			for (TreeNode *leftTree: allLeftTrees)
				for (TreeNode *rightTree: allRightTrees) {
					TreeNode *newNode = new TreeNode(rootIdx, leftTree, rightTree);
					allTrees.push_back(newNode);
				}
		}

		return allTrees;
	}
};
// @lc code=end
