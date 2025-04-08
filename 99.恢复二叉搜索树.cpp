/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include "tree.h"

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
	void recoverTree(TreeNode *root) {
		if (root == nullptr)
			return;

		// 二叉搜索树中序遍历是一个升序序列
		vector<int *> inorder;
		inorderTraversal(inorder, root);

		// 问题转化为一个升序数组中, 恰有一对元素被交换位置
		// 请你找出这对元素, 并交换它们, 恢复原升序数组
		// 在一个升序数组中，对于所有的i，都有arr[i] <= arr[i+1]。当有一对元素被交换后，这个性质会被破坏。
		// 被交换的两个元素中，较大的那个被放到了前面较小的位置，较小的被放到了后面较大的位置
		// 因此，在数组中会存在两个点i和j，其中arr[i] > arr[i+1]，arr[j] < arr[j-1]。这两个点就是我们要交换的元素。
		int i = 1;
		bool foundSecond = false;
		for (i = 1; i < inorder.size(); i++) {
			if (*inorder[i] > *inorder[i - 1])
				continue;

			int j = i + 1;
			for (j = i + 1; j < inorder.size(); j++) {
				if (*inorder[j] > *inorder[j - 1])
					continue;
				// 找到了第二个点
				foundSecond = true;
				std::swap(*inorder[i - 1], *inorder[j]);
				return;
			}
			if (j == inorder.size())
				break;
		}

		if (!foundSecond)
			std::swap(*inorder[i - 1], *inorder[i]);
	}

	void inorderTraversal(vector<int *> &inorder, TreeNode *root) {
		if (root == nullptr)
			return;

		inorderTraversal(inorder, root->left);
		inorder.push_back(&root->val);
		inorderTraversal(inorder, root->right);
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({3, 1, 4, -1, -1, 2});
	Solution().recoverTree(root);
}