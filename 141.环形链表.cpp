/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
	bool hasCycle1(ListNode *head) {
		// 最简单的做法, 使用一个set即可

		unordered_set<ListNode *> node_set;

		while (head != nullptr) {
			if (node_set.contains(head))
				return true;
			node_set.insert(head);
			head = head->next;
		}

		return false;
	}

	// 更省空间的做法是快慢指针, 用O(1)的空间复杂度
	// 其实就是追及问题
	bool hasCycle(ListNode *head) {
		if (head == nullptr)
			return false;

		ListNode *slow = head, *fast = head->next;

		while (slow != fast) {
			if (fast == nullptr || fast->next == nullptr)
				return false;
			slow = slow->next;
			fast = fast->next->next;
		}

		return true;
	}
};
// @lc code=end
