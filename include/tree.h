#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::map;
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

/**
 * @brief 根据层序遍历的结果构建二叉树
 * 
 * @param vec 层序遍历的结果, -1表示空节点
 * @param currIdx 当前节点的索引
 * @return 构建好的二叉树的根节点
 * 
 * @note 该函数是递归的, 需要传入当前节点的索引
 */
TreeNode *processBuildTreeFromLevelOrder(const vector<int> &vec, int currIdx = 0) {
	if (currIdx >= vec.size())
		return nullptr;

	if (vec[currIdx] == -1)
		return nullptr;

	TreeNode *root = new TreeNode(vec[currIdx]);
	root->left = processBuildTreeFromLevelOrder(vec, 2 * currIdx + 1);
	root->right = processBuildTreeFromLevelOrder(vec, 2 * currIdx + 2);
	return root;
}

/**
 * @brief 根据层序遍历的结果构建二叉树
 * 
 * @param vec 层序遍历的结果, -1表示空节点
 * @return 构建好的二叉树的根节点
 */
TreeNode *buildTreeFromLevelOrder(const vector<int> &vec) {
	return processBuildTreeFromLevelOrder(vec, 0);
}

/**
 * @brief 根据先序遍历和中序遍历的结果构建二叉树
 * 
 * @param inOrderIndexMap 中序遍历的结果和索引的映射
 * @param preorder 先序遍历的结果
 * @param preOrderLeft 先序遍历的左边界
 * @param preOrderRight 先序遍历的右边界
 * @param inorder 中序遍历的结果
 * @param inOrderLeft 中序遍历的左边界
 * @param inOrderRight 中序遍历的右边界
 * @return 构建好的二叉树的根节点
 * 
 * @note 该函数是递归的, 需要传入当前先序遍历和中序遍历左右子树的边界
 */
TreeNode *processBuildTreeFromPreAndInOrder(map<int, int> &inOrderIndexMap, const vector<int> &preorder, int preOrderLeft, int preOrderRight, const vector<int> &inorder, int inOrderLeft, int inOrderRight) {
	// 边界条件, 如果前序遍历的左边界大于右边界, 说明没有节点了
	if (preOrderLeft > preOrderRight)
		return nullptr;

	// 构建根节点
	int preOrderRoot = preOrderLeft;
	TreeNode *root = new TreeNode(preorder[preOrderRoot]);

	// 计算左子树的节点数
	int inOrderRoot = inOrderIndexMap[preorder[preOrderRoot]];
	int leftNodeCount = inOrderRoot - inOrderLeft;

	root->left = processBuildTreeFromPreAndInOrder(inOrderIndexMap, preorder, preOrderLeft + 1, preOrderLeft + leftNodeCount, inorder, inOrderLeft, inOrderRoot - 1);
	root->right = processBuildTreeFromPreAndInOrder(inOrderIndexMap, preorder, preOrderLeft + leftNodeCount + 1, preOrderRight, inorder, inOrderRoot + 1, inOrderRight);

	return root;
}

/**
 * @brief 根据先序遍历和中序遍历的结果构建二叉树
 * 
 * @param preorder 先序遍历的结果
 * @param inorder 中序遍历的结果
 * @return 构建好的二叉树的根节点
 */
TreeNode *buildTreeFromPreAndInOrder(const vector<int> &preorder, const vector<int> &inorder) {
	if (preorder.empty() || inorder.empty())
		return nullptr;

	map<int, int> inOrderIndexMap;
	for (int i = 0; i < inorder.size(); i++)
		inOrderIndexMap[inorder[i]] = i;

	return processBuildTreeFromPreAndInOrder(inOrderIndexMap, preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

/**
 * @brief 从中序遍历和后序遍历的结果构建二叉树
 * 
 * @param inOrderIndexMap 中序遍历的结果和索引的映射
 * @param inorder 中序遍历的结果
 * @param inStart 中序遍历的左边界
 * @param inEnd 中序遍历的右边界
 * @param postorder 后序遍历的结果
 * @param postStart 后序遍历的左边界
 * @param postEnd 后序遍历的右边界
 * @return 构建好的二叉树的根节点
 * 
 * @note 该函数是递归的, 需要传入当前中序遍历和后序遍历左右子树的边界
 */
TreeNode *processBuildTreeFromInAndPostOrder(map<int, int> &inOrderIndexMap, const vector<int> &inorder, int inStart, int inEnd, const vector<int> &postorder, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd)
		return nullptr;

	int rootVal = postorder[postEnd];
	TreeNode *root = new TreeNode(rootVal);

	int inOrderRoot = inOrderIndexMap[rootVal];
	int leftNumNodes = inOrderRoot - inStart;

	root->left = processBuildTreeFromInAndPostOrder(inOrderIndexMap, inorder, inStart, inOrderRoot - 1, postorder, postStart, postStart + leftNumNodes - 1);
	root->right = processBuildTreeFromInAndPostOrder(inOrderIndexMap, inorder, inOrderRoot + 1, inEnd, postorder, postStart + leftNumNodes, postEnd - 1);

	return root;
}

/**
 * @brief 从中序遍历和后序遍历的结果构建二叉树
 * 
 * @param inorder 中序遍历的结果
 * @param postorder 后序遍历的结果
 * @return 构建好的二叉树的根节点
 */
TreeNode *buildTreeFromInAndPostOrder(vector<int> &inorder, vector<int> &postorder) {
	if (inorder.empty() || postorder.empty())
		return nullptr;

	if (inorder.size() != postorder.size())
		return nullptr;

	map<int, int> inMap;
	for (int i = 0; i < inorder.size(); ++i)
		inMap[inorder[i]] = i;

	return processBuildTreeFromInAndPostOrder(inMap, inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}