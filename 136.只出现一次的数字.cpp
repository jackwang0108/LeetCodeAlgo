/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include <numeric>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	int singleNumber(vector<int> &nums) {
		return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
	}
};
// @lc code=end
