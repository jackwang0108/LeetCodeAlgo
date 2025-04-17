/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <stack>
#include <vector>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
	vector<int> dailyTemperatures(vector<int> &temperatures) {
		// 使用一个严格递减的单调栈即可, 当单调性被破坏的时候, 弹出栈顶元素, 结算该元素
		stack<int> st;
		vector<int> result(temperatures.size(), 0);

		// 遍历阶段
		int idx;
		for (int i = 0; i < temperatures.size(); i++) {
			while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
				(idx = st.top()), st.pop();
				result[idx] = i - idx;
			}
			st.push(i);
		}

		// 不需要结算阶段, 因为此时如果单调栈里还有元素, 一定是递减, 此时栈中的每个元素后面没有一天温度比这一天高, 所以直接是0

		return result;
	}
};
// @lc code=end
