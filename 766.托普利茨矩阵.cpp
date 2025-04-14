/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>> &matrix) {
		if (matrix.size() <= 1)
			return true;

		for (int i = 1; i < matrix.size(); ++i) {
			for (int j = 1; j < matrix[i].size(); ++j) {
				if (matrix[i][j] != matrix[i - 1][j - 1])
					return false;
			}
		}

		return true;
	}
};
// @lc code=end
