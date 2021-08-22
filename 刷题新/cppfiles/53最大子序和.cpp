#if 0
#include "../headers/wjxHeaders.h"


/*
��̬�滮

dp[i]�������ǰi�����ֵ���������,��ô���Ƿ���
dp[i]��dp[i-1]û�б�Ȼ��ϵ

��������[-2,1,1,-3,4]

ǰ4�����ֵ���������ȡ[1,1]
ǰ5�����ֵ���������ȡ[4],���Է���ֱ��ȥ�˵��������,û���õ�֮ǰ
4�����ֵ�״̬

�޸Ķ���,dp[i]�����Ե�i�����ֽ�β����������
dp[0]=nums[0]
dp[1] = max(nums[1]+nums1[0],nums[1])
	=max(dp[0]+nums[1],nums[1]);
*/

int maxSubArray(vector<int>& nums) {
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	int maxres = dp[0];

	for (int i = 1; i < nums.size(); ++i) {
		dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		maxres = std::max(dp[i], maxres);
	}
	return maxres;
}

int maxSubArray2(vector<int>& nums) {
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	int maxres = dp[0];

	for (int i = 1; i < nums.size(); ++i) {
		dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		maxres = std::max(dp[i], maxres);
	}
	return maxres;
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