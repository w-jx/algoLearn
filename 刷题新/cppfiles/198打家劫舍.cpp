#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/house-robber
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

/// <summary>
/// 
/// </summary>
/// <param name="nums">ÿ���˴�ŵ�Ǯ������</param>
/// <returns>����͵���������</returns>
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
		//ȡ�˵�ǰλ�õģ���ֻ�ܼ���i-2λ�õ���
		//��ȡ��ǰλ�õģ��Ǿ���dp[i-1]
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