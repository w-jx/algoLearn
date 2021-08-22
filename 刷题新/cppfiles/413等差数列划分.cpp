#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    //dp[i]代表以nums[i]结尾的等差数列的个数
    //dp[0]=dp[1]=0,因为不够三个
    vector<int> dp(n);
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        //说明能够组成等差数列
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            dp[i] = dp[i - 1] + 1;
            cnt += dp[i];
        }
    }
    return cnt;
}
//优化空间的动态规划
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int last = 0;//前一个数字能组成等差数列的个数
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        //说明能够组成等差数列
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            cnt += last + 1;
            last += 1;
        }
        else
            last = 0;
    }
    return cnt;
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