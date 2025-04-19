/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */


// @lc code=start
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		long original = x;
		long reversed = 0;
		while (x > 0) {
			reversed = reversed * 10 + x % 10;
			x /= 10;
		}

		return original == reversed;
	}
};
// @lc code=end
