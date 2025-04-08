/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

#include <map>

#include "tree.h"

using std::map;

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
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.empty() || postorder.empty())
			return nullptr;

		if (inorder.size() != postorder.size())
			return nullptr;

		map<int, int> inMap;
		for (int i = 0; i < inorder.size(); ++i)
			inMap[inorder[i]] = i;

		return processBuildTree(inMap, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}


	TreeNode *processBuildTree(map<int, int> &inMap, vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
		if (inStart > inEnd || postStart > postEnd)
			return nullptr;

		int rootVal = postorder[postEnd];
		TreeNode *root = new TreeNode(rootVal);

		int inOrderRoot = inMap[rootVal];
		int leftNumNodes = inOrderRoot - inStart;

		root->left = processBuildTree(inMap, inorder, inStart, inOrderRoot - 1, postorder, postStart, postStart + leftNumNodes - 1);
		root->right = processBuildTree(inMap, inorder, inOrderRoot + 1, inEnd, postorder, postStart + leftNumNodes, postEnd - 1);

		return root;
	}
};
// @lc code=end


int main() {
	vector<int> inorder = {9, 3, 15, 20, 7};
	vector<int> postorder = {9, 15, 7, 20, 3};
	TreeNode *root = Solution().buildTree(inorder, postorder);
	cout << root;
	return 0;
}