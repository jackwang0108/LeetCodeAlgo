/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
	bool containsDuplicate(vector<int> &nums) {
		unordered_set<int> set;
		for (const int n: nums) {
			if (set.contains(n))
				return true;
			set.insert(n);
		}

		return false;
	}
};
// @lc code=end
