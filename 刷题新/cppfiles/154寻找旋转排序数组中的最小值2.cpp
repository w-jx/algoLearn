#if 0
#include "../headers/wjxHeaders.h"
/*
�������һ��Ԫ��x
��Сֵ��ߵ�Ԫ��,�����ڵ���x
��Сֵ�ұߵ�Ԫ��,��С�ڵ���x

[left,right]�������,�Ƚ�nums[mid]��nums[right]
1.nums[mid]<nums[right]
	˵��nums[mid]��ȷ������Сֵ�Ҳ�,[mid+1,right]������Ժ���
	��[left,mid]������Сֵ

2.nums[mid]>nums[right]
	˵��nums[mid]������Сֵ�����,[left,mid]������Ժ���
	��[mid+1,right]����Сֵ
3.nums[mid]==nums[right]
	�����޷��ж�nums[mid]���״�����Сֵ����໹���Ҳ�
	������Ϊnums[mid]��nums[right]����ȵ�,���ǿ��Ժ���right�����
	��Ϊ
	1.������Сֵ����right��,��ô�����������䲻��Ҫ��right
	2.������Сֵ����nums[right],����������������û��right,���ǵ����仹��
	nums[mid],���ǵ�ֵ���
	��˿��Ժ���right�����



*/
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < nums[right])
            right = mid;
        else if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        else if (nums[mid] == nums[right])
            right -= 1;
        }
    return nums[left];
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