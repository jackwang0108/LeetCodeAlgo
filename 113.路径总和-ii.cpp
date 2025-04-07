/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
	vector<int> path;
	vector<vector<int>> allPaths;

public:
	vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
		if (root == nullptr)
			return {};

		processPathSum(root, targetSum);
		return allPaths;
	}

	void processPathSum(TreeNode *root, int leftTargetSum) {
		if (root->left == nullptr && root->right == nullptr) {
			if (leftTargetSum == root->val) {
				path.push_back(root->val);
				allPaths.push_back(path);
				path.pop_back();
			}
		}

		if (root->left) {
			path.push_back(root->val);
			processPathSum(root->left, leftTargetSum - root->val);
			path.pop_back();
		}

		if (root->right) {
			path.push_back(root->val);
			processPathSum(root->right, leftTargetSum - root->val);
			path.pop_back();
		}
	}
};
// @lc code=end
