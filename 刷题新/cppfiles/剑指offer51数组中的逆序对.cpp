#if 0
#include "../headers/wjxHeaders.h"

//利用归并排序方法
//前提条件：left,mid有序，mid+1,right有序
int mergeAndCount(vector<int>& nums, vector<int>& temp,int left, int mid, int right)
{
	std::copy(nums.begin() + left, nums.begin() + right+1, temp.begin()+left);
	int i = left, j = mid + 1,count=0;
	for (int k = left; k <= right; k++) {
		if (i == mid + 1) {//第一个数组到尽头了，只能从第二个开始加了
			nums[k] = temp[j++];
			//count += (mid - i + 1);//这个时候i已经等于mid+1,所以可以省略
		}
		else if(j==right+1){//第二个数组到尽头
			nums[k] = temp[i++];
		}

		else if (temp[i] <= temp[j]) {
			nums[k] = temp[i++];
		}
		else if (temp[i]>temp[j]){
			nums[k] = temp[j++];
			count += (mid-i+1);//第一个数组里剩余的元素个数
		}
	}
	return count;
}
//从[left,right]区间计算逆序对
int mergeSort2(vector<int>& nums,vector<int> &temp, int left, int right)
{
	if (left >= right) return 0;//只有一个元素，一定不存在
	int mid = left + (right - left) / 2;
	

	int leftPairs = mergeSort2(nums, temp,left, mid);
	int rightPairs = mergeSort2(nums, temp,mid + 1, right);

	int crossPairs = mergeAndCount(nums, temp, left, mid, right);

	return leftPairs + rightPairs + crossPairs;
}
/// <summary>
/// 求数组的逆序对
/// </summary>
/// <param name="nums">给定数组</param>
/// <returns>逆序对</returns>
int reversePairs(vector<int>& nums)
{
	int len = nums.size();
	if (len < 2) return 0;//只有一个元素,没有逆序对
	vector<int> vtemp(len);
	return mergeSort2(nums, vtemp, 0, len - 1);
	
}
void mergeArray(vector<int>& nums, int left, int mid, int right);
//归并排序
void mergeSort(vector<int>& nums,int left,int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		mergeArray(nums, left, mid, right);
	}
}
void mergeArray(vector<int>& nums, int left, int mid, int right)
{
	int leftidx = left, rightidx = mid + 1;
	vector<int> temp;
	while (leftidx <= mid && rightidx <= right) {
		if (nums[leftidx] <= nums[rightidx]) {
			temp.push_back(nums[leftidx++]);
		}
		else
			temp.push_back(nums[rightidx++]);
	}
	while (leftidx <= mid)
		temp.push_back(nums[leftidx++]);
	while (rightidx <= right)
		temp.push_back(nums[rightidx++]);
	for (int i = left, j = 0; i <= right; i++, j++)
		nums[i] = temp[j];
}
void test01()
{
	vector<int> v{ 1,6,2,44,10,5 };
	mergeSort(v, 0, v.size() - 1);
	printVector(v);
}
void test02()
{
	vector<int> v{7,5,6,4,10,20,3,6,29,78,98 };
	cout << reversePairs(v) << endl;
}
int main()
{
	//test01();//归并排序复习
	test02();

	system("pause");
	return 0;
}
#endif