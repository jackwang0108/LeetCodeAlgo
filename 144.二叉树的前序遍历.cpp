/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include "tree.h"

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
	vector<int> result;

public:
	vector<int> preorderTraversal(TreeNode *root) {
		if (root == nullptr)
			return {};

		processPreOrderTraversal(root);
		return result;
	}

	void processPreOrderTraversal(TreeNode *root) {
		if (root == nullptr)
			return;

		result.push_back(root->val);
		processPreOrderTraversal(root->left);
		processPreOrderTraversal(root->right);
	}
};
// @lc code=end
