/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
public:
	vector<int> rightSideView(TreeNode *root) {
		if (!root)
			return {};

		map<TreeNode *, int> nodeLevelMap;
		queue<TreeNode *> nodeQueue;
		nodeQueue.push(root);
		nodeLevelMap[root] = 0;

		int currLevel = 0;
		vector<int> result;
		TreeNode *curr, *prev;
		while (!nodeQueue.empty()) {
			curr = nodeQueue.front();
			nodeQueue.pop();

			int currNodeLevel = nodeLevelMap[curr];

			if (currLevel != currNodeLevel) {
				result.push_back(prev->val);
				currLevel = currNodeLevel;
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
		result.push_back(prev->val);
		return result;
	}
};
// @lc code=end
