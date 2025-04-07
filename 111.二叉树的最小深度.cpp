/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

#include "tree.h"
#include <numeric>

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
	int minDepth(TreeNode *root) {
		if (root == nullptr)
			return 0;

		return processMinDepth(root, 1);
	}

	int processMinDepth(TreeNode *root, int currDepth) {
		if (root->left == nullptr && root->right == nullptr)
			return currDepth;

		int leftDepth = std::numeric_limits<int>::max();
		if (root->left)
			leftDepth = processMinDepth(root->left, currDepth + 1);
		int rightDepth = std::numeric_limits<int>::max();
		if (root->right)
			rightDepth = processMinDepth(root->right, currDepth + 1);

		return std::min(leftDepth, rightDepth);
	}
};
// @lc code=end
