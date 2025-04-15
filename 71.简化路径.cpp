/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <deque>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::deque;
using std::string;

using std::istringstream;

// @lc code=start
class Solution {
public:
	string simplifyPath(string path) {
		if (path.length() == 1)
			return path;

		string part;
		istringstream iss(path);
		deque<string> dq;
		while (std::getline(iss, part, '/')) {
			if (part == "" || part == ".")
				continue;
			else if (part == "..") {
				if (!dq.empty())
					dq.pop_back();
			} else {
				dq.push_back(part);
			}
		}

		string result = "";
		while (!dq.empty()) {
			result += "/" + dq.front();
			dq.pop_front();
		}

		return result.length() == 0 ? "/" : result;
	}
};
// @lc code=end


int main() {
	string path = "/home//foo/";
	cout << Solution().simplifyPath(path) << std::endl;
}