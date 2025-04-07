#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::ostream;
using std::string;
using std::vector;


/**
 * @brief leetcode的二叉树节点定义
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printTree(const string &prefix, const TreeNode *root, bool isLeft, bool hasRightBrother = true) {
	if (root == nullptr)
		return;

	cout << prefix;
	cout << (isLeft && hasRightBrother ? "├──" : "└──");
	cout << root->val << (isLeft ? " (L) " : " (R) ") << "\n";

	printTree(prefix + (isLeft && hasRightBrother ? "│   " : "    "), root->left, true, root->right != nullptr);
	printTree(prefix + (isLeft && hasRightBrother ? "│   " : "    "), root->right, false, root->right != nullptr);
}

ostream &operator<<(ostream &os, TreeNode *root) {
	os << "Tree:\n";
	printTree("", root, false, root->right != nullptr);
	return os;
}

TreeNode *buildTree(const vector<int> &vec, int currIdx = 0) {
	if (currIdx >= vec.size())
		return nullptr;

	if (vec[currIdx] == -1)
		return nullptr;

	TreeNode *root = new TreeNode(vec[currIdx]);
	root->left = buildTree(vec, 2 * currIdx + 1);
	root->right = buildTree(vec, 2 * currIdx + 2);
	return root;
}