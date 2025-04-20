/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
	int mySqrt(int x) {
		int l = 0, r = x, ans = -1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if ((long long) mid * mid <= x) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return ans;
	}
};
// @lc code=end

int main() {
	Solution().mySqrt(8);
}