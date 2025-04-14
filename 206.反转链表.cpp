/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

#include "linkedlist.h"

#include <utility>

using std::pair;

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
	ListNode *reverseList(ListNode *head) {
		return processReverseList(head).first;
	}

	pair<ListNode *, ListNode *> processReverseList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return {head, head};

		auto [reversed, reversedEnd] = processReverseList(head->next);
		reversedEnd->next = head;
		head->next = nullptr;

		return {reversed, head};
	}
};
// @lc code=end


int main() {
	ListNode *head = buildLinkedList({1, 2, 3, 4, 5});
	cout << Solution().reverseList(head);
}