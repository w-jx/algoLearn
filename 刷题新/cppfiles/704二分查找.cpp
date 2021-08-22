#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
int binarySearch(vector<int> nums, int target)
{
	int l = 0;
	int r = nums.size();
	int mid = 0;
	while (1) {
		mid = l + (r - l) / 2;

		if (l == r) break;
		if (nums[mid] == target) return mid;
		if (nums[mid] < target) l = mid + 1;
		if (nums[mid] > target)r = mid - 1;
	}
	return -1;
}

int binary_find(vector<int> a, int left, int right, int data)
{

	int mid = left + (right - left) / 2;
	//cout << "left=" << left << ",right=" << right << ",mid=" << mid << endl;

	if (left == right) return -1;
	if (mid == left && mid == right) return -1;
	if (a[mid] == data) return mid;
	if (a[mid] > data)  return binary_find(a, left, mid, data);
	if (a[mid] < data) return binary_find(a, mid + 1, right, data);

}


//查找一个数的二分查找，最简单的版本 模板1
/*
找到了，返回下标，找不到-1
*/
int wenjx_binary_search_1(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len - 1,mid=0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return -1;
}
//模板2 
int wenjx_binary_search_2(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len , mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target) {
			left = mid +1;
		}
		else if (nums[mid] > target)
			right = mid;
	}
	if (left != len && nums[left] == target)
		return left;
	return -1;
}
//模板3 
int wenjx_binary_search_3(vector<int>& nums, int target) {
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len-1, mid = 0;
	while (left+1 < right) { //退出条件：left+1==right,left,right两个元素没检查
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target) {
			left = mid;
		}
		else if (nums[mid] > target)
			right = mid;
	}
	if (nums[left] == target) return left;
	if (nums[right] == target) return right;
	return -1;
}
void test01()
{
	vector<int> v;
	/*for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}*/
	v.push_back(5);

	
	//cout << binarySearch(v, 5) << endl;
	cout << binary_find(v, 0, v.size(), 5);
}
//对于模板1，基本的二分查找，有缺陷
/*
nums = [1,2,2,2,3]，target 为 2
想要找到 target的左侧边界 1或者右侧边界3 ，就不方便了
*/
//查找左侧边界的 二分查找 常见版 right=len,while(left<right）
int binary_search_left(vector<int>& nums, int target)
{
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len, mid = 0;
	while (left < right) { //跳出区间的时候left==right,搜索区间[left,left),搜索区间为空，可能错过left这个位置的元素
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			right = mid;//缩小右边界
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target)
			right = mid;
	}
	if (left != len && nums[left] == target)
		return left;
	return -1;
}
//查找左边界的 二分查找 修改版本  right=len-1,while (left<=right)
int binary_search_left2(vector<int> const& nums, int target)
{
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			right = mid - 1;//收缩右边界
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target)
			right = mid - 1;
	}
	if (left < len && nums[left] == target)
		return left;
	return -1;
}
//下面是查找右侧边界的版本 分别是常用版和修改版
int binary_search_right(vector<int>& nums, int target)
{
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len, mid = 0;
	while (left < right) {//跳出区间时候left==right,搜索区间[left,left)为空，
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			left = mid+1;//缩小左边界
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target)
			right = mid;
	}
	if (left>0 && nums[left - 1] == target)
		return left - 1;//mid找到了，nums[mid]==target,mid=left-1
	return -1;//while 循环终止条件 left==right   所以right-1也行 left的区间为[0，len]
}
//寻找右侧边界的修改版 
int binary_search_right2(vector<int> const& nums, int target) //right=len-1,while(left<=right)
{
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0, right = len - 1, mid = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			left = mid +1;//收缩右边界
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target)
			right = mid - 1;
	}//当 target 比所有元素都小时，right 会被减到 -1，所以需要在最后防止越界
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}



//学习 二分查找学习
void test02()
{
	vector<int> v{ 1,2,4,7,10,25,38,42 };
	cout << wenjx_binary_search_1(v, 7) << endl;
	cout << wenjx_binary_search_2(v, 7) << endl;
	cout << wenjx_binary_search_3(v, 7) << endl;

	cout << "-------------------------------------------左边界的寻找:\n";
	//左边界的寻找
	vector<int> nums{ 1,2,2,2,3 };
	cout << binary_search_left(nums, 2) << endl;
	nums.clear();
	nums.assign({ 1,2,2,3,3,3,3,4,5,7 });
	cout << binary_search_left(nums, 3) << endl;

	cout << binary_search_left2(nums, 3) << endl;

	cout << "-------------------------------------------右边界的寻找:\n";
	cout << binary_search_right(nums, 3) << endl;

	cout << binary_search_right2(nums, 3) << endl;


	cout << "--------------------------------------------------特殊测试\n";
	nums.clear();
	nums.assign({ 1 });


	cout << binary_search_left(nums, 0) << endl;
	cout << binary_search_right(nums, 0) << endl;
}
//寻找左右边界
void test02()
{

}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
#endif