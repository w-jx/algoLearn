#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。

注意:
 nums 数组的总和是一定在 32 位有符号整数范围之内的。

示例 1:

输入: nums = [1, -1, 5, -2, 3], k = 3
输出: 4 
解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。
示例 2:

输入: nums = [-2, -1, 2, 1], k = 1
输出: 2 
解释: 子数组 [-1, 2] 和等于 1，且长度最长。
进阶:
你能使时间复杂度在 O(n) 内完成此题吗?


LINTCODE 1844
https://www.lintcode.com/problem/1844/
给定一个整数数组和一个整数k，你需要找到和为k的最短子数组，并返回它的长度。

*/
int maxSubArrayLen(vector<int>& nums, int k) {
	unordered_map<int, int> hash;
	hash[0] = 1;
	int sum = 0;
	int res = 0;
	for (int i = 0; i < nums.size(); ++i) {
		sum += nums[i];

		if (hash.count(sum - k) > 0) res = max(res, i - hash[sum - k]);
	}
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif