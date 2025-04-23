/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include <cstdint>

// @lc code=start
class Solution {
public:
	uint32_t reverseBits1(uint32_t n) {
		uint32_t result = 0;
		for (int i = 0; i < 32; ++i) {
			result <<= 1;
			result |= (n & 1);
			n >>= 1;
		}
		return result;
	}

	// 分治 + 位运算, 真jb牛逼
	const uint32_t M1 = 0b01010101010101010101010101010101;
	const uint32_t M2 = 0b00110011001100110011001100110011;
	const uint32_t M4 = 0b00001111000011110000111100001111;
	const uint32_t M8 = 0b00000000111111110000000011111111;
	uint32_t reverseBits(uint32_t n) {
		n = n >> 1 & M1 | (n & M1) << 1;// 相邻两位反转
		n = n >> 2 & M2 | (n & M2) << 2;// 相邻分组反转
		n = n >> 4 & M4 | (n & M4) << 4;
		n = n >> 8 & M8 | (n & M8) << 8;
		return n >> 16 | n << 16;
	}
};
// @lc code=end
