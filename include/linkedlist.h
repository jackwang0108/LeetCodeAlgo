#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ostream &operator<<(ostream &os, ListNode *head) {
	os << "LinkedList: ";
	ListNode *curr = head;
	while (curr != nullptr) {
		os << curr->val << " -> ";
		curr = curr->next;
	}
	os << "nullptr";
	return os;
}

ListNode *buildLinkedList(const vector<int> &vec) {
	if (vec.empty())
		return nullptr;

	ListNode *head = new ListNode(vec[0]);
	ListNode *curr = head;
	for (int i = 1; i < vec.size(); i++) {
		curr->next = new ListNode(vec[i]);
		curr = curr->next;
	}

	return head;
}