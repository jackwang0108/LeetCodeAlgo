/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include <iostream>
#include <numeric>
#include <vector>

#include "tree.h"

using std::cout;
using std::vector;


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
	// 检查中序遍历是否是一个回文子串即可, 能过195个case
	bool isSymmetric1(TreeNode *root) {
		vector<int> result;
		inorderTraversal(result, root);

		int left = 0, right = result.size() - 1;
		while (left < right)
			if (result[left++] != result[right--])
				return false;

		return true;
	}


	void inorderTraversal(vector<int> &vec, TreeNode *root) {
		if (root == nullptr) {
			vec.push_back(std::numeric_limits<int>::min());
			return;
		}

		inorderTraversal(vec, root->left);
		vec.push_back(root->val);
		inorderTraversal(vec, root->right);
	}

	// 递归翻转, 然后检查左右子树是否相同, 复杂度比较高, 因为递归了两次
	bool isSymmetric2(TreeNode *root) {
		TreeNode *flippedRoot = flip(root);

		return isSameTree(root, flippedRoot);
	}


	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == nullptr || q == nullptr)
			return p == nullptr && q == nullptr;

		bool isLeftSame = isSameTree(p->left, q->left);
		bool isRightSame = isSameTree(p->right, q->right);
		return isLeftSame && isRightSame && p->val == q->val;
	}

	TreeNode *flip(TreeNode *root) {
		if (root == nullptr)
			return nullptr;

		TreeNode *flippedRoot = new TreeNode(root->val);
		flippedRoot->left = flip(root->right);
		flippedRoot->right = flip(root->left);
		return flippedRoot;
	}

	// 更好的思路是双指针
	bool isSymmetric(TreeNode *root) {
		if (root == nullptr)
			return true;

		return processIsSymmetric(root->left, root->right);
	}

	bool processIsSymmetric(TreeNode *left, TreeNode *right) {
		if (left == nullptr && right == nullptr)
			return true;
		if (left == nullptr || right == nullptr)
			return false;

		return left->val == right->val && processIsSymmetric(left->left, right->right) && processIsSymmetric(left->right, right->left);
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({1, 2, 2, -1, 3, -1, 3});

	cout << root;
	cout << std::boolalpha << Solution().isSymmetric2(root);
}
