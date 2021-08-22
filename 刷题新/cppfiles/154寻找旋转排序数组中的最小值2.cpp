#if 0
#include "../headers/wjxHeaders.h"
/*
对于最后一个元素x
最小值左边的元素,都大于等于x
最小值右边的元素,都小于等于x

[left,right]区间检索,比较nums[mid]和nums[right]
1.nums[mid]<nums[right]
	说明nums[mid]的确处于最小值右侧,[mid+1,right]区间可以忽略
	在[left,mid]中找最小值

2.nums[mid]>nums[right]
	说明nums[mid]处于最小值的左侧,[left,mid]区间可以忽略
	在[mid+1,right]找最小值
3.nums[mid]==nums[right]
	我们无法判断nums[mid]到底处于最小值的左侧还是右侧
	但是因为nums[mid]和nums[right]是相等的,我们可以忽略right这个点
	因为
	1.假如最小值不在right上,那么我们搜索区间不需要有right
	2.假如最小值就是nums[right],即便我们搜索区间没有right,我们的区间还有
	nums[mid],它们的值相等
	因此可以忽略right这个点



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