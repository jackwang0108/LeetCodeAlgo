/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

#include "linkedlist.h"

#include <unordered_set>

using std::unordered_set;

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
	// 最简单的做法, 用一个set即可
	ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode *> set;
		while (headA && headB) {
			if (set.contains(headA))
				return headA;
			set.insert(headA);

			if (set.contains(headB))
				return headB;
			set.insert(headB);

			headA = headA->next, headB = headB->next;
		}

		while (headA) {
			if (set.contains(headA))
				return headA;
			set.insert(headA);
			headA = headA->next;
		}

		while (headB) {
			if (set.contains(headB))
				return headB;
			set.insert(headB);
			headB = headB->next;
		}

		return nullptr;
	}

	// 更好的做法是双指针
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		// 假设A和B在相交的地方分别是a和b, 那么A的长度是a + c, B的长度是b + c
		// a = b的时候, 直接就是相交节点, 直接返回即可
		// a != b 的时候. 只要A和B到达末尾, 就指向另外一个的开头. 假设A先走到末尾, 则 A 走了 a + c, B 走了 b + c. 等A走到交点的时候, A走了 a + b + c, B在中途会指向 A 的开头, 此时 B也走了a+b+c, 所以这个地方就是交点
		// 如果不相交的话, 最后两个人都会走到null

		if (headA == nullptr || headB == nullptr)
			return nullptr;

		ListNode *pA = headA, *pB = headB;
		while (pA != pB) {
			pA = pA ? pA->next : headB;
			pB = pB ? pB->next : headA;
		}
		return pA;
	}
};
// @lc code=end


int main() {
	ListNode *headA = buildLinkedList({2, 2});
	ListNode *headB = buildLinkedList({2, 2, 4, 5, 4});
	headA->next->next = headB->next->next;

	Solution().getIntersectionNode(headA, headB);
}