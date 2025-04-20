/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <iostream>
#include <unordered_map>

using std::cout;
using std::unordered_map;

// @lc code=start
class Solution {
	unordered_map<int, int> cache;

public:
	int climbStairs(int n) {
		if (n == 0 || n == 1)
			return 1;

		if (cache.contains(n))
			return cache[n];

		cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
		return cache[n];
	}
};
// @lc code=end

int main() {
	cout << Solution().climbStairs(37);
}