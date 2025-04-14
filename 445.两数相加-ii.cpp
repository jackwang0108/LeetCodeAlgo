/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

		auto [reversedL1, endL1] = reverse(l1);
		auto [reversedL2, endL2] = reverse(l2);

		ListNode *dummy = new ListNode(0), *curr = dummy;

		int carry = 0;
		while (reversedL1 || reversedL2 || carry) {
			int sum = carry;
			if (reversedL1) {
				sum += reversedL1->val;
				reversedL1 = reversedL1->next;
			}
			if (reversedL2) {
				sum += reversedL2->val;
				reversedL2 = reversedL2->next;
			}

			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
		}

		return reverse(dummy->next).first;
	}

	pair<ListNode *, ListNode *> reverse(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return {head, head};

		auto [reversedHead, reversedEnd] = reverse(head->next);
		reversedEnd->next = head;
		head->next = nullptr;

		return {reversedHead, head};
	}
};
// @lc code=end
