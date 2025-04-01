/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <cmath>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

using std::tuple;
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
	// 最简单的方法: 中序遍历, 得到的输出序列是升序的
	bool isValidBST(TreeNode *root) {
		if (root == nullptr)
			return true;

		vector<int> result;
		inorderTraversal(result, root);

		for (int i = 0; i < result.size() - 1; i++)
			if (result[i] >= result[i + 1])
				return false;
		return true;
	}

	void inorderTraversal(vector<int> &result, TreeNode *root) {
		if (root == nullptr)
			return;

		inorderTraversal(result, root->left);
		result.push_back(root->val);
		inorderTraversal(result, root->right);
	}

	// 复杂一些的方法, 问左右子树要信息: 左右子树是不是, 左子树最大值和右子树最小值
	bool isValidBST1(TreeNode *root) {
		if (root == nullptr)
			return true;

		return std::get<0>(processIsValidBST(root));
	}

	tuple<bool, double, double> processIsValidBST(TreeNode *root) {
		// 边界条件, 叶子结点
		if (root == nullptr)
			return {true, std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()};

		// 递归
		auto [isLeftBST, leftMin, leftMax] = processIsValidBST(root->left);
		auto [isRightBST, rightMin, rightMax] = processIsValidBST(root->right);

		// 左右子树有一个不是
		if (!isLeftBST || !isRightBST)
			return {false, 0, 0};

		bool isBST = true;
		if (!std::isnan(leftMax))
			isBST = isBST && leftMax < root->val;
		if (!std::isnan(rightMin))
			isBST = isBST && root->val < rightMin;

		return {isBST, std::isnan(leftMin) ? root->val : leftMin, std::isnan(rightMax) ? root->val : rightMax};
	}
};
// @lc code=end


int main() {
	TreeNode *root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	std::cout << Solution().isValidBST(root);
}