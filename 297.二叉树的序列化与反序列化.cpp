/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include "tree.h"

#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using std::istringstream;
using std::map;
using std::queue;
using std::string;
using std::vector;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
	string preOrder, inOrder;

public:
	// Encodes a tree to a single string.
	// = 如果用二叉树的先序遍历和中序遍历的方式, 因为子节点的值可能有重复, 所以还需要在inStart和inEnd中确定哪个才是真正的根节点, 最后就很麻烦
	// = 后序遍历也是如此, 所以不如直接用层序的方式做了
	string serialize1(TreeNode *root) {
		if (root == nullptr)
			return "#";

		preOrderTraversal(root);
		inOrderTraversal(root);

		return preOrder.substr(0, preOrder.length() - 1) + "#" + inOrder.substr(0, inOrder.length() - 1);
	}

	void preOrderTraversal(TreeNode *root) {
		if (root == nullptr)
			return;

		preOrder += std::to_string(root->val) + ",";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}

	void inOrderTraversal(TreeNode *root) {
		if (root == nullptr)
			return;
		inOrderTraversal(root->left);
		inOrder += std::to_string(root->val) + ",";
		inOrderTraversal(root->right);
	}


	// Decodes your encoded data to tree.
	TreeNode *deserialize1(string data) {
		if (data == "#")
			return nullptr;

		istringstream ss(data);
		string preOrderStr, inOrderStr;
		std::getline(ss, preOrderStr, '#');
		std::getline(ss, inOrderStr);

		vector<int> preOrder = parseStringVector(preOrderStr);
		vector<int> inOrder = parseStringVector(inOrderStr);


		return buildTreeFromPreAndInOrder(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1);
	}

	vector<int> parseStringVector(string str) {
		vector<int> result;
		istringstream ss(str);

		string token;
		while (std::getline(ss, token, ','))
			result.push_back(std::stoi(token));
		return result;
	}

	TreeNode *buildTreeFromPreAndInOrder(const vector<int> &preOrder, int preStart, int preEnd, const vector<int> &inOrder, int inStart, int inEnd) {
		if (preStart > preEnd || inStart > inEnd)
			return nullptr;

		int rootVal = preOrder[preStart];
		TreeNode *root = new TreeNode(rootVal);


		// TODO: 如果允许值重复, 就需要确定在inStart和inEnd中哪个才是真正的根节点
		int rootIndex = 1;
		int leftTreeSize = rootIndex - inStart;

		root->left = buildTreeFromPreAndInOrder(preOrder, preStart + 1, preStart + leftTreeSize, inOrder, inStart, rootIndex - 1);
		root->right = buildTreeFromPreAndInOrder(preOrder, preStart + leftTreeSize + 1, preEnd, inOrder, rootIndex + 1, inEnd);

		return root;
	}


	string serialize(TreeNode *root) {
		if (root == nullptr)
			return "";

		string result = "";
		TreeNode *currNode;
		queue<TreeNode *> nodeQueue;

		nodeQueue.push(root);
		while (!nodeQueue.empty()) {
			(currNode = nodeQueue.front(), nodeQueue.pop());

			if (currNode == nullptr) {
				result += "null,";
				continue;
			}


			result += std::to_string(currNode->val) + ",";
			nodeQueue.push(currNode->left);
			nodeQueue.push(currNode->right);
		}

		return result.substr(0, result.length() - 1);
	}

	vector<int> parseString(const string &str) {
		string token;
		vector<int> result;
		istringstream ss(str);
		while (std::getline(ss, token, ','))
			result.push_back(token == "null" ? std::numeric_limits<int>::min() : std::stoi(token));

		return result;
	}


	TreeNode *deserialize(string data) {
		if (data == "")
			return nullptr;

		vector<int> vec = parseString(data);

		if (vec.size() == 0 || vec[0] == std::numeric_limits<int>::min())
			return nullptr;

		if (vec.size() == 1)
			return new TreeNode(vec[0]);

		int idx = 1;
		queue<TreeNode *> nodeQueue;
		TreeNode *curr, *root = new TreeNode(vec[0]);

		nodeQueue.push(root);
		while (!nodeQueue.empty()) {
			(curr = nodeQueue.front(), nodeQueue.pop());

			if (idx < vec.size() && vec[idx] != std::numeric_limits<int>::min()) {
				curr->left = new TreeNode(vec[idx]);
				nodeQueue.push(curr->left);
			}
			idx++;

			if (idx < vec.size() && vec[idx] != std::numeric_limits<int>::min()) {
				curr->right = new TreeNode(vec[idx]);
				nodeQueue.push(curr->right);
			}
			idx++;
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end


int main() {
	Codec codec;

	TreeNode *root = buildTreeFromLevelOrder({4, -7, -3, -1, -1, -9, -3, 9, -7, -4, -1, 6, -1, -6, -6, -1, -1, 0, 6, 5, -1, 9, -1, -1, 1, -4, -1, -1, -1, -2}, false);
	cout << root;
	string serialized = codec.serialize(root);
	TreeNode *deserialized = codec.deserialize(serialized);

	cout << deserialized;

	return 0;
}