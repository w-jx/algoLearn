#if 0
#include "../headers/wjxHeaders.h"


/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] 。

请找出其中最小的元素。

数组中的最后一个元素x
最小值右侧的元素(不包括元素x),一定严格小于x
最小值左侧的元素,一定要个大于x
左边界left,右边界right,中点mid

比较nums[mid]和nums[right]有三种情况
1.nums[mid]<nums[right],说明nums[mid]是最小值右侧的元素
	可以省略区间的右半部分
2.nums[mid]>nums[right],说明nums[mid]是最小值左侧的元素
	可以省略区间的左半部分
3.nums[mid]==nums[right]数组元素各不相同,所以这种情况不存在

*/
int findMin(vector<int>& nums) {

	int len = nums.size();
	int left = 0, right = len;
	while (left < right) {
		int mid = (left + right) / 2;;
		if (nums[mid] > nums[mid + 1])
			left = mid + 1;
		else
			right = mid;
	}
	return nums[left];

}
//2021年5月20日复习不会,看的题解
int findMin2(vector<int>& nums) {
	if (nums.size() == 1 || nums.front() < nums.back())
		return nums[0];
	int left = 0, right = nums.size() - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] > nums[mid + 1])
			return nums[mid + 1];
		else if (nums[mid] < nums[mid - 1])
			return nums[mid];

		if (nums[mid] > nums[0])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}
void test01()
{
	vector<int> v = { 9,12,17,1,3,5,7 };
	cout << findMin(v) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif