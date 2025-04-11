/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

#include "linkedlist.h"

#include <queue>

using std::priority_queue;

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
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode *dummy = new ListNode(0);

		auto cmp = [](ListNode *a, ListNode *b) {
			return a->val > b->val;
		};

		priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> minHeap(cmp);

		for (auto list: lists)
			if (list != nullptr)
				minHeap.push(list);

		ListNode *minNode, *curr = dummy;
		while (!minHeap.empty()) {
			minNode = minHeap.top(), minHeap.pop();
			curr->next = minNode;
			curr = curr->next;
			if (minNode->next != nullptr)
				minHeap.push(minNode->next);
		}

		return dummy->next;
	}
};
// @lc code=end
