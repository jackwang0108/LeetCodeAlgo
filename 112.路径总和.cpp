/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
	bool hasPathSum(TreeNode *root, int targetSum) {
		if (root == nullptr)
			return false;

		return processHasPathSum(root, targetSum);
	}

	bool processHasPathSum(TreeNode *root, int leftTargetSum) {
		if (root->left == nullptr && root->right == nullptr)
			return leftTargetSum - root->val == 0;

		bool leftAnswer = false;
		if (root->left)
			leftAnswer = processHasPathSum(root->left, leftTargetSum - root->val);
		bool rightAnswer = false;
		if (root->right)
			rightAnswer = processHasPathSum(root->right, leftTargetSum - root->val);

		return leftAnswer || rightAnswer;
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1});
	Solution().hasPathSum(root, 22);
}