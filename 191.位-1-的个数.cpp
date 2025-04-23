/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
	int hammingWeight(int n) {
		int count = 0;
		while (n) {
			count += n & 1;
			n >>= 1;
		}
		return count;
	}
};
// @lc code=end
