/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
	// 字符串匹配问题, KMP直接求解即可
	int strStr(string haystack, string needle) {

		vector<int> next = getNext(needle);

		int hIdx = 0, nIdx = 0;
		// hIdx越界表示整个串就找不到needle
		// nIdx越界表示needle已经匹配完了
		while (hIdx < haystack.length() && nIdx < needle.length()) {
			if (haystack[hIdx] == needle[nIdx])
				hIdx++, nIdx++;
			else if (nIdx == 0)
				hIdx++;
			else
				nIdx = next[nIdx];
		}
		return nIdx == needle.length() ? hIdx - nIdx : -1;
	}

	vector<int> getNext(string &needle) {
		if (needle.size() == 1)
			return {-1};

		vector<int> next(needle.size(), 0);
		next[0] = -1;
		next[1] = 0;

		// i是当前要填充的位置, cn是和i-1比较的位置
		int i = 2, cn = 0;
		while (i < needle.length()) {
			if (needle[i - 1] == needle[cn])
				next[i++] = ++cn;
			else if (cn > 0)
				cn = next[cn];
			else
				next[i++] = 0;
		}

		return next;
	}

	// 暴力匹配, 复杂度 O(m*n)
	int strStr1(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (needle.size() > haystack.size()) return -1;

		auto matched = [&haystack, &needle](int i) -> bool {
			for (int j = 0; j < needle.size(); j++)
				if (haystack[i + j] != needle[j])
					return false;
			return true;
		};

		for (int i = 0; i <= haystack.size() - needle.size(); i++)
			if (matched(i))
				return i;
		return -1;
	}
};
// @lc code=end


int main() {
	cout << Solution().strStr("sadbutsad", "sad") << "\n";
}