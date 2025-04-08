/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

#include <stack>

#include "tree.h"

using std::stack;

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
	vector<TreeNode *> inorder;

public:
	void flatten(TreeNode *root) {
		if (root == nullptr)
			return;
		processFlatten(root);

		for (int i = 0; i < inorder.size() - 1; i++) {
			inorder[i]->left = nullptr;
			inorder[i]->right = inorder[i + 1];
		}
	}

	void processFlatten(TreeNode *root) {
		if (root == nullptr)
			return;

		inorder.push_back(root);
		processFlatten(root->left);
		processFlatten(root->right);
	}
};
// @lc code=end
