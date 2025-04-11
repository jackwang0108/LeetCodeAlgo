/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
		ListNode *curr, *dummy = new ListNode(0);

		curr = dummy;

		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val)
				curr->next = list1, list1 = list1->next;
			else
				curr->next = list2, list2 = list2->next;
			curr = curr->next;
		}

		if (list1 != nullptr)
			curr->next = list1;
		else
			curr->next = list2;

		return dummy->next;
	}
};
// @lc code=end


int main() {
	ListNode *list1 = buildLinkedList({1, 2, 4});
	ListNode *list2 = buildLinkedList({1, 3, 4});

	cout << Solution().mergeTwoLists(list1, list2);
}