/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);
		ListNode *curr = dummy;

		stack<ListNode *> st;
		while (head != nullptr) {
			// 压 k 个节点入栈
			for (int i = 0; i < k; i++) {
				if (head == nullptr)
					break;
				st.push(head);
				head = head->next;
			}

			curr->next = reverse(st, k);
			while (curr->next != nullptr)
				curr = curr->next;
		}
		return dummy->next;
	}

	ListNode *reverse(stack<ListNode *> &st, int k) {
		ListNode *next, *curr, *head;
		if (st.size() < k) {
			while (!st.empty())
				(curr = st.top()), st.pop();
			return curr;
		}


		(head = curr = st.top()), st.pop();
		while (!st.empty()) {
			(next = st.top()), st.pop();
			curr->next = next;
			curr = curr->next;
		}
		curr->next = nullptr;
		return head;
	}
};
// @lc code=end


int main() {

	ListNode *head = buildLinkedList({1, 2, 3, 4, 5});
	cout << Solution().reverseKGroup(head, 2);

	return 0;
}