/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
	vector<int> vec1{1};
	vector<int> vec2{1, 1};

public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0)
			return vec1;
		if (rowIndex == 1)
			return vec2;

		vector<int> *prev = &vec1, *curr = &vec2;

		for (int row = 1; row <= rowIndex; row++) {

			curr->clear();
			curr->push_back(1);

			for (int i = 0; i < prev->size() - 1; i++)
				curr->push_back((*prev)[i] + (*prev)[i + 1]);
			curr->push_back(1);

			std::swap(prev, curr);
		}

		return *prev;
	}
};
// @lc code=end

int main() {
	Solution().getRow(3);
	return 0;
}