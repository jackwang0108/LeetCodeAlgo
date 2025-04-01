/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <iostream>
#include <map>
#include <numeric>
#include <string>

using std::cout;
using std::map;
using std::string;

// @lc code=start
class Solution {
public:
	// 满足的条件就是债务清零
	string minWindow(string s, string t) {
		map<char, int> charCount;
		for (char c: t)
			charCount[c]--;

		int debt = t.length(), start = 0;
		int minLength = std::numeric_limits<int>::max();
		for (int left = 0, right = 0; right < s.length(); right++) {
			// 如果是需要的字符就减少债务
			if (charCount[s[right]]++ < 0)
				debt--;

			// 债务清零了就需要尝试减小窗口
			// 因为保证了子串唯一, 所以只需要减小即可, 不需要再考虑后续的字符串了
			if (debt == 0) {
				// 减小窗口的标准是字符的债务大于0
				while (charCount[s[left]] > 0)
					charCount[s[left++]]--;

				// 此时已经缩到最小了
				if (right - left + 1 < minLength) {
					start = left;
					minLength = right - left + 1;
				}
			}
		}
		return minLength == std::numeric_limits<int>::max() ? "" : s.substr(start, minLength);
	}
};
// @lc code=end


int main() {
	cout << Solution().minWindow("ADOBECODEBANC", "ABC");
}