/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::map;
using std::vector;

// @lc code=start
class Solution {
public:
	// O(N^2) 暴力遍历
	vector<int> twoSumBruteForce(vector<int> &nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target)
					return {i, j};
			}
		}
		return {};
	}

	// 哈希表
	vector<int> twoSum(vector<int> &nums, int target) {
		map<int, int> numMap;
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (numMap.contains(complement)) {
				return {numMap[complement], i};
			}
			numMap[nums[i]] = i;
		}
		return {};
	}

	// 递归版本
	vector<int> twoSumRecursion(vector<int> &nums, int target) {
		return processtwoSumRecursion(nums, target, -1, 0);
	}

	vector<int> processtwoSumRecursion(vector<int> &nums, int target, int prevIdx, int currIdx) {
		if (currIdx >= nums.size())
			return {};

		if (prevIdx != -1 && nums[prevIdx] + nums[currIdx] == target)
			return {prevIdx, currIdx};

		vector<int> useThisNumResult = processtwoSumRecursion(nums, target, currIdx, currIdx + 1);
		if (!useThisNumResult.empty())
			return useThisNumResult;

		vector<int> skipThisNumResult = processtwoSumRecursion(nums, target, prevIdx, currIdx + 1);
		if (!skipThisNumResult.empty())
			return skipThisNumResult;

		return {};
	}
};
// @lc code=end
