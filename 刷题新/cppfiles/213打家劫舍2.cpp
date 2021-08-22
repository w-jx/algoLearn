#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
//2021年5月20日不会,看的题解
/*
只有一个房屋,偷窃该房间
只有2个房屋,偷窃金额较高的

假如偷窃了第一个房间,不能偷窃最后一个房间
偷窃的范围就是第一个房间到倒数第二个房间
下标是[0,n-2]

如果不偷窃第一个房间,能偷窃最后一个房间
偷窃的范围就是第二个房间到最后一个房间
下标是[1,n-1]

[start,end]范围进行偷窃,dp[i]代表[start,i]能偷窃的最高金额
dp[i]=std::max(dp[i-2]+nums[i],dp[i-1])
边界条件:
	dp[start]=nums[start];只有一个房间
	dp[start+1]=std::max(nums[start],nums[start+1]);有两个房间

分别去[start,end]=[0,n-2]
和[start,end]=[1,n-1]进行计算,取两个dp[end]的最大值

*/
//非状态压缩的
int getMax(vector<int>& nums, int start, int end, int n) {
    vector<int> dp(n);
    dp[start] = nums[start];
    dp[start + 1] = std::max(nums[start], nums[start + 1]);

    for (int i = start + 2; i <= end; ++i) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
}
//状态压缩的
int getMax(vector<int>& nums, int start, int end, int n) {
    vector<int> dp(n);
    int first = nums[start];
    int second = std::max(nums[start], nums[start + 1]);
    int amount = first;
    for (int i = start + 2; i <= end; ++i) {
        amount = std::max(first + nums[i], second);
        first = second;
        second = amount;
    }
    return amount;
}
int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return std::max(nums[0], nums[1]);
    int n = nums.size();
    int first = getMax(nums, 0, n - 2, n);
    int last = getMax(nums, 1, n - 1, n);

    return std::max(first, last);

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