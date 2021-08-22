#if 0

#include "../headers/wjxHeaders.h"
//这是背包问题
/*
我的想法
但是target 可能是负数
这就不行了
*/
int findTargetSumWays(vector<int>& nums, int target) {
	int n = nums.size();
	//dp[i][j]代表前i个元素能够组成j的方法数
	//最后返回dp[n][target]
	vector<vector<int> > dp(n + 1, vector<int>(target + 1));


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= target; ++j) {
			if (j - nums[i - 1] < 0 || j+nums[i-1]>target) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j + nums[i - 1]];
			}
		}
	}

	return dp[n][target];
}


int dfs(vector<int>& nums, int idx, int target) {
	if (idx < 0)
		return 0;
	if (idx == 0) {
		int items = 0;
		if (nums[0] == target)
			++items;
		if (nums[0] + target == 0)
			++items;
		return items;
	}
	if (nums[idx] == 0)
		return dfs(nums, idx - 1, target);
	return dfs(nums, idx - 1, target - nums[idx]) + dfs(nums, idx - 1, target + nums[idx]);
}
//第二次尝试
int findTargetSumWays2(vector<int>& nums, int target) {
	
	int n = nums.size();
	if (n < 2) {
		int items = 0;
		if (nums[0] == target)
			++items;
		if (nums[0] + target == 0)
			++items;
		return items;

	}
	if (nums.back() == 0)
		return dfs(nums, n - 2, target);
	return dfs(nums, n - 2, target -nums.back()) + dfs(nums, n - 2, target + nums.back());
}

void backtrace(vector<int>& nums,int idx, int const &target, int sum,int &times) {
	if (idx == nums.size()) {
		if (sum == target)
			++times;
		return;
	}
	backtrace(nums, idx + 1, target, sum + nums[idx], times);
	backtrace(nums, idx + 1, target, sum - nums[idx], times);
}
//答案题解的回溯解法
/*
回溯解法就是不断递归,针对每一个变量num,+num或者-num的结果
到最后的时候比较sum是否等于target

*/
int findTargetSumWays3(vector<int>& nums, int target) {
	int times = 0;
	backtrace(nums, 0, target, 0,times);
	return times;
}

/*
答案题解的动态规划
相当于
正号元素的和 + 负号元素的和 = target
所有数的和为sum,负号元素的和为neg
则正号元素的和为  sum-neg
(sum-neg) - neg = target
	neg = (sum-target)/2

sum,neg都是非负整数,neg 也是非负整数
sum-target 是非负偶数,不符合的话方案数为0	

所以题目转化成:从数组中选取若干个数,使得元素之和为neg
dp[i][j]代表在数组nums的前i个元素中选取元素,使得元素和为j的方案数

没有元素可选的时候:边界条件
dp[0][j]=1 (j=0)
dp[0][j]=0(j>0)

对于数组的第i个元素num(从1计算)
遍历j=[0,neg],计算dp[i][j]
	如果j<num,则不能选num
	dp[i][j] = dp[i-1][j]

	如果j>=num,如果不选num,方案数dp[i-1][j]
			如果选num,方案数dp[i-1][j-num]
	dp[i][j] = dp[i-1][j] + dp[i-1][j-num]

状态转移方程出来了:
				dp[i-1][j]   (j<num)
	dp[i][j] = 
				dp[i-1][j] + dp[i-1][j-num] (j>=num)
*/
int findTargetSumWays4(vector<int>& nums, int target) {
	int n = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int neg = sum - target;
	if (neg < 0 || neg % 2 != 0)
		return 0;
	neg /= 2;
	vector<vector<int> > dp(n + 1, vector<int>(neg + 1));

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		int num = nums[i - 1];
		for (int j = 0; j <= neg; ++j) {
			if (j < num) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
			}
		}
	}
	return dp[n][neg];
}
void test01()
{
	vector<int> nums(5,1);
	cout << findTargetSumWays2(nums, 3) << endl;
}
int main()
{
	//test01();
	vector<int> v;
	//1074731823
	cout << v.max_size() << endl;

}


#endif