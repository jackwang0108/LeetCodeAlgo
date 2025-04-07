/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

#include <map>
#include <queue>

#include "tree.h"

using std::map;
using std::queue;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	vector<vector<int>> results;

public:
	vector<vector<int>> levelOrderBottom(TreeNode *root) {
		if (root == nullptr)
			return {};

		queue<TreeNode *> nodeQueue;
		map<TreeNode *, int> levelMap;
		nodeQueue.push(root);
		levelMap[root] = 0;

		int currLevel = 0;
		TreeNode *curr;
		vector<int> layerNodes;
		while (!nodeQueue.empty()) {
			(curr = nodeQueue.front()), nodeQueue.pop();

			int nodeLevel = levelMap[curr];
			if (nodeLevel != currLevel) {
				results.insert(results.begin(), layerNodes);
				layerNodes.clear();
				currLevel = nodeLevel;
			}

			layerNodes.push_back(curr->val);
			if (curr->left != nullptr) {
				nodeQueue.push(curr->left);
				levelMap[curr->left] = nodeLevel + 1;
			}
			if (curr->right != nullptr) {
				nodeQueue.push(curr->right);
				levelMap[curr->right] = nodeLevel + 1;
			}
		}

		results.insert(results.begin(), layerNodes);
		return results;
	}
};
// @lc code=end
