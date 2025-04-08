/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
	int results = 0;

public:
	int sumNumbers(TreeNode *root) {
		if (root == nullptr)
			return 0;
		processSumNumbers(root, 0);
		return results;
	}

	void processSumNumbers(TreeNode *root, int prevNum) {
		int currNum = prevNum * 10 + root->val;

		if (root->left == nullptr && root->right == nullptr) {
			results += currNum;
			return;
		}

		if (root->left)
			processSumNumbers(root->left, currNum);
		if (root->right)
			processSumNumbers(root->right, currNum);
	}
};
// @lc code=end

int main() {
	TreeNode *root = buildTreeFromLevelOrder({1, 2, 3});
	cout << Solution().sumNumbers(root);
}
