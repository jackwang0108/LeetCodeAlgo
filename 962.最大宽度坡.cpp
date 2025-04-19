/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

#include <stack>
#include <vector>

using std::stack;
using std::vector;

/**
 * 我们之前说过的单调栈可以用来找里的最近比他大/小的元素.
 * 这道题要找的是离他最远比他大的元素, 所以之前单调栈的模版这里是用不了的
 * 
 * 但是我们可以换个角度思考, 我们在单调栈里面维持答案的可能性
 * 我们要求单调栈里的元素严格递减, 而后从右向左遍历数组
 */

// @lc code=start
class Solution {
public:
	int maxWidthRamp(vector<int> &nums) {
		stack<int> st;
		for (int i = 0; i < nums.size(); i++)
			if (st.empty() || nums[i] < nums[st.top()])
				st.push(i);

		int maxWidth = 0;
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!st.empty() && nums[i] >= nums[st.top()]) {
				maxWidth = std::max(maxWidth, i - st.top());
				st.pop();
			}
		}

		return maxWidth;
	}
};
// @lc code=end
