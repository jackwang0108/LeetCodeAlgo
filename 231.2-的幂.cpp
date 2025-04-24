/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
	// 2的幂的特征是只有一个二进制位为1
	// 所以移除最低位的1之后判断是否为0即可
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;

		return (n & (n - 1)) == 0;
	}
};
// @lc code=end
