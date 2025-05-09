/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
public:
	TreeNode *invertTree(TreeNode *root) {
		if (root == nullptr)
			return nullptr;

		TreeNode *invertedLeft = invertTree(root->left);
		TreeNode *invertedRight = invertTree(root->right);

		root->left = invertedRight;
		root->right = invertedLeft;
		return root;
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({4, 7, 2, 9, 6, 3, 1});
	root = Solution().invertTree(root);
	cout << root;
	return 0;
}