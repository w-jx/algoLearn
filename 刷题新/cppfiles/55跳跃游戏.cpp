#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

这道题最好的方法是贪心算法，并不是动态规划

*/

/// <summary>
/// 判断是否能从第一个下标跳跃到数组的最后一个下标
/// </summary>
/// <param name="nums">非负整数数组</param>
/// <returns>是否能到最后一个下标</returns>
bool canJump(vector<int>& nums) {
	/*
	第一步：确定状态 假如n = nums.size();
		例如最后从石头i 跳跃到n-1，那么肯定满足
		1.能跳到石头i上
		2.i+a[i]>=n-1 
	子问题就是 能否跳到i石头上

	第二步：转移方程
		f[j] 代表能不能跳到石头j上
	f[j] =OR( 0<=i<j代表枚举j石头之前的石头i) (f[i) && i+a[i]>=j)
		也就是能跳到石头i上，且满足跳到石头j上的条件

	第三步：边界条件和初始值
	f[0]=true 因为初始的时候就在第一块上

	第四步：计算顺序
	先计算f[1],再计算f[2]，以此类推
	
	*/
	vector<bool> dp(nums.size(), false);
	dp.front() = true;
	int n = nums.size();
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < j; ++i) {
			if (dp[i] && i + nums[i] >= j) {
				dp[j] = true;
				break;
			}
		}
	}
	return dp[n - 1];
}
//贪心算法
bool canJump2(vector<int>& nums)
{
	std::vector<int> index(nums.size(),0);//最远可跳到位置
	for (int i = 0; i < nums.size(); ++i) {
		index[i] = i + nums[i];
	}
	int jump = 0;
	int max_index = index[0];
	//jump 不能越界,就是数组下标
	//直到jump跳到数组的尾 或者 超越了当前可以跳的最远位置
	//例如数组是2 0 0 0 ....
	//可以看到从第一个位置(下标为0)最多可以到达第三个位置(下标2)
	/*
		2 0 0 0 ..
		2 1 2 3  
		当我们jump遍历到达 第三个0的时候,虽然提示我们最远可以到下标3
		但是实际上我们从下标0的位置 最远只能到达 下标2 ,因此
		jump>max_index,所以这种情况就是失败的
		我们再去检查 jump是不是大于原数组的长度,就能判断是不是能到达最后
		一个位置了	
	*/
	while (jump < nums.size() && jump <= max_index) {
		if (max_index < index[jump])
			max_index = index[jump];
		++jump;
	}
	
	return jump >= nums.size();


}
//2021年5月16日,不要index数组了,直接在遍历的时候更新即可
bool canJump(vector<int>& nums) {
	int jump = 0, max_index = nums[0];
	while (jump < nums.size() && jump <= max_index) {
		max_index = std::max(max_index, jump + nums[jump]);
		++jump;
	}
	return jump >= nums.size();
}
void test01()
{
	vector<int> nums{ 2,3,1,1,4 };
	cout<<canJump2(nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif