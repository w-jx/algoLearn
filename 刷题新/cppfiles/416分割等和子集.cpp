#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
vector<vector<int> >res;
vector<int> item;
vector<int> sumvec;
int sum;
void helper(vector<int>& nums,int idx)
{
	res.push_back(item);

	for (int i = idx; i < nums.size(); ++i) {
		item.push_back(nums[i]);
		helper(nums, i+1);
		item.pop_back();
	}

}
//子集
vector<vector<int> > partition(vector<int>& nums) {
	 helper(nums, 0);
	 return res;
}
void helper2(vector<int>& nums, int idx)
{
	sumvec.push_back(sum);

	for (int i = idx; i < nums.size(); ++i) {
		sum += nums[i];
		helper2(nums, i + 1);
		sum -= nums[i];
	}

}
//子集和
vector<int> partitionsum (vector<int>& nums) {
	helper2(nums, 0);
	return sumvec;

}


void findhalf(vector<int>& nums, int idx,int sum,int target,bool flag) {
	if (sum == target)
		flag= true;
	for (int i = idx; i < nums.size(); ++i) {
		sum += nums[i];
		findhalf(nums, i + 1, sum, target,flag);
		sum -= nums[i];
	}
}
//答案题解里面的动态规划的方法,空间复杂度O(n×target)
bool canPartition(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0)//是奇数,无法分成2部分
		return false;
	int target = sum / 2;
	int maxelem = *max_element(nums.begin(), nums.end());
	//最大值大于一半,剩下的一定小于一半,无法拆分
	if (maxelem > target)
		return false;
	//dp[i][j]代表从nums[0:i]选取若干个正整数
	//是否存在一些选取方案,使得被选取的正整数和为j
	vector<vector<int> > dp(n, vector<int>(target + 1));
	/*
	不选取任何数,正整数和为0,显然成立 dp[i][0]=true
	同时,如果只选取一个数dp[0][nums[0]]=true


	j>=nums[i],对于nums[i],可以选取也可以不选取

	不选取nums[i],dp[i][j] = dp[i-1][j]
	选取nums[i],dp[i][j] = dp[i-1][ j-nums[i] ]
	这两种情况有一种为true,dp[i][j]=true

	如果j<nums[i],对于nums[i],所以dp[i][j]和等于j无法选取
	nums[i]
	因此dp[i][j]=dp[i-1][j]

	*/
	//dp[i][j]代表到nums[i]能否组成和为值j
	
	for (int i = 0; i < n; ++i) {
		//组成和为0,是一定可以的,只要不选元素即可
		dp[i][0] = 1;
	}
	dp[0][nums[0]] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= target; ++j) {
			if (j >= nums[i]) {
				if (dp[i - 1][j] == 1 || dp[i - 1][j - nums[i]] == 1)
					dp[i][j] = 1;
				//这个写法也可以是 
				// dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n - 1][target];

}
//优化空间复杂度
//发现dp[i][j]都只和dp[i-1]上一行有关系
/*
j>=nums[i]:
	 dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num[i]];
j<nums[i]:
	dp[i][j] = dp[i - 1][j];
可以把这两种情况统一成
	dp[j] = dp[j]|dp[j-nums[i]]




*/
bool canPartition2(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)//无法拆分
		return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0)//是奇数,无法分成2部分
		return false;
	int target = sum / 2;
	int maxelem = *max_element(nums.begin(), nums.end());
	//最大值大于一半,剩下的一定小于一半,无法拆分
	if (maxelem > target)
		return false;
	vector<int> dp(target + 1);
	dp[0] = true;//组成0,只要不选就是可以的
	for (int i = 0; i < n; ++i) {
		//这个必须从大到小计算
		//如果从小到达,计算dp[j]的时候,dp[j-nums[i]]已经被更新了
		//不再是上一行的dp值,要用上一行的dp[i-1][j-nums[i]],dp[i-1][j]来更新dp[i][j]
		for (int j = target; j >= nums[i]; --j)
			dp[j] = dp[j] | dp[j - nums[i]];
	}
	return dp[target];
	
}
//先求子集的方法铁超时
void test01()
{
	vector<int> nums{ 1,5,11,5};
	cout << canPartition(nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif