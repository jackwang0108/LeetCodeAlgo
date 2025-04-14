/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

#include "linkedlist.h"

#include <vector>

using std::vector;

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
	ListNode *insertionSortList(ListNode *head) {

		vector<ListNode *> nodes;
		while (head)
			nodes.push_back(head), head = head->next;

		if (nodes.size() == 1)
			return nodes[0];

		for (int i = 1; i < nodes.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (nodes[j]->val > nodes[j + 1]->val)
					std::swap(nodes[j], nodes[j + 1]);
				else
					break;
			}
		}

		ListNode *dummy = new ListNode(0), *curr = dummy;
		for (int i = 0; i < nodes.size(); i++)
			curr = curr->next = nodes[i], nodes[i]->next = nullptr;

		return dummy->next;
	}
};
// @lc code=end


int main() {
	ListNode *head = buildLinkedList({4, 2, 1, 3});
	cout << Solution().insertionSortList(head);
}