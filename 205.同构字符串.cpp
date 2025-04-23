/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;

		unordered_map<char, char> map1;
		unordered_map<char, char> map2;
		for (int i = 0; i < s.size(); i++) {
			if (map1.contains(s[i]) && map1[s[i]] != t[i])
				return false;
			if (map2.contains(t[i]) && map2[t[i]] != s[i])
				return false;

			map1[s[i]] = t[i];
			map2[t[i]] = s[i];
		}

		return true;
	}
};
// @lc code=end
