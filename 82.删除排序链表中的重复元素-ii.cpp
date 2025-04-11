/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

#include "linkedlist.h"

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
class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr)
			return head;

		ListNode *dummy = new ListNode(0, head);
		ListNode *curr = dummy;
		while (curr->next && curr->next->next) {
			if (curr->next->val == curr->next->next->val) {
				int duplicated = curr->next->val;
				while (curr->next && curr->next->val == duplicated)
					curr->next = curr->next->next;
			} else {
				curr = curr->next;
			}
		}
		return dummy->next;
	}
};
// @lc code=end
