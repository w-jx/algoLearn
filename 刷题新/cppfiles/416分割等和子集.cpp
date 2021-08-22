#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


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
//�Ӽ�
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
//�Ӽ���
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
//���������Ķ�̬�滮�ķ���,�ռ临�Ӷ�O(n��target)
bool canPartition(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0)//������,�޷��ֳ�2����
		return false;
	int target = sum / 2;
	int maxelem = *max_element(nums.begin(), nums.end());
	//���ֵ����һ��,ʣ�µ�һ��С��һ��,�޷����
	if (maxelem > target)
		return false;
	//dp[i][j]�����nums[0:i]ѡȡ���ɸ�������
	//�Ƿ����һЩѡȡ����,ʹ�ñ�ѡȡ����������Ϊj
	vector<vector<int> > dp(n, vector<int>(target + 1));
	/*
	��ѡȡ�κ���,��������Ϊ0,��Ȼ���� dp[i][0]=true
	ͬʱ,���ֻѡȡһ����dp[0][nums[0]]=true


	j>=nums[i],����nums[i],����ѡȡҲ���Բ�ѡȡ

	��ѡȡnums[i],dp[i][j] = dp[i-1][j]
	ѡȡnums[i],dp[i][j] = dp[i-1][ j-nums[i] ]
	�����������һ��Ϊtrue,dp[i][j]=true

	���j<nums[i],����nums[i],����dp[i][j]�͵���j�޷�ѡȡ
	nums[i]
	���dp[i][j]=dp[i-1][j]

	*/
	//dp[i][j]����nums[i]�ܷ���ɺ�Ϊֵj
	
	for (int i = 0; i < n; ++i) {
		//��ɺ�Ϊ0,��һ�����Ե�,ֻҪ��ѡԪ�ؼ���
		dp[i][0] = 1;
	}
	dp[0][nums[0]] = 1;

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= target; ++j) {
			if (j >= nums[i]) {
				if (dp[i - 1][j] == 1 || dp[i - 1][j - nums[i]] == 1)
					dp[i][j] = 1;
				//���д��Ҳ������ 
				// dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n - 1][target];

}
//�Ż��ռ临�Ӷ�
//����dp[i][j]��ֻ��dp[i-1]��һ���й�ϵ
/*
j>=nums[i]:
	 dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num[i]];
j<nums[i]:
	dp[i][j] = dp[i - 1][j];
���԰����������ͳһ��
	dp[j] = dp[j]|dp[j-nums[i]]




*/
bool canPartition2(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)//�޷����
		return false;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 != 0)//������,�޷��ֳ�2����
		return false;
	int target = sum / 2;
	int maxelem = *max_element(nums.begin(), nums.end());
	//���ֵ����һ��,ʣ�µ�һ��С��һ��,�޷����
	if (maxelem > target)
		return false;
	vector<int> dp(target + 1);
	dp[0] = true;//���0,ֻҪ��ѡ���ǿ��Ե�
	for (int i = 0; i < n; ++i) {
		//�������Ӵ�С����
		//�����С����,����dp[j]��ʱ��,dp[j-nums[i]]�Ѿ���������
		//��������һ�е�dpֵ,Ҫ����һ�е�dp[i-1][j-nums[i]],dp[i-1][j]������dp[i][j]
		for (int j = target; j >= nums[i]; --j)
			dp[j] = dp[j] | dp[j - nums[i]];
	}
	return dp[target];
	
}
//�����Ӽ��ķ�������ʱ
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