/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
	vector<string> summaryRanges(vector<int> &nums) {
		if (nums.empty()) return {};

		vector<string> result;
		int start = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] != nums[i - 1] + 1) {
				result.push_back(start == nums[i - 1] ? std::to_string(start) : std::to_string(start) + "->" + std::to_string(nums[i - 1]));
				start = nums[i];
			}
		}
		result.push_back(start == nums.back() ? std::to_string(start) : std::to_string(start) + "->" + std::to_string(nums.back()));

		return result;
	}
};
// @lc code=end
