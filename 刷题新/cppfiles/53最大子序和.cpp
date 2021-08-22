#if 0
#include "../headers/wjxHeaders.h"


/*
动态规划

dp[i]如果代表到前i个数字的最大子序和,那么我们发现
dp[i]和dp[i-1]没有必然联系

例如数组[-2,1,1,-3,4]

前4个数字的最大子序和取[1,1]
前5个数字的最大子序和取[4],可以发现直接去了第五个数字,没有用到之前
4个数字的状态

修改定义,dp[i]代表以第i个数字结尾的最大子序和
dp[0]=nums[0]
dp[1] = max(nums[1]+nums1[0],nums[1])
	=max(dp[0]+nums[1],nums[1]);
*/

int maxSubArray(vector<int>& nums) {
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	int maxres = dp[0];

	for (int i = 1; i < nums.size(); ++i) {
		dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		maxres = std::max(dp[i], maxres);
	}
	return maxres;
}

int maxSubArray2(vector<int>& nums) {
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	int maxres = dp[0];

	for (int i = 1; i < nums.size(); ++i) {
		dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		maxres = std::max(dp[i], maxres);
	}
	return maxres;
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