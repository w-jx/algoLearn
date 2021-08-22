#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

/// <summary>
/// 
/// </summary>
/// <param name="nums">每家人存放的钱的数额</param>
/// <returns>可以偷到的最大数</returns>
int rob(vector<int>& nums) {
	
	int len = nums.size();
	if (len == 0)
		return 0;
	else if (len == 1)
		return nums.front();

	vector<int> dp(nums.size(), 0);
	dp[0]= nums.front();
	dp[1] = max(dp[0], nums[1]);
	for (int i = 2; i < len; ++i) {
		//取了当前位置的，那只能加上i-2位置的了
		//不取当前位置的，那就是dp[i-1]
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}

	return dp[len - 1];

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