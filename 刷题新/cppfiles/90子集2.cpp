#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。
输入 [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/
vector<vector<int> > res;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<int> temp;//记录走过的路
	sort(nums.begin(), nums.end());
	
	dfs(nums, temp, 0);

	return res;
}
void dfs(vector<int>& nums, vector<int>& temp, int start) {

	res.push_back(temp);
	for (int i = start; i < nums.size(); i++) {
		if (i > start && nums[i] == nums[i - 1])
			continue;
		temp.push_back(nums[i]);

		dfs(nums, temp, i + 1);
		temp.pop_back();
		

	}
}
int main()
{
	system("pause");
	return 0;
}
#endif