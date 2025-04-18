/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

#include <stack>
#include <vector>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
	// 单调栈
	// 解决思路: 必须以i为高的矩形, 找到左右两边比他小的第一个柱子, 从而得到宽度. 遇到相同值直接释放即可
	int largestRectangleArea(vector<int> &heights) {
		int maxArea = 0;

		stack<int> st;
		int curr = 0, left = 0;
		for (int i = 0; i < heights.size(); i++) {
			while (!st.empty() && heights[st.top()] >= heights[i]) {
				(curr = st.top()), st.pop();
				left = st.empty() ? -1 : st.top();
				maxArea = std::max(maxArea, (i - left - 1) * heights[curr]);
			}
			st.push(i);
		}

		while (!st.empty()) {
			(curr = st.top()), st.pop();
			left = st.empty() ? -1 : st.top();
			maxArea = std::max(maxArea, (int) ((heights.size() - left - 1) * heights[curr]));
		}

		return maxArea;
	}
};
// @lc code=end
