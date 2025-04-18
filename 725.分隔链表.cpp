/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

#include "linkedlist.h"

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
	vector<ListNode *> splitListToParts(ListNode *head, int k) {
		vector<ListNode *> result(k, nullptr);

		int length = getLength(head),
		    partLength = length / k,
		    extraLength = length % k;

		for (int i = 0; i < k && head != nullptr; i++) {
			result[i] = head;
			int currPartLength = partLength + (i < extraLength ? 1 : 0);
			for (int j = 0; j < currPartLength - 1; j++)
				head = head->next;
			ListNode *nextHead = head->next;
			head->next = nullptr;
			head = nextHead;
		}

		return result;
	}


	int getLength(ListNode *head) {
		int length = 0;
		while (head != nullptr) {
			length++;
			head = head->next;
		}
		return length;
	}
};
// @lc code=end
