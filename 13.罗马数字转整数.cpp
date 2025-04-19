/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <stack>
#include <string>
#include <unordered_map>

using std::stack;
using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
	unordered_map<char, int> map{
	    {'I', 1},
	    {'V', 5},
	    {'X', 10},
	    {'L', 50},
	    {'C', 100},
	    {'D', 500},
	    {'M', 1000}};

public:
	int romanToInt(string s) {

		int result = 0;
		stack<char> st;
		for (char c: s) {
			if (st.empty()) {
				st.push(c);
				continue;
			}
			// 一个字母只有被弹出的时候才参与计算
			if (map[st.top()] < map[c]) {
				result += map[c] - map[st.top()];
				st.pop();
			} else {
				result += map[st.top()];
				st.pop();
				st.push(c);
			}
		}

		while (!st.empty()) {
			result += map[st.top()];
			st.pop();
		}
		return result;
	}
};
// @lc code=end
