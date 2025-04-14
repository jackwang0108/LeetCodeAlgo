/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
	bool isPalindrome(ListNode *head) {
		ListNode *slow = head, *fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		if (fast)
			slow = slow->next;

		stack<ListNode *> st;
		while (slow)
			st.push(slow), slow = slow->next;

		while (!st.empty()) {
			if (head->val != st.top()->val)
				return false;
			head = head->next;
			st.pop();
		}


		return true;
	}
};
// @lc code=end

int main() {
	ListNode *head = buildLinkedList({1, 2, 2, 1});
	cout << Solution().isPalindrome(head);
}
