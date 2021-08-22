#if 0
#include "../headers/wjxHeaders.h"
/*
0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6
��Ϊ�˻�С��k��ʱ��,���Ǿͼ������Ҫ���������


���˻�������Ҫ���ʱ��,����
nums[0]*nums[1]*...nums[i-1]<k
nums[0]*nums[1]*...nums[i-1]*nums[i]>=k��
���ǿ��Դ���߿�ʼ�Գ˻����γ��Գ���nums[left],ֱ���˻�����Ҫ��
���Ե�һ��nums[1]*...nums[i-1]*nums[i]
��������ڵ���k,�ٳ���һ��

Ϊʲôans+=right-left+1
[10,5,2,6]
[10]->1
[10,5]->[10],[10,5]->2��
[10,5,2]->[5],[2],[10,5,2](������Ҫ��)->3��
[10,5,2,6]->4��
������һ����right-left+1��,��Ȼǰ����left,right��Χ�ڵ�������˻�����Ҫ��

��Ȼ����һ��ǰ�����������е�nums[i]��������
prod = nums[0]*nums[1]*...nums[i-1]*nums[i]
���㵽iʱ��prod>=k,���Ǿͽ��г���nums[left]
����һ��
prod = nums[1]*...nums[i-1]*nums[i],�����Ƿ���Ҫ���
��һ��prod = nums[1]*...nums[i-1]*nums[i]*nums[i+1]
���õ���û���ж� nums[0]*nums[1]*...nums[i-1]*nums[i]*nums[i+1]
��Ϊnums[0]*nums[1]*...nums[i-1]*nums[i]>=k,nums[i+1]>0,һ��������Ҫ��
*/
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	if (k <= 1)
		return 0;
	int n = nums.size();
	int prod = 1, ans = 0, left = 0;
	for (int right = 0; right < n; ++right) {
		prod *= nums[right];
		while (prod >= k) prod /= nums[left++];
		ans += right - left + 1;
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