/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include <stack>
#include <vector>

using std::stack;
using std::vector;

// @lc code=start
class Solution {
public:
	// 单调栈, 就是84题的变种, 每一行作为直方图的底部
	int maximalRectangle(vector<vector<char>> &matrix) {
		vector<int> heights = vector<int>(matrix[0].size(), 0);

		int maxArea = 0;
		for (int i = 0; i < matrix.size(); i++) {
			heights = currHeight(heights, matrix[i]);
			maxArea = std::max(maxArea, largestRectangleArea(heights));
		}

		return maxArea;
	}

	vector<int> &currHeight(vector<int> &prevHight, vector<char> currRow) {
		for (int i = 0; i < currRow.size(); i++)
			prevHight[i] = currRow[i] == '1' ? prevHight[i] + 1 : 0;
		return prevHight;
	}

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
