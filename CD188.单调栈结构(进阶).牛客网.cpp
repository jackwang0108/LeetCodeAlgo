#include <iostream>
#include <map>
#include <stack>
#include <vector>

/**
 * 单调栈结构(进阶)
 * https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb
 * 
 * 描述
 * 给定一个可能含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。返回所有位置相应的信息。
 * 
 * 输入描述：
 * 第一行输入一个数字 n，表示数组 arr 的长度。
 * 以下一行输入 n 个数字，表示数组的值
 * 
 * 输出描述：
 * 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
 * 
 * 示例1
 * 输入：
 *     7
 *     3 4 1 5 6 2 7
 * 输出：
 *     -1 2
 *     0 2
 *     -1 -1
 *     2 5
 *     3 5
 *     2 -1
 *     5 -1
 */

using std::cin;
using std::cout;
using std::map;
using std::stack;
using std::vector;

std::ostream &operator<<(std::ostream &os, const vector<int> &v) {
	for (const auto &i: v)
		os << i << " ";
	return os;
}

std::ostream &operator<<(std::ostream &os, const map<int, vector<int>> &m) {
	for (const auto &i: m)
		os << i.second << "\n";
	return os;
}

vector<int> readInput() {
	int n, i = 0;
	cin >> n;
	vector<int> nums(n, 0);
	while (n-- > 0)
		cin >> nums[i++];
	return nums;
}

map<int, vector<int>> monotonicStack(const vector<int> &nums) {
	stack<int> st;
	map<int, vector<int>> result;

	// 遍历阶段
	for (int i = 0; i < nums.size(); i++) {
		// 上到山顶了, 开始下山 (单调性被破坏)
		while (!st.empty() && nums[st.top()] >= nums[i]) {
			int j = st.top();
			st.pop();
			result[j].push_back(st.empty() ? -1 : st.top());
			result[j].push_back(i);
		}
		st.push(i);
	}

	// 清算阶段
	int curr;
	while (!st.empty()) {
		(curr = st.top()), st.pop();
		result[curr].push_back(st.empty() ? -1 : st.top());
		result[curr].push_back(-1);
	}

	// 修正阶段
	for (int i = nums.size() - 1; i >= 0; i--)
		if (result[i][1] != -1 && nums[result[i][1]] == nums[i])
			result[i][1] = result[result[i][1]][1];


	return result;
}

int main() {
	vector<int> nums = readInput();

	map<int, vector<int>> result = monotonicStack(nums);

	cout << result;

	return 0;
}