#if 0
#include "../headers/wjxHeaders.h"

//方法1-单指针法
/*
第一次遍历，先把0放在数组首，利用一个下标（指针）来记录0的位置
第二次遍历，把1放在0的后边
*/
void sortColors(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1)
		return;
	int idx = 0;
	for (int i = 0; i < len; i++) {
		if (nums.at(i) == 0) {
			swap(nums[i], nums[idx]);
			++idx;
		}	
	}
	for (int i = idx; i < len; i++) {
		if (nums.at(i) == 1) {
			swap(nums[i], nums[idx]);
			++idx;
		}
	}

}
//双指针法
void sortColors2(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1)
		return;
	int p0 = 0, p1 = 0;
	for (int i = 0; i < len; i++) {
		if (nums[i] == 1) {
			swap(nums[i], nums[p1]);
			p1++;
			continue;
		}
		if (nums[i] == 0) {
			swap(nums[i], nums[p0]);
			if (p0 < p1)
				swap(nums[i], nums[p1]);
			p0++;
			p1++;
			continue;
		}

	}
}
//单指针法
void test01()
{
	vector<int> v{ 0,2,2,1,1,0,1,2,1 };
	sortColors(v);
	printVector(v);
}
//双 指针法
void test02()
{
	vector<int> v{ 0,2,2,1,1,0,1,2,1 };
	sortColors2(v);
	printVector(v);
}
int main()
{
	//test01();//单指针法
	test02();//双指针法
	system("pause");
	return 0;
}


#endif