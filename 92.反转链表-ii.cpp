/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

#include "linkedlist.h"

#include <stack>

using std::stack;

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
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		if (head->next == nullptr)
			return head;

		ListNode *dummy = new ListNode(0, head);

		ListNode *leftStart = dummy, *rightStart = dummy;

		int rightAheadSteps = right - left;
		while (rightAheadSteps-- > 0)
			rightStart = rightStart->next;
		while (left-- > 1)
			leftStart = leftStart->next, rightStart = rightStart->next;
		rightStart = rightStart->next->next;

		stack<ListNode *> s;
		ListNode *cur = leftStart->next;
		while (cur != rightStart) {
			s.push(cur), cur = cur->next;
		}

		while (!s.empty()) {
			leftStart->next = s.top();
			s.pop();
			leftStart = leftStart->next;
		}
		leftStart->next = rightStart;

		return dummy->next;
	}
};
// @lc code=end


int main() {
	ListNode *head = buildLinkedList({1, 2, 3, 4, 5});
	cout << Solution().reverseBetween(head, 2, 4);
}