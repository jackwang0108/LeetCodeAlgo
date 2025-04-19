/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	// 双指针, 移动元素到末尾即可
	int removeElement(vector<int> &nums, int val) {
		int curr = 0, len = nums.size();
		while (curr < len) {
			if (nums[curr] == val)
				std::swap(nums[curr], nums[--len]);
			else
				curr++;
		}

		return len;
	}
};
// @lc code=end
