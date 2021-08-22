#if 0
#include "../headers/wjxHeaders.h"

/*
方法1 无优化动态规划
dp[i][j]为以a[i],a[j]为最后两个元素的等差数列的长度
最后两个数定了,那么前一个数target
有
	target-a[i]=a[i]-a[j]
		target = 2*a[i]-a[j]
a[i],a[j]确定了,那么只要找的i前面最靠近i的target位置即可
dp[i][j] = dp[target][i]+1;
*/
//超时的解法,n3的时间复杂度
int longestArithSeqLength(vector<int>& nums) {
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 0;
	//相当于连续的三个数是nums[k] ,nums[i],nums[j]
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			for (int k = i - 1; k >= 0; k--) {
				if (nums[k] == target) {
					dp[i][j] = dp[k][i] + 1;
					break;
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}
//利用哈希表降低时间复杂度
int longestArithSeqLength2(vector<int>& nums) {
	int n = nums.size();
	unordered_map<int, int> hashmap;
	/*   for (int i = 0; i < n; ++i)
		   hashmap[nums[i]] = i;*/
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			if (hashmap.find(target) != hashmap.end()) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
//哈希表降低一些无用的计算量,少运算大约(n-2)次
int longestArithSeqLength3(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	unordered_map<int, int> hashmap;
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 2;
	hashmap[nums[0]] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			if (hashmap.find(target) != hashmap.end()) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
//题目说明了0 <= A[i] <= 10000,用数组代替哈希表
//时间复杂度进一步下降
int longestArithSeqLength4(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	/*
	* 全局变量数组,自动初始化为0
	注意:局部变量数组,只能全部初始化为0,其他数
	例如-1只会把第一个初始化为-1
	memset(hashmap, -1, sizeof(hashmap));
	*/
	int hashmap[10001];
	memset(hashmap, -1, sizeof(hashmap));
	vector<vector<int>> dp(n, vector<int>(n, 2));
	int ans = 2;
	hashmap[nums[0]] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int target = 2 * nums[i] - nums[j];
			if (target>=0 && hashmap[target]!=-1) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
			}
			ans = max(ans, dp[i][j]);
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
//在4的基础上,i<n-1,降低一些运算次数,超过百分之91的人了
int longestArithSeqLength4(vector<int>& nums) {
	int n = nums.size();
	if (n < 3)
		return n;
	//dp[i][j]代表nums[i],nums[j]为等差数列的后两个元素
	//的等差数列的长度,初始化为2,因为至少有nums[i],nums[j]
	//两个元素
	vector<vector<int> > dp(n, vector<int>(n, 2));
	int hashmap[10001];
	memset(hashmap, -1, sizeof(hashmap));
	hashmap[nums[0]] = 0;
	/*
		target-nums[i]=nums[i]-nums[j]
			target =nums[i]*2-nums[j]
	*/
	int ans = 2;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int target = nums[i] * 2 - nums[j];
			if (target >= 0 && hashmap[target] != -1) {
				dp[i][j] = dp[hashmap[target]][i] + 1;
				ans = std::max(ans, dp[i][j]);
			}
		}
		hashmap[nums[i]] = i;
	}
	return ans;
}
void test01()
{

}
int main()
{
	test01();
}
#endif