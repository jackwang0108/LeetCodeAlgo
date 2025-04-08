/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <map>
#include <queue>

using std::map;
using std::queue;

class Node {
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

	Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

	Node(int _val, Node *_left, Node *_right, Node *_next)
	    : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	// 层序遍历即可
	Node *connect(Node *root) {
		if (root == nullptr)
			return nullptr;

		queue<Node *> nodeQueue;
		map<Node *, int> nodeLevelMap;
		nodeQueue.push(root);
		nodeLevelMap[root] = 0;

		int currLevel = 0;
		Node *curr = nullptr, *prev = nullptr;
		while (!nodeQueue.empty()) {
			(curr = nodeQueue.front()), nodeQueue.pop();

			int currNodeLevel = nodeLevelMap[curr];

			if (currNodeLevel != currLevel) {
				prev->next = nullptr;
				currLevel += 1;
			} else {
				if (prev)
					prev->next = curr;
			}

			if (curr->left) {
				nodeQueue.push(curr->left);
				nodeLevelMap[curr->left] = currNodeLevel + 1;
			}

			if (curr->right) {
				nodeQueue.push(curr->right);
				nodeLevelMap[curr->right] = currNodeLevel + 1;
			}

			prev = curr;
		}

		return root;
	}
};
// @lc code=end


int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(7);

	Solution().connect(root);

	return 0;
}