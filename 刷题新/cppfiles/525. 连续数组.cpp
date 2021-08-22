#if 0
#include "../headers/wjxHeaders.h"

//下面的结果不对
//[0,0,0,1,1,1,0] 结果是6
//应该是有一个0,就应该有一个1对应
enum STATE {

	ZERO,
	ONE,
	NONE,
};
int findMaxLength(vector<int>& nums) {
	int n = nums.size();
	int state = STATE::NONE;
	int len = 0;
	int maxlen = 0;
	for (const auto& num : nums) {
		switch (state) {
		case ZERO:
			if (num == 1) {
				state = ONE;
				++len;
			}
			else if (num == 0) {
				maxlen = std::max(maxlen, len);
				len = 1;
			
			}
			else {
				state = NONE;
				maxlen = std::max(maxlen, len);
				len = 0;
			}
			break;
		case ONE:
			if (num == 0) {
				state = ZERO;
				++len;
			}
			else if (num == 1) {
				maxlen = std::max(maxlen, len);
				len = 1;
			}
			else {
				state = NONE;
				maxlen = std::max(maxlen, len);
				len = 0;
			}
			break;

		case NONE:
			maxlen = std::max(len, maxlen);
			if (num == 0) {
				state = ZERO;
				++len;
			}
			else if (num == 1) {
				state = ONE;
				++len;
			}
			break;
		}
	}
	maxlen = std::max(maxlen, len);
	if (maxlen%2==0)
		return maxlen;
	return maxlen - 1;
}
//这个是错误的
void test01()
{
	vector<int> nums{ 1,0,2,0,1,0,1,3,4,5,0,1,0,1,0,1,2,3 };
	cout << std::format("maxlen:{}\n", findMaxLength(nums));
}
/*

 1 1 1 1 1 0 0 0 1
 答案题解:
 0的数目和1的数目相同,等价于0的数目减去1的数量为0

 将数组中的0看成-1,求连续的0的和
 原问题转换:求最长的连续子数组,元素和为0

 1.将数组转换成新数组(0改成-1)
 2.求前缀和数组

 p_sum[k]-p_sum[j]==0

 1 1 1  [2]
 1 1 1 1 1[4]
 所以长度为j-k,找到最大的即可

 这样暴力解法会超时


 实际上,不需要创建新数组,也不要创建前缀和数组
 只需要一个变量counter 存储新数组的前缀和就行了
 利用哈希表存储每个前缀和第一次出现的下标
 规定空的 结束下标-1,元素和为0
 哈希表先存储{0,-1}

 对于每个下标i:
 如果counter已经存在,则取出之前的下标preIdx
 从preIdx+1到下标i的子数组有相同数量的0,1
 长度为i-preIdx

 如果counter不存在,将counter和i存入哈希

*/
//暴力解法写出来再说
int findMaxLength2(vector<int>& nums) {
	unordered_map<int, int> mp;
	int counter = 0;
	mp[counter] = -1;
	int n = nums.size();
	int maxlength = 0;
	for (int i = 0; i < n; ++i) {
		int num = nums[i];
		if (num == 1)
			++counter;
		else
			--counter;
		if (mp.count(counter)) {
			int preIdx = mp[counter];
			maxlength = std::max(maxlength, i - preIdx);
		}
		else
			mp[counter] = i;
	}
	return maxlength;
}
int main()
{
	test01();
}


#endif