/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

#include "linkedlist.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// 这个题的意思就是说, 不给你链表的head, 只给你要删除的节点, 要求你从这个链表中删除这个节点
	void deleteNode(ListNode *node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};
// @lc code=end
