/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	int singleNumber(vector<int> &nums) {

		int result = nums[0];
		for (int i = 1; i < nums.size(); i++)
			result ^= nums[i];

		return result;
	}
};
// @lc code=end
