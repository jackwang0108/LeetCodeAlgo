/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
	// 因为已经分配空间了, 所以直接用归并排序最好
	ListNode *sortList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *mid = findMiddle(head);
		ListNode *right = mid->next;
		mid->next = nullptr;

		right = sortList(right);
		ListNode *left = sortList(head);

		return merge(left, right);
	}

	ListNode *findMiddle(ListNode *head) {
		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next)
			slow = slow->next, fast = fast->next->next;
		return slow;
	}

	ListNode *merge(ListNode *left, ListNode *right) {
		ListNode *dummy = new ListNode(0), *curr = dummy;

		while (left && right) {
			ListNode **which = left->val < right->val ? &left : &right;
			curr->next = *which;
			curr = curr->next;
			*which = (*which)->next;
		}

		if (left)
			curr->next = left;
		else
			curr->next = right;

		return dummy->next;
	}
};
// @lc code=end

int main() {
	ListNode *head = buildLinkedList({4, 2, 1, 3});
	cout << Solution().sortList(head);
}
