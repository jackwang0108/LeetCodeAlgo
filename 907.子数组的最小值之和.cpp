/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

#include <stack>
#include <vector>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
	long mod = 1000000007;

public:
	// 数据规模: 1 <= arr.length <= 3 * 10^4
	// 暴力解法列出所有子数组, 再求子数组最小值, 然后求和一定来不及

	// CD188使用单调栈求出了每个元素左侧和右侧第一个小于它的元素
	// 所以在这个区间内的所有横跨该元素的数组的最小值都是该元素
	// 因此, 可以用单调栈来加快计算
	int sumSubarrayMins(vector<int> &arr) {
		long result = 0;

		int curr;
		stack<int> st;
		for (int i = 0; i < arr.size(); i++) {
			while (!st.empty() && arr[st.top()] >= arr[i]) {
				(curr = st.top()), st.pop();
				int left = st.empty() ? -1 : st.top();
				result += (i - curr) * (curr - left) * arr[curr];
			}
			st.push(i);
		}

		while (!st.empty()) {
			(curr = st.top()), st.pop();
			int left = st.empty() ? -1 : st.top();
			result += (arr.size() - curr) * (curr - left) * arr[curr];
		}

		return (int) (result % mod);
	}
};
// @lc code=end


int main() {
	vector<int> vec{3, 1, 2, 4};
	Solution().sumSubarrayMins(vec);
	return 0;
}