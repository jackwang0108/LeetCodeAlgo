/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

// @lc code=start
class Solution {
public:
	bool containsNearbyDuplicate(vector<int> &nums, int k) {
		queue<int> q;
		unordered_map<int, int> map;

		for (int i = 0; i < nums.size(); i++) {
			while (q.size() > k) {
				map[q.front()]--;
				q.pop();
			}

			if (++map[nums[i]] > 1)
				return true;
			q.push(nums[i]);
		}

		return false;
	}
};
// @lc code=end
