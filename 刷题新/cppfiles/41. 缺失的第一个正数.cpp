#if 0
#include "../headers/wjxHeaders.h"

//2021��7��5�ղ���д.ͨ��,�ռ临�ӶȲ�����
int firstMissingPositive(vector<int>& nums) {
	set<int> num_set;
	for (const int& num : nums) {
		if (num > 0)
			num_set.insert(num);
	}
	int ret = 1;
	for (const int num : num_set) {
		if (num != ret)
			return ret;
		++ret;
	}
	return ret;
}
/*
�����:
���鳤��ΪN,���������ܳ��ֵ�������[1,N]
��ô������û�г��ֵ���С��������
[1,N+1]��Χ,��Ϊ���1,N���еĻ�,����N+1

��������1,N��Χ�ڵ����ַ����ϣ��,�Ϳ��Եõ����յĴ�

��Ӧ����Ԫ��x,�������[1,N]��Χ,�Ͷ�(x-1)λ�ñ��
����������,�������λ�ö������,��ô�����N+1
�������û�б�ǵ�λ��+1


��Ϊ��Ŀ�������������и�,����ֻ����[1,N]������,�����ȶ�������б���
����[1,N]�������޸ĳ�����һ������N������,�������������е�������������
������"����"���б��

1.������С��1�����޸ĳ�N+1
2.�����������x,�����Ѿ��������,
���Զ�Ӧ����Ӧ����|x|,���|x|��[1,N]��Χ,����ӱ�Ǹĳɸ���
����Ѿ��Ǹ���,�����ظ����
3.���������,������Ǹ���,�����N+1
������ǵ�һ��������λ�ü�1


*/
int firstMissingPositive2(vector<int>& nums) {
	int n = nums.size();
	for (int& num : nums) {
		if (num < 1)
			num = n + 1;
	}
	for (int i = 0; i < n; ++i) {
		int num = abs(nums[i]);
		if (num <= n)//����ֵ,�϶���[1,N]��Χ����
			nums[num - 1] = abs(nums[num - 1]) * (-1);
	}
	for (int i = 0; i < n; ++i) {
		if (nums[i] > 0)
			return i + 1;
	}
	return n + 1;
}
//��������ᵽ�ķ���,������while,������if
/*
nums=[4,2,1,9]
i=0,nums[i]=4,���Է��ֿ��Խ���
��һ�ν���{4,nums[3]=9}
[9,2,1,4],������������if,��ôi���λ�õı���Ӧ�÷�1��,�͵ò�����Ч����
��Ϊ9<���鳤��4
i=1,nums[1]=2,��Ϊnums[1]��nums[2-1]���,������

i=2,nums[2]=1,
swap(1,nums[0]=9),
��������
[1,2,9,4],��ͬ����Ϊ9<4������һ��ѭ��

i=3,nums[3]=4,��Ϊnums[3]=3+1,��������ѭ��

Ȼ�����Ƿ���9������i+1,���Է���3

*/
int firstMissingPositive3(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		//��ֹ����������[1,1]
		while (nums[i] > 0 && nums[i] <= n && nums[i]!=i+1&& nums[i]!=nums[nums[i]-1])
			swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (nums[i] != (i+1))
			return i+1;
	}
	return n + 1;
}
void test01()
{

}
int main()
{
	test01();
}
#endif