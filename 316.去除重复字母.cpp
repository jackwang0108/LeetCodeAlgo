/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
	string minLexiStr;
	unordered_set<char> charSet{};
	unordered_set<char> currCharSet{};

public:
	// = 这个递归的解法是正确的, 但是超时了, 复杂度 O(2^N)
	string removeDuplicateLetters1(string s) {
		if (s.length() <= 1)
			return s;
		minLexiStr = string(s.length(), 'z');

		for (const char c: s)
			charSet.insert(c);

		processRemoveDuplicateLetters(s, 0, "");

		return minLexiStr;
	}

	void processRemoveDuplicateLetters(string s, int index, string prevStr) {
		// 递归终止条件
		if (index >= s.length()) {
			if (currCharSet == charSet)
				minLexiStr = prevStr < minLexiStr ? prevStr : minLexiStr;
			return;
		}

		if (currCharSet.contains(s[index]))
			return processRemoveDuplicateLetters(s, index + 1, prevStr);

		currCharSet.insert(s[index]);
		processRemoveDuplicateLetters(s, index + 1, prevStr + s[index]);
		currCharSet.erase(s[index]);
		processRemoveDuplicateLetters(s, index + 1, prevStr);
	}

	// = 如果不超时的话, 需要用单调栈, 并且是有重复值情况下的单调栈. 无重复值的单调栈参考 牛客网-单调栈结构(进阶).cpp
	//【算法讲解052【必备】单调栈-上】https://www.bilibili.com/video/BV1HH4y1X7T9?vd_source=214871085a518d6559a5be7d13ee2374

	// 单调栈求解速度就很快了, 栈里面保存的是最小的字典序的字符串的可能
	// 要求其中保存的字母严格大压小
	// 但是因为每个字母都要出现一次, 所以提前建立一个词频表, 来判断能否弹出栈顶元素
	string removeDuplicateLetters(string s) {
		unordered_map<char, int> charCount{};
		for (const char c: s)
			charCount[c]++;

		vector<char> stack{};
		unordered_set<char> inStack{};
		for (const char c: s) {
			// 当前字符已经在栈中了
			if (inStack.contains(c)) {
				charCount[c]--;
				continue;
			}

			// 当前字符不在栈中, 判断能否弹出之前的字符
			while (!stack.empty() && stack.back() > c && charCount[stack.back()] > 0) {
				inStack.erase(stack.back());
				stack.pop_back();
			}

			stack.push_back(c);
			inStack.insert(c);
			charCount[stack.back()]--;
		}

		return string(stack.begin(), stack.end());
	}
};
// @lc code=end

int main() {
	std::cout << Solution().removeDuplicateLetters("cbacdcbc");
}