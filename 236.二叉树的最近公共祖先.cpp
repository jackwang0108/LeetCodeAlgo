/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include "tree.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		if (root == nullptr)
			return nullptr;

		TreeNode *leftCommonAncestor = lowestCommonAncestor(root->left, p, q);
		TreeNode *rightCommonAncestor = lowestCommonAncestor(root->right, p, q);

		// 左右子树直接没有这两个节点
		if (leftCommonAncestor == nullptr && rightCommonAncestor == nullptr)
			return (root->val == p->val || root->val == q->val) ? root : nullptr;

		// 左右子树有一个节点
		bool hasNull = leftCommonAncestor == nullptr || rightCommonAncestor == nullptr;
		bool hasNotNull = leftCommonAncestor != nullptr || rightCommonAncestor != nullptr;
		if (hasNull && hasNotNull)
			// 如果自己是另外一个节点, 就返回自己
			return root->val == p->val || root->val == q->val ? root : (leftCommonAncestor == nullptr ? rightCommonAncestor : leftCommonAncestor);

		// 两个节点分别在左右两个子树
		bool isOneInLeft = leftCommonAncestor->val == p->val || leftCommonAncestor->val == q->val;
		bool isOneInRight = rightCommonAncestor->val == p->val || rightCommonAncestor->val == q->val;
		if (isOneInLeft && isOneInRight)
			return root;

		return nullptr;
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});

	Solution().lowestCommonAncestor(root, new TreeNode(5), new TreeNode(4));

	return 0;
}