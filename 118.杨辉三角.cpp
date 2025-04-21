/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
	vector<vector<int>> result{{1}};

public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 1)
			return result;

		for (int i = 2; i <= numRows; i++)
			generateRow();

		return result;
	}

	void generateRow() {
		vector<int> row;
		row.push_back(1);

		for (int i = 0; i < result.back().size() - 1; i++)
			row.push_back(result.back()[i] + result.back()[i + 1]);

		row.push_back(1);
		result.push_back(row);
		return;
	}
};
// @lc code=end
