#if 0
#include "../headers/wjxHeaders.h"
/*



*/
//我的错误的解法,[3,6,5,1,8]输出15,应该是18
int maxSumDivThree(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n);//dp[i]代表到元素i,能被3整除的元素最大和
    vector<int> visit(n);
    if (nums[0] % 3 == 0) {
        dp[0] = nums[0];
        visit[0] = 1;
    }
    bool find = false;
    for (int i = 1; i < n; ++i) {
        if ((dp[i - 1] + nums[i]) % 3 == 0) {
            dp[i] = dp[i - 1] + nums[i];
            visit[i] = 1;
            find = true;
        }
        else {
            for (int j = 0; j < i; ++j) {
                if (visit[j] == 0 && (dp[i - 1] + nums[i] + nums[j]) % 3 == 0) {
                    dp[i] = dp[i - 1] + nums[i]+nums[j];
                    visit[j] = 1;
                    visit[i] = 1;
                    find = true;
                }
            }
        }//else
        if (!find) {
            dp[i] = dp[i - 1];
        }
        find = false;
       
    }
    return dp[n - 1];


}
//leetcode 可以理解的题解
int maxSumDivThree2(vector<int>& nums) {

    /*
题目要求挑选出的子数组(不要求连续)的和能够被三整除，且最大。
我们可以先贪心的累加所有数字的和，然后从中剔除一些数字使得其能够被三整除。
具体来说，如果整个数组的和恰好能够被三整除，那我们不需要做任何操作，直接返回。
如果最后的累加和sumsum modmod 3 == 1, 那我们可以有2种方式让其能够被3整除:
    1.剔除一个数组中满足mod3==1，且近可能小的数
    2.剔除两个数组中满足mod3==2，且近可能小的数
如果最后的累加和sumsum modmod 3 == 2, 那我们可以有2种方式让其能够被3整除:
    1.剔除一个数组中满足mod3==2，且近可能小的数
    2.剔除两个数组中满足mod3==1，且近可能小的数
最后取上面方案的最大值
    */
    int n = nums.size();
    int sum = 0;
    vector<int> one, two;
    for (int num : nums) {
        if (num % 3 == 1)
            one.push_back(num);
        if (num % 3 == 2)
            two.push_back(num);
        sum += num;
    }
    int res = sum % 3;
    if (res == 0)
        return sum;
    int ans = 0;
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    if (res % 3 == 1) {
        if (one.size() > 0)
            ans = std::max(ans, sum - one[0]);
        if (two.size() > 1)
            ans = std::max(ans, sum - two[0] - two[1]);
    }
    else if (res % 3 == 2) {
        if (two.size() > 0)
            ans = std::max(ans, sum - two[0]);
        if (one.size() > 1)
            ans = std::max(ans, sum - one[0] - one[1]);
    }
    return ans;


}
void test01()
{
    vector<int> nums{ 3,6,5,1,8 };
    cout << maxSumDivThree2(nums) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif