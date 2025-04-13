/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

#include <map>

using std::map;

class Node {
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node *copyRandomList(Node *head) {
		if (head == nullptr)
			return nullptr;

		Node *cur = head, *dummy = new Node(0), *prev = dummy;
		map<Node *, Node *> node_map;
		node_map[nullptr] = nullptr;
		while (cur != nullptr) {
			prev->next = new Node(cur->val);
			node_map[cur] = prev->next;
			prev = prev->next, cur = cur->next;
		}

		cur = head, prev = dummy->next;
		while (cur != nullptr) {
			prev->random = node_map[cur->random];
			cur = cur->next;
			prev = prev->next;
		}

		return dummy->next;
	}
};
// @lc code=end
