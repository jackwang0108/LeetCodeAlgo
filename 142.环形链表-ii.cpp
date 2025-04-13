/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include "linkedlist.h"

#include <unordered_set>

using std::unordered_set;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// 最简单的做法, 使用一个set即可
	ListNode *detectCycle1(ListNode *head) {
		if (head == nullptr)
			return nullptr;

		unordered_set<ListNode *> node_set;
		while (head != nullptr) {
			if (node_set.contains(head))
				return head;
			node_set.insert(head);
			head = head->next;
		}

		return nullptr;
	}

	// 更省空间的做法是快慢指针, 用O(1)的空间复杂度
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return nullptr;

		ListNode *slow = head->next, *fast = head->next->next;

		while (slow != fast) {
			if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
				return nullptr;
			slow = slow->next;
			fast = fast->next->next;
		}

		slow = head;
		while (slow != fast)
			slow = slow->next, fast = fast->next;

		return fast;
	}
};
// @lc code=end
