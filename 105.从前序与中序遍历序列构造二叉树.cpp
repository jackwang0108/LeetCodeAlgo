/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include <map>
#include <set>


#include "tree.h"

using std::map;
using std::set;

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
	TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;

		return processBuildTree1(preorder, inorder, 0, 0, inorder.size() - 1);
	}

	TreeNode *processBuildTree1(vector<int> &preorder, vector<int> &inorder, int rootPreOrderIdx, int leftInOrderIdx, int rightInOrderIdx) {
		if (rootPreOrderIdx >= preorder.size() || leftInOrderIdx > rightInOrderIdx)
			return nullptr;

		if (leftInOrderIdx == rightInOrderIdx)
			return new TreeNode(inorder[leftInOrderIdx]);

		// 构建根节点
		int rootVal = preorder[rootPreOrderIdx];
		TreeNode *root = new TreeNode(rootVal);

		// 获得根节点中序遍历的位置
		int rootInOrderIdx;
		set<int> leftNodeVals, rightNodeVals;
		for (int i = leftInOrderIdx; i <= rightInOrderIdx; i++) {
			if (inorder[i] != rootVal) {
				leftNodeVals.insert(inorder[i]);
				continue;
			}
			rootInOrderIdx = i;
			while (i++ < rightInOrderIdx) {
				rightNodeVals.insert(inorder[i]);
			}
			break;
		}

		// 获得左子树和右子树的根节点的位置
		int leftRootIdx = -1, rightRootIdx = -1;
		for (int i = rootPreOrderIdx + 1; i < preorder.size(); i++) {
			if (leftRootIdx == -1 && leftNodeVals.contains(preorder[i]))
				leftRootIdx = i;
			if (rightRootIdx == -1 && rightNodeVals.contains(preorder[i]))
				rightRootIdx = i;
		}


		root->left = processBuildTree1(preorder, inorder, leftRootIdx, leftInOrderIdx, rootInOrderIdx - 1);
		root->right = processBuildTree1(preorder, inorder, rightRootIdx, rootInOrderIdx + 1, rightInOrderIdx);

		return root;
	}

	// 改进:
	// 对于任意一颗树而言，前序遍历的形式总是
	//  [ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
	// 即根节点总是前序遍历中的第一个节点。而中序遍历的形式总是
	//  [ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
	// 因此, 只需要定位到根节点在中序遍历中的位置, 就可以获得左子树的节点数量
	// 在此基础上, 就可以从先序遍历中获得左子树 (根节点Idx+1) 和右子树的根节点 (根节点Idx + 左子树节点数 + 1) 的位置
	// 细节:
	//  1. 中序遍历查找根节点的时候使用一个哈希表加速
	//  2. 中序遍历查找左子树和右子树的根节点的时候利用节点数来加速
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;

		map<int, int> inOrderIndexMap;
		for (int i = 0; i < inorder.size(); i++)
			inOrderIndexMap[inorder[i]] = i;

		return processBuildTree(inOrderIndexMap, preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
	}

	TreeNode *processBuildTree(map<int, int> &inOrderIndexMap, vector<int> &preorder, vector<int> &inorder, int preOrderLeft, int preOrderRight, int inOrderLeft, int inOrderRight) {
		// 边界条件, 如果前序遍历的左边界大于右边界, 说明没有节点了
		if (preOrderLeft > preOrderRight)
			return nullptr;

		// 构建根节点
		int preOrderRoot = preOrderLeft;
		TreeNode *root = new TreeNode(preorder[preOrderRoot]);

		// 计算左子树的节点数
		int inOrderRoot = inOrderIndexMap[preorder[preOrderRoot]];
		int leftNodeCount = inOrderRoot - inOrderLeft;

		root->left = processBuildTree(inOrderIndexMap, preorder, inorder, preOrderLeft + 1, preOrderLeft + leftNodeCount, inOrderLeft, inOrderRoot - 1);
		root->right = processBuildTree(inOrderIndexMap, preorder, inorder, preOrderLeft + leftNodeCount + 1, preOrderRight, inOrderRoot + 1, inOrderRight);

		return root;
	}
};
// @lc code=end


int main() {
	vector<int> preorder{3, 9, 20, 15, 7};
	vector<int> inorder{9, 3, 15, 20, 7};
	cout << Solution().buildTree(preorder, inorder);
}