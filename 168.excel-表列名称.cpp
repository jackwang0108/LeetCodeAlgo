/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel 表列名称
 */

#include <string>

using std::string;

// @lc code=start
class Solution {
public:
	string convertToTitle(int columnNumber) {
		string result = "";
		while (columnNumber > 0) {
			result.insert(result.begin(), 'A' + (columnNumber - 1) % 26);
			columnNumber = (columnNumber - 1) / 26;
		}

		return result;
	}
};
// @lc code=end
