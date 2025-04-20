/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <iostream>
#include <string>

using std::cout;
using std::string;

// @lc code=start
class Solution {
public:
	string addBinary(string a, string b) {
		string result;

		int i = a.size() - 1, j = b.size() - 1, carry = 0;
		while (i >= 0 || j >= 0) {
			int sum =
			    carry +
			    (i >= 0 ? a[i--] - '0' : 0) +
			    (j >= 0 ? b[j--] - '0' : 0);
			result.push_back('0' + sum % 2);
			carry = sum / 2;
		}

		if (carry > 0) {
			result.push_back('1');
		}

		return string(result.rbegin(), result.rend());
	}
};
// @lc code=end

int main() {
	cout << Solution().addBinary("11", "1") << "\n";
}