/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

#include <stack>

using std::stack;

// @lc code=start
class MyQueue {
	stack<int> in{};
	stack<int> out{};

public:
	MyQueue() {
	}

	void push(int x) {
		in.push(x);
	}

	void _move() {
		while (!in.empty()) {
			out.push(in.top());
			in.pop();
		}
	}

	int pop() {
		if (out.empty())
			_move();

		int top = out.top();
		out.pop();
		return top;
	}

	int peek() {
		if (out.empty())
			_move();

		return out.top();
	}

	bool empty() {
		return in.empty() && out.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
