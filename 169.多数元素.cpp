/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
	int majorityElement(vector<int> &nums) {
		unordered_map<int, int> count;

		for (int i = 0; i < nums.size(); i++) {
			count[nums[i]]++;
			if (count[nums[i]] > nums.size() / 2) {
				return nums[i];
			}
		}

		return 0;
	}
};
// @lc code=end
