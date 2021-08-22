#if 0
#include "../headers/wjxHeaders.h"


//��Ϊ��ת���ˣ��ֳ�������������
//��һ������Сֵ��һ�����ڵڶ��������ֵ
//����ԭ�������� 0,1,2,4,5,6,7   ��ת����4��5��6��7 //0,1,2
//�����������򣬵�һ����Сֵ4Ҳ���ڵڶ�����������ֵ2
int search(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		//midֵ���������һ���Ǻ�left��һ�����飻�ڶ��֣�left������1��mid������2
		//����ͨ��nums[mid]   nums[left] ��С�ж������1���������2
		if (nums[mid] == target) return mid;
		if (nums[mid] >= nums[left]) {//left,mid��ͬһ����������
			if (target >= nums[left] && target < nums[mid]) //Ŀ����[nums[left],nums[mid])֮��
				right = mid - 1;//��һ����С�ռ�
			else if (target > nums[mid] || target < nums[left]) {
				//target ����right ��mid ֮��  �������ڵ�һ�����飬Ҳ�����ڵڶ�������
				//���� 4��5��6��7��8  | 0��1��2  midָ���Ԫ��Ϊ7
				//���target ��8����ô����nums[mid]���ڵ�һ��������
				//���target ��1����ôС��nums[left]���ڵڶ���������
				left = mid + 1;
			}

		}
		else if (nums[mid] < nums[left]) { //left������1��mid������2��
			if (target <= nums[right] && target > nums[mid]) {
				left = mid + 1;//��һ����С����
			}
			else if (target > nums[right] || target < nums[mid]) {
				//���������������һ�֣�target������2�����Ķ����ˣ�˵��target ����������1��
				//�ڶ��֣�target ��nums[mid]С��Ҳ������������2��
				//������һ�֣���Ҫ���Ҳ�ָ���С
				right = mid - 1;

			}
		}

	}
	return -1;
}
//2021��5��12�� ��ϰ����
int search2(vector<int>& nums, int target) {
	int left = 0, right = nums.size()-1, mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		//left,mid��ͬ��������
		if (nums[mid] >= nums[left]) {
			if (target >= nums[left] && target < nums[mid]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		//left,mid���ڲ�ͬ������
		else if (nums[mid] < nums[left]) {
			if (target > nums[mid] && target <= nums[right]) {
				left = mid + 1;
			}
			else
				right = mid;
		}
	}//while
	if (left < nums.size() && nums[left] == target)
		return left;
	return -1;
}
void test01()
{
	vector<int> nums{3,1};
	cout << search2(nums, 2) << endl;
}
int main(void)
{

	test01();

	system("pause");
	return 0;

}
#endif