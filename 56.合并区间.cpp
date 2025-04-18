/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <algorithm>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		if (intervals.size() == 1)
			return intervals;

		auto sorter = [](const vector<int> &a, const vector<int> &b) {
			return a[0] < b[0];
		};

		std::sort(intervals.begin(), intervals.end(), sorter);


		vector<vector<int>> res{};
		int prevEnd = intervals[0][1];
		int prevStart = intervals[0][0];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] <= prevEnd) {
				prevStart = std::min(prevStart, intervals[i][0]);
				prevEnd = std::max(prevEnd, intervals[i][1]);
			} else {
				res.emplace_back(vector<int>{prevStart, prevEnd});
				prevStart = intervals[i][0];
				prevEnd = intervals[i][1];
			}
		}
		res.emplace_back(vector<int>{prevStart, prevEnd});

		return res;
	}
};
// @lc code=end

int main() {
	vector<vector<int>> intervals = {{1, 4}, {0, 0}};
}