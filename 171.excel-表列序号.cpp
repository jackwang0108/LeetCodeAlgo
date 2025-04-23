/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

#include <string>

using std::string;

// @lc code=start
class Solution {
public:
	int titleToNumber(string columnTitle) {
		long ans = 0, base = 1;
		for (int i = columnTitle.size() - 1; i >= 0; i--)
			ans += (columnTitle[i] - 'A' + 1) * base, base *= 26;

		return (int) ans;
	}
};
// @lc code=end
