/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
	ListNode *removeElements(ListNode *head, int val) {
		ListNode *dummy = new ListNode(), *curr = dummy;

		while (head) {
			if (head->val != val) {
				curr->next = head;
				curr = curr->next;
			}
			head = head->next;
		}
		curr->next = nullptr;

		return dummy->next;
	}
};
// @lc code=end
