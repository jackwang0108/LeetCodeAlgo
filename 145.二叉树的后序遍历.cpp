/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
	vector<int> postorderTraversal(TreeNode *root) {
		if (root == nullptr)
			return {};
		processPostOrderTraversal(root);
		return result;
	}

	void processPostOrderTraversal(TreeNode *root) {
		if (root == nullptr)
			return;

		processPostOrderTraversal(root->left);
		processPostOrderTraversal(root->right);
		result.push_back(root->val);
	}
};
// @lc code=end
