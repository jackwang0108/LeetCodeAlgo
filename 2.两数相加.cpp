/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <vector>

using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
		int prevCarry = 0;
		ListNode *result = nullptr, *head;
		while (l1 != nullptr && l2 != nullptr) {
			int sum = l1->val + l2->val + prevCarry;

			prevCarry = sum / 10;
			ListNode *newNode = new ListNode(sum % 10);
			if (result == nullptr)
				result = head = newNode;
			else {
				result->next = newNode;
				result = result->next;
			}

			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr) {
			int sum = prevCarry + l1->val;
			prevCarry = sum / 10;
			ListNode *newNode = new ListNode(sum % 10);
			result->next = newNode;
			result = result->next;
			l1 = l1->next;
		}

		while (l2 != nullptr) {
			int sum = prevCarry + l2->val;
			prevCarry = sum / 10;
			ListNode *newNode = new ListNode(sum % 10);
			result->next = newNode;
			result = result->next;
			l2 = l2->next;
		}

		if (prevCarry != 0)
			result->next = new ListNode(prevCarry);

		return head;
	}
};
// @lc code=end

ListNode *buildList(const vector<int> &vec) {
	ListNode *head, *curr, *tmp;

	for (int i = 0; i < vec.size(); i++) {
		tmp = new ListNode(vec[i]);
		if (i == 0)
			head = curr = tmp;
		else {
			curr->next = tmp;
			curr = curr->next;
		}
	}
	return head;
}

int main() {

	ListNode *l1 = buildList(vector<int>(7, 9));

	ListNode *l2 = buildList(vector<int>(4, 9));

	Solution().addTwoNumbers(l1, l2);
}