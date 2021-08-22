#if 0
#include "../headers/wjxHeaders.h"

/*
例如
17/5=3...2
12/5=2...2
17-12=5 能被5整除,所以除以一个数余数相同的两个数的差能被这个数整除

同余定理
大多数语言的处理方式都与 C/Java 一致，采用了 truncate 除法。所以在 C/Java 语言中:
-17 % 10 的计算结果如下：r = (-17) - (-17 / 10) x 10 = (-17) - (-1 x 10) = -7
17 % -10 的计算结果如下：r = 17 - (17 / -10) x (-10) = (17) - (-1 x -10) = 7
-17 % -10 的计算结果如下：r = (-17) - (-17 / -10) x (-10) = (-17) - (1 x -10) = -7

-17%5正常的应该是
=-17-(-17/5)*5=-17-(-15)=-2,是个负数
我们给它修正为整数
(-2+5)%5=3;

找到另外一个数是23 
23%5=3

23-(-17) = 40,是5的倍数,验证了算法的正确性
*/
int subarraysDivByK(vector<int>& nums, int k) {
	unordered_map<int, int> hashmap;
	hashmap[0] = 1;//考虑了前缀和本身被 K 整除
	int cnt = 0;
	int n = nums.size();
	int pre = 0, remain = 0;

	/*
	如果pre是整数,k是整数

	 (pre%k+k)%k
	=pre%k%k+k%k
	=pre%k+0
	=pre%k
	整数对k的余数一定是小于k的,小于k的数对k取余,一定是其自身
	k%k取余是0,所以对正数是不影响的
	
	*/

	for (int i = 0; i < nums.size(); ++i) {
		pre += nums[i];
		//remain = pre % k,考虑负数情况的存在
		remain = (pre % k + k) % k;//保证余数是正的
		//当前的余数是remain,如果哈希表里面已经有余数是remain了,那么
		//两段之差就是k的整数倍
		if (hashmap.count(remain) > 0) {
			cnt += hashmap[remain];
		}
		hashmap[remain]++;
	}
}
//尝试用数组代替hash,尝试失败!!!
int subarraysDivByK2(vector<int>& nums, int k) {
	int n = nums.size();
	int maxelem = *max_element(nums.begin(), nums.end());

	vector<int> hashmap(maxelem%2);
	hashmap[0] = 1;
	int pre = 0;//保存前缀和的
	int remain = 0;//保存余数的
	int cnt = 0;//保存子数组的个数的

	for (int i = 0; i < n; ++i) {
		pre += nums[i];
		remain = (pre % k + k) % k;
		cnt += hashmap[remain];
		hashmap[remain]++;
	}
	return cnt;
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