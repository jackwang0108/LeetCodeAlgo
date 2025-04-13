/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
	void reorderList(ListNode *head) {
		// 快慢指针找到链表的中点
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
			return;

		ListNode *dummy = new ListNode(0, head);
		ListNode *slow = dummy, *fast = dummy;
		while (fast->next != nullptr && fast->next->next != nullptr)
			slow = slow->next, fast = fast->next->next;

		while (fast->next != nullptr)
			slow = slow->next, fast = fast->next;


		stack<ListNode *> st;
		ListNode *curr = slow->next;
		slow->next = nullptr;
		while (curr != nullptr)
			st.push(curr), curr = curr->next;


		int i = 0;
		dummy = dummy->next;
		ListNode *answer = new ListNode(0);
		curr = answer;
		while (!st.empty()) {
			ListNode *which = (i % 2 == 0) ? dummy : st.top();
			curr->next = which;
			curr = curr->next;

			if (i++ % 2 == 0) {
				dummy = dummy->next;
			} else {
				curr->next = nullptr;
				st.pop();
			}
		}
		if (dummy != nullptr)
			curr->next = dummy;
	}
};
// @lc code=end


int main() {
	ListNode *head = buildLinkedList({1, 2, 3, 4, 5});
	Solution().reorderList(head);
	cout << head;
}