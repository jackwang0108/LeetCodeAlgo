/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> charCount;

		for (char c: s)
			charCount[c]++;

		for (char c: t)
			charCount[c]--;

		for (const auto &pair: charCount)
			if (pair.second != 0)
				return false;
		return true;
	}
};
// @lc code=end
