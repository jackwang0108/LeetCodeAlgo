/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 1)
			return std::stoi(tokens[0]);

		stack<int> st;
		for (const string &token: tokens) {
			int operand1 = 0, operand2 = 0;
			if (token == "+") {
				operand2 = st.top(), st.pop();
				operand1 = st.top(), st.pop();
				st.push(operand1 + operand2);
			} else if (token == "-") {
				operand2 = st.top(), st.pop();
				operand1 = st.top(), st.pop();
				st.push(operand1 - operand2);
			} else if (token == "*") {
				operand2 = st.top(), st.pop();
				operand1 = st.top(), st.pop();
				st.push(operand1 * operand2);
			} else if (token == "/") {
				operand2 = st.top(), st.pop();
				operand1 = st.top(), st.pop();
				st.push(operand1 / operand2);
			} else {
				st.push(std::stoi(token));
			}
		}
		return st.top();
	}
};
// @lc code=end
