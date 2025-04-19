/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	// 双指针
	int removeDuplicates(vector<int> &nums) {
		int curr = 0, look = 1;
		while (look < nums.size()) {
			if (nums[curr] == nums[look])
				look++;
			else
				nums[++curr] = nums[look++];
		}

		return curr + 1;
	}
};
// @lc code=end
