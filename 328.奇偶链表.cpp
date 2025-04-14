/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
	ListNode *oddEvenList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *odd = new ListNode(0), *even = new ListNode(0);
		ListNode *oddCurr = odd, *evenCurr = even;

		int i = 0;
		while (head) {
			ListNode **which = (i++ % 2 == 0) ? &oddCurr : &evenCurr;
			(*which)->next = head;
			(*which) = (*which)->next;
			head = head->next;
			(*which)->next = nullptr;
		}

		oddCurr->next = even->next;

		return odd->next;
	}
};
// @lc code=end
