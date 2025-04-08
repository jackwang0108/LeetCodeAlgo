/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

#include "tree.h"

#include <map>
#include <queue>
#include <vector>

using std::map;
using std::queue;
using std::vector;

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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		if (root == nullptr)
			return {};

		vector<vector<int>> result;

		queue<TreeNode *> nodeQueue;
		map<TreeNode *, int> nodeLevelMap;

		nodeQueue.push(root);
		nodeLevelMap[root] = 0;

		TreeNode *curr;
		int currLevel = 0;
		vector<int> levelResult;
		while (!nodeQueue.empty()) {
			curr = nodeQueue.front();
			nodeQueue.pop();

			int currNodeLevel = nodeLevelMap[curr];

			if (currLevel != currNodeLevel) {
				result.push_back(
				    (currLevel % 2 == 0) ? levelResult : vector<int>(levelResult.rbegin(), levelResult.rend()));
				levelResult.clear();
				currLevel = currNodeLevel;
			}
			levelResult.push_back(curr->val);

			if (curr->left) {
				nodeQueue.push(curr->left);
				nodeLevelMap[curr->left] = currNodeLevel + 1;
			}
			if (curr->right) {
				nodeQueue.push(curr->right);
				nodeLevelMap[curr->right] = currNodeLevel + 1;
			}
		}
		result.push_back(
		    (currLevel % 2 == 0) ? levelResult : vector<int>(levelResult.rbegin(), levelResult.rend()));
		return result;
	}
};
// @lc code=end


int main() {
	TreeNode *root = buildTreeFromLevelOrder({3, 9, 20, -1, -1, 15, 7});
	Solution().zigzagLevelOrder(root);
}