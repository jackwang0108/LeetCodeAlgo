/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include "tree.h"
#include <map>
#include <queue>

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
	vector<vector<int>> levelOrder(TreeNode *root) {
		if (!root) {
			return {};
		}

		queue<TreeNode *> nodeQueue;
		map<TreeNode *, int> levelMap;
		nodeQueue.push(root);
		levelMap[root] = 0;

		TreeNode *curr;
		int currLevel = 0;
		vector<int> layerResult;
		vector<vector<int>> finalResult;
		while (!nodeQueue.empty()) {
			curr = nodeQueue.front();
			nodeQueue.pop();

			int nodeLevel = levelMap[curr];
			if (currLevel != nodeLevel) {
				finalResult.push_back(layerResult);
				layerResult.clear();
				currLevel += 1;
			}


			if (curr) {
				layerResult.push_back(curr->val);
				if (curr->left) {
					nodeQueue.push(curr->left);
					levelMap[curr->left] = nodeLevel + 1;
				}
				if (curr->right) {
					nodeQueue.push(curr->right);
					levelMap[curr->right] = nodeLevel + 1;
				}
			}
		}

		finalResult.push_back(layerResult);

		return finalResult;
	}
};
// @lc code=end
