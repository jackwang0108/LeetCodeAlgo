/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
	double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {

		vector<int> help;
		int leftIdx = 0, rightIdx = 0;
		while (leftIdx < nums1.size() && rightIdx < nums2.size())
			help.push_back(nums1[leftIdx] <= nums2[rightIdx] ? nums1[leftIdx++] : nums2[rightIdx++]);

		while (leftIdx < nums1.size())
			help.push_back(nums1[leftIdx++]);

		while (rightIdx < nums2.size())
			help.push_back(nums2[rightIdx++]);

		int tol = nums1.size() + nums2.size();
		int mid = tol / 2;
		if (tol % 2 == 0)
			return (help[mid - 1] + help[mid]) / 2.0;
		return help[mid];
	}
};
// @lc code=end


int main() {
	Solution().findMedianSortedArrays({1, 2}, {3, 4});
}
