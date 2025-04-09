/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

#include "tree.h"

#include <string>

using std::string;

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
	vector<string> paths;

public:
	vector<string> binaryTreePaths(TreeNode *root) {
		if (root == nullptr)
			return {};
		processBinaryTreePaths(root, "");

		return paths;
	}

	void processBinaryTreePaths(TreeNode *root, string prevPath) {
		prevPath += "->" + std::to_string(root->val);


		if (root->left == nullptr && root->right == nullptr) {
			paths.push_back(prevPath.substr(2));
			return;
		}

		if (root->left)
			processBinaryTreePaths(root->left, prevPath);
		if (root->right)
			processBinaryTreePaths(root->right, prevPath);
	}
};
// @lc code=end
