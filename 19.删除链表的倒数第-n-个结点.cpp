/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
	// 牛逼
	// 在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 next 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *dummy = new ListNode(0, head);

		ListNode *slow = dummy, *fast = head;

		while (n-- > 0)
			fast = fast->next;

		while (fast != nullptr)
			slow = slow->next, fast = fast->next;

		slow->next = slow->next->next;

		return dummy->next;
	}
};
// @lc code=end


int main() {
	// [1, 2], 1
	// [1, 2], 2
	ListNode *head = buildLinkedList({1, 2});

	cout << Solution().removeNthFromEnd(head, 1);
}