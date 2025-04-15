/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <iostream>
#include <queue>

using std::cout;
using std::queue;

// @lc code=start
class MyStack1 {
	queue<int> q1{};
	queue<int> q2{};

	queue<int> *prev;
	queue<int> *curr;

public:
	MyStack1() {
		curr = &q1;
		prev = &q2;
	}

	void _switch() {
		std::swap(curr, prev);
	}

	void push(int x) {
		curr->push(x);
	}

	int pop() {
		while (curr->size() > 1)
			prev->push(curr->front()), curr->pop();
		int top = curr->front();
		curr->pop();
		_switch();
		return top;
	}

	int top() {
		while (curr->size() > 1)
			prev->push(curr->front()), curr->pop();
		int top = curr->front();
		prev->push(top);
		curr->pop();
		_switch();
		return top;
	}

	bool empty() {
		return curr->empty();
	}
};

// 使用一个队列完成的栈
class MyStack {
	queue<int> q;

public:
	MyStack() {}

	void push(int x) {
		q.push(x);
		// 将前面的元素重新入队，使得新元素在队首
		for (int i = 0; i < q.size() - 1; i++) {
			q.push(q.front());
			q.pop();
		}
	}

	int pop() {
		int top = q.front();
		q.pop();
		return top;
	}

	int top() {
		return q.front();
	}

	bool empty() {
		return q.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main() {
	MyStack *obj = new MyStack();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	cout << obj->pop() << " ";
	cout << obj->pop() << " ";
	cout << obj->pop() << " ";
	cout << std::boolalpha << obj->empty() << " ";


	delete obj;
	return 0;
}
