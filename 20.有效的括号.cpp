/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <stack>
#include <string>
#include <unordered_map>

using std::stack;
using std::string;
using std::unordered_map;

// @lc code=start
class Solution {
public:
	bool isValid(string s) {
		unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};

		stack<char> st;
		for (char c: s) {
			if (!pairs.contains(c))
				st.push(c);
			else {
				if (st.empty() || st.top() != pairs[c])
					return false;
				st.pop();
			}
		}

		return st.empty();
	}
};
// @lc code=end
