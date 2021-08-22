#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 1);//dp[i]代表以nums[i]结尾的LIS长度
	vector<int> count(n , 1);//count[i]以nums[i]结尾的LIS的个数

/*
在nums[i] > nums[j]前提下，如果在[0, i-1]的范围内，找到了j，使得dp[j] + 1 > dp[i]，
说明找到了一个更长的递增子序列。
那么以j为结尾的子串的最长递增子序列的个数,就是最新的以i为结尾的子串的最长递增子序列的个数
即：count[i] = count[j]。


在nums[i] > nums[j]前提下，如果在[0, i-1]的范围内，找到了j，使得dp[j] + 1 == dp[i]
说明找到了两个相同长度的递增子序列
那么以i为结尾的子串的最长递增子序列的个数 就应该加上以j为结尾的子串的最长递增子序列的个数，
即：count[i] += count[j];
*/

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j]) {

				if (dp[j] + 1 > dp[i]) {//第一次找到
					dp[i] = dp[j] + 1;//更新dp[i]
					count[i] = count[j];
				}
				else if (dp[j] + 1 == dp[i]) {
					count[i] += count[j];
				}
			}
		}
	}
	//获得最长子序列的长度
	int maxlen = *std::max_element(dp.begin(), dp.end());
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (dp[i] == maxlen)
			res += count[i];
	}
	return res;
}
void test01()
{
	vector<int> nums{ 1,2,4,3,5,4,7,2 };
	//vector<int> nums{ 1,2,4,3};
	cout << findNumberOfLIS(nums) << endl;




	

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif