#include <iostream>
#include <string>
#include <vector>

/**
 * P4391 [BalticOI 2009] Radio Transmission 无线传输
 * 
 * 题目描述
 *     给你一个字符串s1​，它是由某个字符串s2不断自我连接形成的
 *    （保证至少重复 2 次）。
 *     但是字符串s2是不确定的，现在只想知道它的最短长度是多少。
 * 输入格式
 *     第一行一个整数L，表示给出字符串的长度。
 *     第二行给出字符串s1的一个子串，全由小写字母组成。
 * 输出格式
 *     仅一行，表示s2的最短长度。
 * 
 * https://www.luogu.com.cn/problem/P4391
 */

using std::cin;
using std::cout;
using std::string;
using std::vector;

/**
 * 直接说结论: 对字符串s1(长度为n)用KMP算法求其next数组, 最后一个字符next数组值为M, 则最短循环节长度为 n - M
 * 
 * 因为next数组是不包括整个串在内的最大匹配前后缀的长度, 所以最后一个字符的next值的长度就是 (k-1) * s2 + L, 而整个串的长度是 k * s2 + L
 * 所以两个相减就得到了循环节的长度
 */

int process(const string &str) {
	if (str.length() == 1)
		return 1;

	vector<int> next(str.length() + 1, 0);

	next[0] = -1;
	next[1] = 0;

	// i是当前要填充的位置, cn是和i-1比较的位置
	int i = 2, cn = 0;
	while (i <= str.length()) {
		if (str[i - 1] == str[cn])
			next[i++] = ++cn;
		else if (cn > 0)
			cn = next[cn];
		else
			next[i++] = 0;
	}

	return str.length() - next.back();
}

int main() {
	int n;
	cin >> n;

	string s1;
	cin >> s1;
	cout << process(s1);

	return 0;
}