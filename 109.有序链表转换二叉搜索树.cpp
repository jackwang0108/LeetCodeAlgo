/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

#include "linkedlist.h"
#include "tree.h"

#include <vector>

using std::vector;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == nullptr)
			return nullptr;

		vector<int> nums;
		while (head != nullptr)
			nums.push_back(head->val), head = head->next;

		return buildBST(nums, 0, nums.size() - 1);
	}


	TreeNode *buildBST(const vector<int> &vec, int left, int right) {
		if (left > right)
			return nullptr;

		int mid = left + (right - left) / 2;
		TreeNode *root = new TreeNode(vec[mid]);
		root->left = buildBST(vec, left, mid - 1);
		root->right = buildBST(vec, mid + 1, right);
		return root;
	}
};
// @lc code=end

int main() {
	ListNode *head = buildLinkedList({-10, -3, 0, 5, 9});
	TreeNode *root = Solution().sortedListToBST(head);
	cout << root;
	return 0;
}
