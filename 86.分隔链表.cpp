/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
	// 荷兰国旗问题, 不过链表的更简单
	ListNode *partition(ListNode *head, int x) {
		ListNode *leDummy = new ListNode(0);
		ListNode *geDummy = new ListNode(0);

		ListNode *le = leDummy, *ge = geDummy;
		while (head) {
			if (head->val < x) {
				le->next = head;
				le = le->next;
			} else {
				ge->next = head;
				ge = ge->next;
			}
			head = head->next;
		}
		le->next = geDummy->next;
		ge->next = nullptr;
		return leDummy->next;
	}
};
// @lc code=end
