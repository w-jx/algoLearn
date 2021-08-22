#if 0
#include "../headers/wjxHeaders.h"
#include <time.h>
/*
leecode题目介绍:
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

*/

int searchInsert(vector<int>& nums, int target) { //我的写法

	//如果数组为空,或者插入数字小于数组第一个元素的话,那么就是返回位置0
	if (nums.empty() || target<=nums.front()) return 0;
	if (target > nums.back()) return nums.size();
	int left = 0;
	int right = nums.size();

	while (1) {
		int mid = left + (right - left) / 2;
		if (mid == left && mid == right && left == right) break;

		if (nums[mid] == target) return mid;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		if (nums[mid] > target) {
			right = mid;
		}
	}
	
	return left;

}
int searchInsert2(vector<int>& nums, int target) { //答案中优秀写法

	int n = nums.size();
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else r = mid - 1;
	}
	return l;

}

int binary_search(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size();

	while (1) {
		int mid = left + (right - left) / 2; 
		if (mid==left && mid==right && left == right) break;

		if (nums[mid] == target) return mid;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		if (nums[mid] > target) {
			right = mid ;
		}
	}

	return -1;
}
int binary_search2(vector<int>& nums, int target, int left, int right) {

	int mid= left + (right - left) / 2;
	if (mid == left &&mid== right) return -1;
	if (nums[mid] == target) return mid;
	if (nums[mid] < target)  return binary_search2(nums, target, mid + 1, right);
	if (nums[mid] > target) return binary_search2(nums, target, left, mid);
	
}
int binary_search2(vector<int>& nums, int target) {
	
	return binary_search2(nums, target, 0, nums.size());
}

int binary_search3(vector<int>& nums, int target) { //二分搜索  	int right = nums.size()-1; left<=right
	int left = 0;
	int right = nums.size()-1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target)
			left = mid+1;
		else if(nums[mid]> target)
			right = mid-1;
	}
	return -1;
}

int binary_search4(vector<int>& nums, int target) { //二分搜索  int right = nums.size(); left<right
	int left = 0;
	int right = nums.size();

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] == target) return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid ;
	}

	return -1;
}
//2021.2.25
int searchInsert5(vector<int>& nums, int target) {
	int len = nums.size();
	int left = 0, right = len, mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] > left) {
			right = mid;
		}
		else if (nums[mid] < left) {
			left = mid + 1;
		}

	}
	return left;
}
void test01()
{
	srand((unsigned)time(nullptr));
	int k = 10;

	while (k--) {
		vector<int> v;
		int last = 0;
		for (auto i = 0; i < 10; i+=1) {
			int newNum = rand()%125;
			while (newNum <= last) {
				newNum++;
			}
			v.push_back(newNum);
			last = newNum;
		}

		printVector(v);
		int target = v[3] + rand() % 10;
		cout << target <<","<<searchInsert(v, target) << endl;
	}
	/*vector<int> vtest = { 1,3,5,6 };
	cout << searchInsert(vtest, 2) << endl;*/
}
void test02()
{
	vector<int> vtemp = { 1,3,5,6, };
	cout << searchInsert5(vtemp, 7) << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
#endif