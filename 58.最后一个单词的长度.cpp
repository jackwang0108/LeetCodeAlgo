/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <string>

using std::string;

// @lc code=start
class Solution {
public:
	int lengthOfLastWord(string s) {
		int i = s.size() - 1;
		while (i >= 0 && s[i] == ' ')
			i--;

		int count = 0;
		while (i >= 0 && s[i] != ' ')
			count++, i--;

		return count;
	}
};
// @lc code=end
