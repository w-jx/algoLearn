#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
/*
下一个排列总是比当前排列要大,除非当前排列已经是最大的排列
要求:找到下一个大于当前序列的新序列,而且变大的幅度要尽可能小


具体:
左边找较小数,右边找较大数
较小数要尽量靠右,较大数尽量靠左
[4,5,2,6,3,1]
较小数2,较大数3

完成交换 [4,5,3,6,2,1]
完成交换后,原来较大数右边的数,按照升序重新排列,得到
[4,5,3,1,2,6]。

算法具体描述:
从后往前找顺序对(i,i+1),满足a[i]<a[i+1],较小数为a[i]
[i+1,n)下降序列,因为是从后面找的

然后我们再从[i+1,n)从后往前找 下标j,满足a[i]<a[j],较大数为a[j]

交换a[i]和a[j],因为[i+1,n)必然降序(为什么),然后我们反转[i+1,n)就可以让其
变成升序,就不用重新排序了

例如原数组    a e c nums[i] u v w nums[j] x m(a,e,c,u,v,w,x,m代表数字)
nums[i]是较小数,nums[j]是较大数
我们从后面找较小数的时候, 
初始时候 如果x<m ,那么较小数肯定是x了,但是较小数是nums[i],所以
可以得到x>m,同理,u>=v>=w>=nums[j]>=x>=m,直到nums[i]<u
所以可以得到[i+1,n)是降序序列

我们从后面找较大数的时候,如果nums[i]<m的时候,较大数就是m了
而较大数不是m,所以我们可以得到nums[i]>=m
nums[i]>=x,因为nums[j]是较大数,肯定有 nums[i]<nums[j]<=w

我们交换较小数和较大数后
 a e c nums[j] u v w nums[i] x m
 因为w>=nums[j],nums[j]>nums[i],所以w>nums[i]
 所以从[i+1,n)仍然是降序排序,所以,只需要反转就达到了升序排列的效果


*/
void nextPermutation(vector<int>& nums) {
	int i = nums.size()-2;
	while (i >= 0 && nums[i] >= nums[i + 1]) {
		--i;
	}//从这边找较小数 nums[i]<nums[i+1],nums[i]就是较小数
	if (i >= 0) {
		int j = nums.size() - 1;
		while (j >= 0 && nums[j] <= nums[i])
			--j;//nums[j]>nums[i],nums[j]就是较大数
		swap(nums[i], nums[j]);//进行交换
	}
	//反转[i+1,n)
	reverse(nums.begin() + i + 1, nums.end());
	//如果是[3,2,1]这样的,i会变成-1,也就相当于反转数组
	//变成[1,2,3]

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