#if 0
#include "../headers/wjxHeaders.h"

int findLength(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	//dp[i][j]代表到[1..i]nums1,[1,..j]num2的子数组的长度
	vector<vector<int> > dp(n1+1, vector<int>(n2+1));
	int maxlen = 0;
	for (int i = 1; i <= n1; ++i) {
		for (int j = 1; j <= n2; ++j) {
			if (nums1[i - 1] == nums2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			}
			
		}
	}
	return dp[n1][n2];
}
/*
如果nums[i]==nums2[j]
	nums1[i:]和nums2[j:]的最长公共子数组
dp[i][j]=dp[i+1][j+1]+1;
否则
dp[i][j]=0;

因为前一个要通过后一个算出来,所以先求
dp[n1][n2]

*/
//动态规划的方法,题解
int findLength(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	
	
}
//滑动窗口的方法,题解
int findLength(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	//dp[i][j]代表到[1..i]nums1,[1,..j]num2的子数组的长度
	vector<vector<int> > dp(n1 + 1, vector<int>(n2 + 1));
	int maxlen = 0;
	for (int i = n1 - 1; i >= 0; --i) {
		for (int j = n2 - 1; j >= 0; --j) {
			if (nums1[i] == nums2[j])
				dp[i][j] = dp[i + 1][j + 1] + 1;
			else
				dp[i][j] = 0;
			maxlen = std::max(maxlen, dp[i][j]);
		}
	}
	return maxlen;
}
void test01()
{

	vector<int> nums1{ 1, 0, 0, 0, 1, 0, 0, 1, 0, 0 };
	vector<int> nums2{ 0, 1, 1, 1, 0, 1, 1, 1, 0, 0 };
	cout << findLength(nums1, nums2) << endl;;
}
int main()
{
	test01();
}
#endif