#if 0
#include "../headers/wjxHeaders.h"

/*
* 通过
* 
* 我每次的解法都是用rightMax数组,答案题解用单调栈,方法是类似的
* 其实我的思路就是单调栈
* 
* 
思路是首先获得nums2的rightMax数组
其中rightMax[i]存储的是nums2[i]右侧第一个比其大的元素的坐标
然后还需要一个哈希表,存储nums[2]中的每一个元素的对应的坐标

对于nums1,我们一次找到其元素对应在nums2中的下标idx
再利用rightMax[idx]得到结果

*/
//rightMax[i]存右边比nums[i]大的下标,如果没有就是-1
vector<int> getRightMax(vector<int>& nums,int& maxval)
{
	int n = nums.size();
	vector<int> rightMax(n, -1);
	
	for (int i = n - 2; i >= 0; --i) {
		maxval = std::max(maxval, nums[i]);
		if (nums[i] < nums[i + 1]) {
			rightMax[i] = i + 1;
		}
		else if (nums[i] == nums[i + 1])
			rightMax[i] = rightMax[i + 1];
		else {//nums2[i]>nums2[i+1]
			int idx = i + 1;
			while (idx < n && rightMax[idx] < n && rightMax[idx] != -1) {
				if (nums[i] < nums[rightMax[idx]]) {
					rightMax[i] = rightMax[idx];
					break;
				}
				else {
					idx = rightMax[idx];
				}
			}
		}
	}
	return rightMax;
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int maxval = nums2.back();
	//rightMax[i]存右边比nums2[i]大的下标,如果没有就是-1
	vector<int> rightMax = getRightMax(nums2, maxval);
	
	
	vector<int> num_map(maxval+1);
	for (int i = 0; i < n2; ++i)
		num_map[nums2[i]] = i;
	
	vector<int> ret(n1);
	for (int i = 0; i < n1; ++i) {
		int curnum = nums1[i];//当前元素
		int curidx = num_map[curnum];//当前元素在nums数组里面的下标
		int curbig_idx = rightMax[curidx];//比其大的元素下标
		if (curbig_idx == -1)
			ret[i] = -1;
		else
			ret[i] = nums2[curbig_idx];
	}
	return ret;
}
//答案题解的方法,单调栈
vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int maxval = *max_element(nums2.begin(), nums2.end());
	vector<int> ret_hash(maxval + 1,-1);

	vector<int> stk;//单调栈
	stk.reserve(n2);
	for (int i = 0; i < n2; ++i) {
		while (!stk.empty() && stk.back() < nums2[i]) {
			ret_hash[stk.back()] = nums2[i];
			stk.pop_back();
		}
		stk.push_back(nums2[i]);
	}
	//遍历nums1得到结果
	vector<int> ret(n1);
	for (int i = 0; i < n1; ++i) {
		ret[i] = ret_hash[nums1[i]];
	}
	return ret;

}
void test01()
{
	vector<int> nums1{ 1,3,5,2,4 }, nums2{ 6,5,4,3,2,1,7 };
	printVector(nextGreaterElement(nums1, nums2));

}
int main()
{
	test01();
}
#endif