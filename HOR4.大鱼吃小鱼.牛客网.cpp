#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::pair;
using std::stack;
using std::vector;

/**
 * 大鱼吃小鱼
 * https://www.nowcoder.com/practice/77199defc4b74b24b8ebf6244e1793de
 * 
 * 描述
 * 小明最近喜欢上了俄罗斯套娃、大鱼吃小鱼这些大的包住小的类型的游戏。
 * 于是小明爸爸给小明做了一个特别版的大鱼吃小鱼游戏，他希望通过这个游戏
 * 能够近一步提高牛牛的智商。
 * 游戏规则如下：
 *  1. 现在有N条鱼，每条鱼的体积为Ai，从左到右排成一排。
 *  2. A数组是一个排列。
 *  3. 小明每轮可以执行一次大鱼吃小鱼的操作
 * 一次大鱼吃小鱼的操作：对于每条鱼，它在每一次操作时会吃掉右边比自己小的第一条鱼
 * 
 * 值得注意的时，在一次操作中，每条鱼吃比自己小的鱼的时候是同时发生的。
 * 举一个例子，假设现在有三条鱼,体积为分别[5，4，3]，5吃4，4吃3，一次操作后就剩下[5]一条鱼。
 * 
 * 
 * 爸爸问小明，你知道要多少次操作，鱼的数量就不会变了嘛？
 * 
 * 输入描述：
 * - 给定N, １＜＝N＜＝１０＾５
 * - 给定A数组, １＜＝Ai＜＝Ｎ
 * 
 * 输出描述：
 * 一行, 正整数, 表示要多少次操作，鱼的数量就不会变了。
 * 
 * 示例1
 * 输入：
 *     3
 *     1 2 3
 * 输出：
 *     0
 */


vector<int> getInput() {
	int n = 0;
	cin >> n;

	int i = 0;
	vector<int> nums(n, 0);
	while (n-- > 0)
		cin >> nums[i++];

	return nums;
}

// 看到是自己右边离自己最近比自己小的, 所以肯定是用单调栈求解
// 因为这里鱼会同步向右吃, 所以是从右往左去遍历数组, 此时就需要去找自己左边最近比自己大的
// 所以单调栈是要求严格递减的单调栈
// 此外, 因为要求的是轮数, 所以还要考虑怎么样去计算轮数, 因此单调栈里的每个元素还要存自己的轮数
int howManyRoundNeeded(vector<int> &nums) {
	int ans = 0;
	stack<pair<int, int>> s;
	for (int i = nums.size() - 1; i >= 0; i--) {
		// 出现的数字大于栈顶元素, 弹出, 并且去做轮数的计算
		int thisRound = 0;
		while (!s.empty() && s.top().first < nums[i]) {
			// 当前的鱼吃掉栈顶的鱼还要一轮
			thisRound = std::max(thisRound + 1, s.top().second);
			s.pop();
		}
		s.push({nums[i], thisRound});
		ans = std::max(ans, thisRound);
	}
	return ans;
}

int main(int argc, char *argv[]) {

	vector<int> nums = getInput();

	cout << howManyRoundNeeded(nums);

	return 0;
}