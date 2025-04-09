/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

		if (p->val == root->val || q->val == root->val)
			return root;

		TreeNode *less = p->val < q->val ? p : q;
		TreeNode *greater = p->val > q->val ? p : q;
		if (less->val < root->val && root->val < greater->val)
			return root;

		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		return left == nullptr ? right : left;
	}
};
// @lc code=end

int main() {
	TreeNode *root = buildTreeFromLevelOrder({2, 1, 3});
	TreeNode *p = new TreeNode(1);
	TreeNode *q = new TreeNode(3);
	Solution().lowestCommonAncestor(root, p, q);

	return 0;
}
