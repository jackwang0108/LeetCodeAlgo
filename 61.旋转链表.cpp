/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

#include "linkedlist.h"

#include <deque>

using std::deque;

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
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr)
			return nullptr;

		// 双端队列直接解决问题
		deque<ListNode *> dq;
		while (head != nullptr)
			dq.push_back(head), head = head->next;

		k = k % dq.size();
		while (k-- > 0)
			dq.push_front(dq.back()), dq.pop_back();

		ListNode *dummy = new ListNode(0);
		ListNode *curr = dummy;
		while (!dq.empty()) {
			curr->next = dq.front();
			curr = curr->next;
			dq.pop_front();
		}
		curr->next = nullptr;

		return dummy->next;
	}
};
// @lc code=end

int main() {

	ListNode *head = buildLinkedList({1, 2, 3, 4, 5});
	cout << Solution().rotateRight(head, 2);

	return 0;
}