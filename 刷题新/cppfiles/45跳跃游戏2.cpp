#if 0
#include "../headers/wjxHeaders.h"

//int jump(vector<int>& nums) {
//
//    int jumptime = 0, maxIndex = 0, nextPos = 0, curPos = 0;
//    while (curPos < nums.size()) {
//        for (int temp = curPos; temp < curPos + nums[curPos]; ++temp) {
//            if (nums[temp] + temp > maxIndex) {
//                maxIndex = nums[temp] + temp;
//                nextPos = temp;
//            }
//        }
//        curPos = maxIndex;
//        ++jumptime;
//    }
//    return jumptime;
//}
//跳跃游戏2 
int jump(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;//数组长度小于2不用跳跃
	int current_max_index = nums[0];//当前可达到的最远位置
	int pre_max_max_index = nums[0];//遍历各个位置，可以达到的最远位置

	int jump_min = 1;
	/*
	idx		0 1 2 3 4
	nums	2 3 1 1 4
cur_idx		2 4 3 4 8
		首先最开始跳跃次数为1,因为我们数组元素2个以上的时候,至少要跳一次
		我们也要从第2个元素开始遍历数组

		首先最开始可以到达的位置为2,所以下标j遍历数组的时候,当j<=2的时候
		不需要增加跳跃次数,这都是目前第一次跳跃能到的范围

		当j==3的时候,1次跳跃最多只能到2,所以只能跳跃了,增加跳跃次数
		同时把能去的最远的位置更新下,可以看到在第一次跳跃过程中,能去最远的下标为
		4

		接着便利,我们可以发现数组j<=4始终成立,所以 跳跃次数就是2

	*/
	for (int j = 1; j < nums.size(); ++j) {
		if (j > current_max_index) {//无法再向前移动了，才进行跳跃
			jump_min++;//更新当前可到达的最远位置
			current_max_index = pre_max_max_index;
		}
		if (pre_max_max_index < nums[j] + j)
			pre_max_max_index = nums[j] + j;
	}
	return jump_min;
}
//2021年5月16日 复习错误
int jump2(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;//数组长度小于2不用跳跃
	int times = 1;
	int cur_idx = 1, pre_max_idx = nums[0], max_max_idx = nums[0];
	while (cur_idx < nums.size()) {
		if (cur_idx == pre_max_idx) {
			++times;
			pre_max_idx = max_max_idx;
		}
	
		max_max_idx = std::max(max_max_idx, cur_idx + nums[cur_idx]);
		++cur_idx;
	}
	return times;
}
void test01()
{
	vector<int> nums{ 0 };
	cout << jump2(nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif