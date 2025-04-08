/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
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
	int k;
	int result;

public:
	int kthSmallest(TreeNode *root, int k) {
		this->k = k;
		processKthSmallest(root);
		return result;
	}

	void processKthSmallest(TreeNode *root) {
		if (k == 0)
			return;

		if (root->left)
			processKthSmallest(root->left);

		k -= 1;
		if (k == 0) {
			result = root->val;
			return;
		}

		if (root->right)
			processKthSmallest(root->right);
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({1, -1, 2});
	cout << Solution().kthSmallest(root, 2);
	return 0;
}