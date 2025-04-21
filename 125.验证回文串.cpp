/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include <algorithm>
#include <cctype>
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
	bool isPalindrome(string s) {

		auto isAlpha = [](char c) -> bool {
			return !std::isalnum(c);
		};

		s.erase(std::remove_if(s.begin(), s.end(), isAlpha), s.end());

		std::transform(s.begin(), s.end(), s.begin(), ::tolower);

		return string(s.rbegin(), s.rend()) == s;
	}
};
// @lc code=end

int main() {
	Solution().isPalindrome("A man, a plan, a canal: Panama");

	return 0;
}