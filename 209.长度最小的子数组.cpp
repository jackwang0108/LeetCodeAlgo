/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <numeric>
#include <vector>

using std::vector;

/**
 * @brief 滑动窗口用于解决子数组/子串问题
 * 注意, 子数组和子串要求是连续的, 而子序列则可以不连续
 * 
 * 滑动窗口要求左右边界都不回退
 * 求解的关键在于, 找到范围和答案指标之间的单调关系, 即一旦不达标, 就要缩范围
 * 在此基础上, 求子数组在每个位置开头或者每个位置结尾的答案
 */

// @lc code=start
class Solution {
public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int result = std::numeric_limits<int>::max();

		for (int left = 0, right = 0, sum = 0; right < nums.size(); right++) {
			sum += nums[right];

			// while里面是左指针移动的条件
			// 只要区间内的累加和始终大于target, 窗口一直减小到无法减小为止
			while (sum - nums[left] >= target)
				sum -= nums[left++];

			// 结算
			if (sum >= target)
				result = std::min(result, right - left + 1);
		}

		return result == std::numeric_limits<int>::max() ? 0 : result;
	}
};
// @lc code=end
