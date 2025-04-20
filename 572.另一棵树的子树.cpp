/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

#include "tree.h"

#include <numeric>


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
	// 递归解法, 每个头试一下, 复杂度 O(m*n)
	bool isSubtree1(TreeNode *root, TreeNode *subRoot) {
		// 因为isSubtree也是递归的, 所以也要考虑边界条件
		if (root != nullptr && subRoot != nullptr)
			return isSame(root, subRoot) ||
			       isSubtree1(root->left, subRoot) ||
			       isSubtree1(root->right, subRoot);
		// 要么root已经走到叶子节点, 要么subRoot直接为空
		return subRoot == nullptr;
	}

	// 递归
	bool isSame(TreeNode *root, TreeNode *subRoot) {
		// 叶子结点
		if (root == nullptr && subRoot == nullptr)
			return true;

		if (root != nullptr && subRoot != nullptr)
			return root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);

		return false;
	}

	// 聪明的做法, 直接 kmp 匹配
	// 树对应的先序遍历结果唯一, 所以如果是子树, 那么先序遍历结果中一定包含子树的结果
	// 先序遍历是 O(m) + O(n), kmp 匹配是 O(m+n)
	// 所以最终是 O(m+n)
	vector<int> rootPreOrder, subRootPreOrder;
	bool isSubtree(TreeNode *root, TreeNode *subRoot) {
		preOrderTraversal(root, rootPreOrder);
		preOrderTraversal(subRoot, subRootPreOrder);

		return kmp(rootPreOrder, subRootPreOrder);
	}

	bool kmp(const vector<int> &rootPreOrder, const vector<int> &subRootPreOrder) {
		vector<int> next = getNext(subRootPreOrder);

		int i = 0, j = 0;
		while (i < rootPreOrder.size() && j < subRootPreOrder.size()) {
			if (rootPreOrder[i] == subRootPreOrder[j])
				i++, j++;
			else if (j == 0)
				i++;
			else
				j = next[j];
		}

		return j == subRootPreOrder.size();
	}

	vector<int> getNext(const vector<int> &preOrder) {
		vector<int> next(preOrder.size(), 0);
		next[0] = -1;
		next[1] = 0;

		int i = 2, cn = 0;
		while (i < preOrder.size()) {
			if (preOrder[i - 1] == preOrder[cn])
				next[i++] = ++cn;
			else if (cn > 0)
				cn = next[cn];
			else
				next[i++] = 0;
		}

		return next;
	}

	void preOrderTraversal(TreeNode *root, vector<int> &preOrder) {
		if (root == nullptr) {
			preOrder.push_back(std::numeric_limits<int>::min());
			return;
		}

		preOrder.push_back(root->val);
		preOrderTraversal(root->left, preOrder);
		preOrderTraversal(root->right, preOrder);
	}
};
// @lc code=end

int main() {
	TreeNode *root = buildTreeFromLevelOrder({3, 4, 5, 1, 2, -1, -1, -1, -1, 0});
	TreeNode *subRoot = buildTreeFromLevelOrder({4, 1, 2});

	cout << Solution().isSubtree1(root, subRoot) << "\n";
}
