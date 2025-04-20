/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		return processSearchInsert(nums, target, 0, nums.size() - 1);
	}

	int processSearchInsert(vector<int> &nums, int target, int left, int right) {
		if (left > right)
			return left;

		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;

		if (nums[mid] < target)
			return processSearchInsert(nums, target, mid + 1, right);
		else
			return processSearchInsert(nums, target, left, mid - 1);
	}
};
// @lc code=end
