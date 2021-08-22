#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//2021��5��20�ղ���,�������
/*
ֻ��һ������,͵�Ը÷���
ֻ��2������,͵�Խ��ϸߵ�

����͵���˵�һ������,����͵�����һ������
͵�Եķ�Χ���ǵ�һ�����䵽�����ڶ�������
�±���[0,n-2]

�����͵�Ե�һ������,��͵�����һ������
͵�Եķ�Χ���ǵڶ������䵽���һ������
�±���[1,n-1]

[start,end]��Χ����͵��,dp[i]����[start,i]��͵�Ե���߽��
dp[i]=std::max(dp[i-2]+nums[i],dp[i-1])
�߽�����:
	dp[start]=nums[start];ֻ��һ������
	dp[start+1]=std::max(nums[start],nums[start+1]);����������

�ֱ�ȥ[start,end]=[0,n-2]
��[start,end]=[1,n-1]���м���,ȡ����dp[end]�����ֵ

*/
//��״̬ѹ����
int getMax(vector<int>& nums, int start, int end, int n) {
    vector<int> dp(n);
    dp[start] = nums[start];
    dp[start + 1] = std::max(nums[start], nums[start + 1]);

    for (int i = start + 2; i <= end; ++i) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
}
//״̬ѹ����
int getMax(vector<int>& nums, int start, int end, int n) {
    vector<int> dp(n);
    int first = nums[start];
    int second = std::max(nums[start], nums[start + 1]);
    int amount = first;
    for (int i = start + 2; i <= end; ++i) {
        amount = std::max(first + nums[i], second);
        first = second;
        second = amount;
    }
    return amount;
}
int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return std::max(nums[0], nums[1]);
    int n = nums.size();
    int first = getMax(nums, 0, n - 2, n);
    int last = getMax(nums, 1, n - 1, n);

    return std::max(first, last);

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