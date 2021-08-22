#if 0

#include "../headers/wjxHeaders.h"
//���Ǳ�������
/*
�ҵ��뷨
����target �����Ǹ���
��Ͳ�����
*/
int findTargetSumWays(vector<int>& nums, int target) {
	int n = nums.size();
	//dp[i][j]����ǰi��Ԫ���ܹ����j�ķ�����
	//��󷵻�dp[n][target]
	vector<vector<int> > dp(n + 1, vector<int>(target + 1));


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= target; ++j) {
			if (j - nums[i - 1] < 0 || j+nums[i-1]>target) {
				dp[i][j] = 0;
			}
			else {
				dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j + nums[i - 1]];
			}
		}
	}

	return dp[n][target];
}


int dfs(vector<int>& nums, int idx, int target) {
	if (idx < 0)
		return 0;
	if (idx == 0) {
		int items = 0;
		if (nums[0] == target)
			++items;
		if (nums[0] + target == 0)
			++items;
		return items;
	}
	if (nums[idx] == 0)
		return dfs(nums, idx - 1, target);
	return dfs(nums, idx - 1, target - nums[idx]) + dfs(nums, idx - 1, target + nums[idx]);
}
//�ڶ��γ���
int findTargetSumWays2(vector<int>& nums, int target) {
	
	int n = nums.size();
	if (n < 2) {
		int items = 0;
		if (nums[0] == target)
			++items;
		if (nums[0] + target == 0)
			++items;
		return items;

	}
	if (nums.back() == 0)
		return dfs(nums, n - 2, target);
	return dfs(nums, n - 2, target -nums.back()) + dfs(nums, n - 2, target + nums.back());
}

void backtrace(vector<int>& nums,int idx, int const &target, int sum,int &times) {
	if (idx == nums.size()) {
		if (sum == target)
			++times;
		return;
	}
	backtrace(nums, idx + 1, target, sum + nums[idx], times);
	backtrace(nums, idx + 1, target, sum - nums[idx], times);
}
//�����Ļ��ݽⷨ
/*
���ݽⷨ���ǲ��ϵݹ�,���ÿһ������num,+num����-num�Ľ��
������ʱ��Ƚ�sum�Ƿ����target

*/
int findTargetSumWays3(vector<int>& nums, int target) {
	int times = 0;
	backtrace(nums, 0, target, 0,times);
	return times;
}

/*
�����Ķ�̬�滮
�൱��
����Ԫ�صĺ� + ����Ԫ�صĺ� = target
�������ĺ�Ϊsum,����Ԫ�صĺ�Ϊneg
������Ԫ�صĺ�Ϊ  sum-neg
(sum-neg) - neg = target
	neg = (sum-target)/2

sum,neg���ǷǸ�����,neg Ҳ�ǷǸ�����
sum-target �ǷǸ�ż��,�����ϵĻ�������Ϊ0	

������Ŀת����:��������ѡȡ���ɸ���,ʹ��Ԫ��֮��Ϊneg
dp[i][j]����������nums��ǰi��Ԫ����ѡȡԪ��,ʹ��Ԫ�غ�Ϊj�ķ�����

û��Ԫ�ؿ�ѡ��ʱ��:�߽�����
dp[0][j]=1 (j=0)
dp[0][j]=0(j>0)

��������ĵ�i��Ԫ��num(��1����)
����j=[0,neg],����dp[i][j]
	���j<num,����ѡnum
	dp[i][j] = dp[i-1][j]

	���j>=num,�����ѡnum,������dp[i-1][j]
			���ѡnum,������dp[i-1][j-num]
	dp[i][j] = dp[i-1][j] + dp[i-1][j-num]

״̬ת�Ʒ��̳�����:
				dp[i-1][j]   (j<num)
	dp[i][j] = 
				dp[i-1][j] + dp[i-1][j-num] (j>=num)
*/
int findTargetSumWays4(vector<int>& nums, int target) {
	int n = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	int neg = sum - target;
	if (neg < 0 || neg % 2 != 0)
		return 0;
	neg /= 2;
	vector<vector<int> > dp(n + 1, vector<int>(neg + 1));

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i) {
		int num = nums[i - 1];
		for (int j = 0; j <= neg; ++j) {
			if (j < num) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
			}
		}
	}
	return dp[n][neg];
}
void test01()
{
	vector<int> nums(5,1);
	cout << findTargetSumWays2(nums, 3) << endl;
}
int main()
{
	//test01();
	vector<int> v;
	//1074731823
	cout << v.max_size() << endl;

}


#endif