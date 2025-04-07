/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

#include <utility>

#include "tree.h"

using std::pair;

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
	bool isBalanced(TreeNode *root) {
		if (root == nullptr)
			return true;
		return processIsBalanced(root).first;
	}

	pair<bool, int> processIsBalanced(TreeNode *root) {
		if (root == nullptr)
			return {true, 0};

		pair<bool, int> left = processIsBalanced(root->left);
		pair<bool, int> right = processIsBalanced(root->right);

		return {
		    left.first &&
		        right.first &&
		        std::abs(left.second - right.second) <= 1,
		    std::max(left.second, right.second) + 1};
	}
};
// @lc code=end
