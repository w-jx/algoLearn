#if 0
#include "../headers/wjxHeaders.h"

//2021年7月5日不会写.通过,空间复杂度不符合
int firstMissingPositive(vector<int>& nums) {
	set<int> num_set;
	for (const int& num : nums) {
		if (num > 0)
			num_set.insert(num);
	}
	int ret = 1;
	for (const int num : num_set) {
		if (num != ret)
			return ret;
		++ret;
	}
	return ret;
}
/*
答案题解:
数组长度为N,数组里面能出现的正数是[1,N]
那么数组中没有出现的最小正正数是
[1,N+1]范围,因为如果1,N都有的话,就是N+1

将所有在1,N范围内的数字放入哈希表,就可以得到最终的答案

对应数组元素x,如果处于[1,N]范围,就对(x-1)位置标记
遍历结束后,如果所有位置都标记了,那么结果是N+1
否则就是没有标记的位置+1


因为题目给的数组有正有负,我们只关心[1,N]的数字,可以先对数组进行遍历
不在[1,N]的数字修改成任意一个大于N的数字,这样数组中所有的数都是正数了
可以用"负数"进行标记

1.数组中小于1的数修改成N+1
2.遍历数组的数x,可能已经被标记了,
所以对应的数应该是|x|,如果|x|在[1,N]范围,就添加标记改成负数
如果已经是负数,不用重复添加
3.遍历完成了,如果都是负数,结果是N+1
否则答案是第一个正数的位置加1


*/
int firstMissingPositive2(vector<int>& nums) {
	int n = nums.size();
	for (int& num : nums) {
		if (num < 1)
			num = n + 1;
	}
	for (int i = 0; i < n; ++i) {
		int num = abs(nums[i]);
		if (num <= n)//绝对值,肯定在[1,N]范围内了
			nums[num - 1] = abs(nums[num - 1]) * (-1);
	}
	for (int i = 0; i < n; ++i) {
		if (nums[i] > 0)
			return i + 1;
	}
	return n + 1;
}
//别人题解提到的方法,必须用while,不能用if
/*
nums=[4,2,1,9]
i=0,nums[i]=4,可以发现可以交换
第一次交换{4,nums[3]=9}
[9,2,1,4],如果我们这边用if,那么i这个位置的本来应该放1的,就得不到有效处理
因为9<数组长度4
i=1,nums[1]=2,因为nums[1]和nums[2-1]相等,不交换

i=2,nums[2]=1,
swap(1,nums[0]=9),
数组变成了
[1,2,9,4],它同样因为9<4进行下一次循环

i=3,nums[3]=4,因为nums[3]=3+1,所以跳过循环

然后我们发现9不等于i+1,所以返回3

*/
int firstMissingPositive3(vector<int>& nums) {
	int n = nums.size();
	for (int i = 0; i < n; ++i) {
		//防止测试用例是[1,1]
		while (nums[i] > 0 && nums[i] <= n && nums[i]!=i+1&& nums[i]!=nums[nums[i]-1])
			swap(nums[i], nums[nums[i] - 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (nums[i] != (i+1))
			return i+1;
	}
	return n + 1;
}
void test01()
{

}
int main()
{
	test01();
}
#endif