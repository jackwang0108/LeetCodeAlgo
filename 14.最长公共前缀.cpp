/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string commonPrefix = "";
		for (int len = 0; len < strs[0].size(); len++) {
			for (int i = 1; i < strs.size(); i++) {
				if (len >= strs[i].size() || strs[i][len] != strs[0][len]) {
					return commonPrefix;
				}
			}
			commonPrefix += strs[0][len];
		}
		return commonPrefix;
	}
};
// @lc code=end
