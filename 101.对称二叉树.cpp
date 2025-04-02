/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include <iostream>
#include <numeric>
#include <vector>

using std::cout;
using std::vector;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

	// 递归翻转, 然后检查是否和自己相同
	bool isSymmetric(TreeNode *root) {
		TreeNode *flippedRoot = flip(root);

		return isSameTree(root, flippedRoot);
	}


	bool isSameTree(TreeNode *p, TreeNode *q) {
		if (p == nullptr || q == nullptr)
			if (!(p == nullptr && q == nullptr))
				return false;
			else
				return true;

		bool isLeftSame = isSameTree(p->left, q->left);
		bool isRightSame = isSameTree(p->right, q->right);
		return isLeftSame && isRightSame && p->val == q->val;
	}

	TreeNode *flip(TreeNode *root) {
		if (root == nullptr)
			return nullptr;

		TreeNode *flippedRoot = new TreeNode(root->val);
		flippedRoot->left = flip(root->left);
		flippedRoot->right = flip(root->right);
		return flippedRoot;
	}
};
// @lc code=end

TreeNode *buildTree(const vector<int> &vec, int currIdx) {
	if (currIdx >= vec.size())
		return nullptr;

	if (vec[currIdx] == -1)
		return nullptr;

	TreeNode *root = new TreeNode(vec[currIdx]);
	root->left = buildTree(vec, 2 * currIdx + 1);
	root->right = buildTree(vec, 2 * currIdx + 2);
	return root;
}

int main() {
	TreeNode *root = buildTree({1, 2, 2, 2, -1, 2}, 0);

	cout << std::boolalpha << Solution().isSymmetric(root);
}
