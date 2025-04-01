/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <climits>
#include <iostream>
#include <set>
#include <string>

using std::cout;
using std::set;
using std::string;

// @lc code=start
class Solution {
public:
	// 滑动窗口, 只要右指针指向的元素在集合里面, 左指针就一直走, 同时左指针指向的元素出队列, 直到右指针指向的元素不在集合里
	int lengthOfLongestSubstring(string s) {
		if (s.length() == 0)
			return 0;

		set<char> charSet;
		int maxLength = INT_MIN;
		for (int left = 0, right = 0; right < s.length(); right++) {
			char currChar = s[right];
			while (charSet.contains(currChar)) {
				charSet.erase(s[left]);
				left++;
			}
			charSet.insert(currChar);
			maxLength = std::max(maxLength, right - left + 1);
		}
		return maxLength;
	}
};
// @lc code=end


int main() {
	cout << Solution().lengthOfLongestSubstring("pwwkew");
}
