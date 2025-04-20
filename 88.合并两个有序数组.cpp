/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
		if (n == 0)
			return;
		if (m == 0) {
			nums1 = nums2;
			return;
		}

		int i = m - 1, j = n - 1, k = nums1.size() - 1;
		while (i >= 0 && j >= 0)
			nums1[k--] = (nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];

		while (j >= 0)
			nums1[k--] = nums2[j--];
		while (i >= 0)
			nums1[k--] = nums1[i--];
	}
};
// @lc code=end
