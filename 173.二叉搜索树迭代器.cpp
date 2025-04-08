/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
	int curr = 0;
	// Mirrors 遍历更节省空间
	vector<TreeNode *> inorder;

public:
	BSTIterator(TreeNode *root) {
		inorderTraversal(root);
	}

	void inorderTraversal(TreeNode *root) {
		if (root == nullptr)
			return;
		inorderTraversal(root->left);
		inorder.push_back(root);
		inorderTraversal(root->right);
	}

	int next() {
		return inorder[curr++]->val;
	}

	bool hasNext() {
		return curr < inorder.size();
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
