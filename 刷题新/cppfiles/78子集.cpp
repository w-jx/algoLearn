#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

nums = [1,2,3]
子集：
[ [],[1],[2],[3],[1,3],[2,3],[1,2],[1,2,3] ] 一共是8个

而[1,2]的子集
[ [],[1],[2],[1,2] ]

两个结果相减：
subset([1,2,3]) - subset([1,2])= [3],[1,3],[2,3],[1,2,3]，就是在subset([1,2])每个集合加3

如果A=subset([1,2]),那么subset([1,2,3])=A中的每个元素加3

方法2：回溯算法

*/
//方法1 是递归方法，数学归纳法
vector<vector<int>> subsets(vector<int>& nums) {
	if (nums.empty()) return { {} };
	int n = nums.back();//取出最后一个元素
	nums.pop_back();//取出最后一个元素

	auto res = subsets(nums);//先算出前面元素的子集
	int len = res.size();//因为1，2，3的子集是1，2的子集
	for (int i = 0; i < len; i++) {
		res.push_back(res[i]);
		res.back().push_back(n);
		/*
		原数组					子集
		空：					[[]]
		1					1.将原来的再加到res后面  [ [],[]]
							2.尾的元素加上前一种情况的元素个数（0的时候个数为1，只有一个空集）
								所以变成 [[],[1]]
		2.					1.先把原来的加到res后面，依次加 [[],[1],[]],然后再添加前
							一种情况的元素个数（1的时候个数为2） [[],[1],[2]]
							2.继续添加  [[],[1],[2],[1]] ,再尾巴添加一个2也就是最终结果为
							[[],[1],[2],[1,2] ]
		*/
	}
	return res;
}
vector<vector<int>> res;
void dfs(vector<int>& nums, int start, vector<int>& track)
{
	res.push_back(track);
	for (int i = start; i < nums.size(); i++) {
		//做选择
		track.push_back(nums[i]);
		//回溯
		dfs(nums, i + 1, track);//千万记住是i+1而不是 start+1
		track.pop_back();//撤销选择
	}
}


vector<vector<int>> subsets2(vector<int>& nums)
{
	vector<int> track;//记录走过的路线
	dfs(nums, 0, track);
	return res;

}
// 方法3 位运算
vector<vector<int>> subsets3(vector<int>& nums)
{
	int all_set = 1<< nums.size();//设置 全部集合的最大值+1；

	for (int i = 0; i < all_set; ++i) {
		std::vector<int> item;
		for (int j = 0; j < nums.size(); ++j) {
			if (i & (1 << j)) //001->c  010->b 100->a 
				item.push_back(nums[j]);
			/*
			构造数字I 代表的集合，各元素存储到item中
			整数i代表从0到2^n-1 一共2^n个集合
			1<<j 构造 nums数组的第j个元素，若i & (1 << j)就把nums[j]放进去
			例如 A=100 4 B=010 2 C=001 1 
			*/
		}
		res.push_back(item);
	}
	return res;

}
void test01()
{
	int a = 1 << 3;
	cout << a << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif