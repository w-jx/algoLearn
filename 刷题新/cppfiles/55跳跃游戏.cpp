#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

�������õķ�����̰���㷨�������Ƕ�̬�滮

*/

/// <summary>
/// �ж��Ƿ��ܴӵ�һ���±���Ծ����������һ���±�
/// </summary>
/// <param name="nums">�Ǹ���������</param>
/// <returns>�Ƿ��ܵ����һ���±�</returns>
bool canJump(vector<int>& nums) {
	/*
	��һ����ȷ��״̬ ����n = nums.size();
		��������ʯͷi ��Ծ��n-1����ô�϶�����
		1.������ʯͷi��
		2.i+a[i]>=n-1 
	��������� �ܷ�����iʯͷ��

	�ڶ�����ת�Ʒ���
		f[j] �����ܲ�������ʯͷj��
	f[j] =OR( 0<=i<j����ö��jʯͷ֮ǰ��ʯͷi) (f[i) && i+a[i]>=j)
		Ҳ����������ʯͷi�ϣ�����������ʯͷj�ϵ�����

	���������߽������ͳ�ʼֵ
	f[0]=true ��Ϊ��ʼ��ʱ����ڵ�һ����

	���Ĳ�������˳��
	�ȼ���f[1],�ټ���f[2]���Դ�����
	
	*/
	vector<bool> dp(nums.size(), false);
	dp.front() = true;
	int n = nums.size();
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < j; ++i) {
			if (dp[i] && i + nums[i] >= j) {
				dp[j] = true;
				break;
			}
		}
	}
	return dp[n - 1];
}
//̰���㷨
bool canJump2(vector<int>& nums)
{
	std::vector<int> index(nums.size(),0);//��Զ������λ��
	for (int i = 0; i < nums.size(); ++i) {
		index[i] = i + nums[i];
	}
	int jump = 0;
	int max_index = index[0];
	//jump ����Խ��,���������±�
	//ֱ��jump���������β ���� ��Խ�˵�ǰ����������Զλ��
	//����������2 0 0 0 ....
	//���Կ����ӵ�һ��λ��(�±�Ϊ0)�����Ե��������λ��(�±�2)
	/*
		2 0 0 0 ..
		2 1 2 3  
		������jump�������� ������0��ʱ��,��Ȼ��ʾ������Զ���Ե��±�3
		����ʵ�������Ǵ��±�0��λ�� ��Զֻ�ܵ��� �±�2 ,���
		jump>max_index,���������������ʧ�ܵ�
		������ȥ��� jump�ǲ��Ǵ���ԭ����ĳ���,�����ж��ǲ����ܵ������
		һ��λ����	
	*/
	while (jump < nums.size() && jump <= max_index) {
		if (max_index < index[jump])
			max_index = index[jump];
		++jump;
	}
	
	return jump >= nums.size();


}
//2021��5��16��,��Ҫindex������,ֱ���ڱ�����ʱ����¼���
bool canJump(vector<int>& nums) {
	int jump = 0, max_index = nums[0];
	while (jump < nums.size() && jump <= max_index) {
		max_index = std::max(max_index, jump + nums[jump]);
		++jump;
	}
	return jump >= nums.size();
}
void test01()
{
	vector<int> nums{ 2,3,1,1,4 };
	cout<<canJump2(nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif