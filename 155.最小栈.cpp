/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include <stack>

using std::stack;

// @lc code=start
class MinStack {
	stack<int> st{};
	stack<int> minSt{};

public:
	MinStack() {}

	void push(int val) {
		st.push(val);

		int min = minSt.empty() ? val : (minSt.top() < val ? minSt.top() : val);
		minSt.push(min);
	}

	void pop() {
		st.pop();
		minSt.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return minSt.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
