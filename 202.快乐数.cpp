/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <unordered_set>

using std::unordered_set;

// @lc code=start
class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> set;
		while (n != 1 && !set.contains(n)) {
			set.insert(n);

			int sum = 0;
			while (n > 0) {
				int digit = n % 10;
				sum += digit * digit;
				n /= 10;
			}
			n = sum;
		}
		return n == 1;
	}
};
// @lc code=end
