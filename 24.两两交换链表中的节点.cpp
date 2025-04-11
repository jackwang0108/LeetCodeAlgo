/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
	ListNode *swapPairs(ListNode *head) {
		ListNode *dummy = new ListNode(0);

		stack<ListNode *> st;
		ListNode *curr = dummy;

		while (head != nullptr) {
			// 压两个节点入栈
			for (int i = 0; i < 2; i++) {
				if (head == nullptr)
					break;
				st.push(head);
				head = head->next;
			}

			curr->next = swap(st);
			while (curr->next != nullptr)
				curr = curr->next;
		}

		return dummy->next;
	}

	ListNode *swap(stack<ListNode *> &st) {
		if (st.size() == 1) {
			ListNode *first = st.top();
			st.pop();
			first->next = nullptr;
			return first;
		}

		ListNode *first, *second;
		(second = st.top()), st.pop();
		(first = st.top()), st.pop();
		second->next = first;
		first->next = nullptr;
		return second;
	}
};
// @lc code=end

int main() {
	ListNode *head = buildLinkedList({1, 2, 3, 4});
	cout << Solution().swapPairs(head);
}
