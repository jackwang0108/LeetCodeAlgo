/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

#include "tree.h"

#include <stack>

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
public:
	int sumOfLeftLeaves1(TreeNode *root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return 0;

		stack<TreeNode *> nodeStack;
		nodeStack.push(root);

		int result = 0;
		TreeNode *curr, *prev;
		while (!nodeStack.empty()) {
			(curr = nodeStack.top(), nodeStack.pop());

			// 需要提前一步判断
			if (curr->left != nullptr) {
				if (curr->left->left == nullptr && curr->left->right == nullptr)
					result += curr->left->val;
				else
					nodeStack.push(curr->left);
			}

			if (curr->right != nullptr)
				if (curr->right->left != nullptr || curr->right->right != nullptr)
					nodeStack.push(curr->right);
		}

		return result;
	}

	int result = 0;

	int sumOfLeftLeaves(TreeNode *root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return 0;
		processSumOfLeaves(root, false);
		return result;
	}

	void processSumOfLeaves(TreeNode *root, bool isLeft) {
		if (root->left == nullptr && root->right == nullptr) {
			result += isLeft ? root->val : 0;
			return;
		}

		if (root->left != nullptr)
			processSumOfLeaves(root->left, true);
		if (root->right != nullptr)
			processSumOfLeaves(root->right, false);
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({1, 2});
	cout << root;
	cout << Solution().sumOfLeftLeaves(root);
}