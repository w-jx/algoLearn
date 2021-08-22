#if 0
#include "../headers/wjxHeaders.h"
/*
0 < nums.length <= 50000
0 < nums[i] < 1000
0 <= k < 10^6
因为乘积小于k的时候,我们就计算符合要求的子数组


但乘积不符合要求的时候,例如
nums[0]*nums[1]*...nums[i-1]<k
nums[0]*nums[1]*...nums[i-1]*nums[i]>=k了
我们可以从左边开始对乘积依次除以除了nums[left],直到乘积符合要求
除以第一次nums[1]*...nums[i-1]*nums[i]
如果还大于等于k,再除以一次

为什么ans+=right-left+1
[10,5,2,6]
[10]->1
[10,5]->[10],[10,5]->2个
[10,5,2]->[5],[2],[10,5,2](不符合要求)->3个
[10,5,2,6]->4个
窗口数一定是right-left+1个,当然前提是left,right范围内的子数组乘积符合要求

当然还有一个前提条件是所有的nums[i]都是正数
prod = nums[0]*nums[1]*...nums[i-1]*nums[i]
计算到i时候prod>=k,我们就进行除以nums[left]
除了一次
prod = nums[1]*...nums[i-1]*nums[i],假如是符合要求的
下一次prod = nums[1]*...nums[i-1]*nums[i]*nums[i+1]
不用担心没有判断 nums[0]*nums[1]*...nums[i-1]*nums[i]*nums[i+1]
因为nums[0]*nums[1]*...nums[i-1]*nums[i]>=k,nums[i+1]>0,一定不符合要求
*/
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	if (k <= 1)
		return 0;
	int n = nums.size();
	int prod = 1, ans = 0, left = 0;
	for (int right = 0; right < n; ++right) {
		prod *= nums[right];
		while (prod >= k) prod /= nums[left++];
		ans += right - left + 1;
	}
	return ans;

}
void test01()
{

}
int main()
{
	test01();
}
#endif