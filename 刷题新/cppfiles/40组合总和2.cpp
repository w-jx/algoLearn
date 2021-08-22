#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
vector<int> item;
vector<vector<int> > res;
int sum = 0;
void dfs(vector<int>& nums, int start, int target)
{
	sum = 0;
	for (int i = 0; i < item.size(); ++i)
		sum += item[i];
	if (sum > target)
		return;
	if (sum == target)
		res.push_back(item);
	unordered_set<int> hashset;
	for (int i = start; i < nums.size(); ++i) {
		if (hashset.count(nums[i]) > 0)
			continue;
		hashset.insert(nums[i]);
		item.push_back(nums[i]);
		dfs(nums, i + 1, target);
		item.pop_back();
	}

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	dfs(candidates, 0, target);
	return res;
}
/// <summary>
/// 
/// </summary>
/// <param name="candidates"></param>
/// <param name="target">目标</param>
/// <param name="sum">目前累加和</param>
void dfs2(vector<int>& candidates, int start,int target, int sum)
{
	if (sum > target)
		return;
	if (sum == target) {
		res.push_back(item);
	}
	unordered_set<int> hashset;
	for (int i = start; i < candidates.size(); i++) {
		if (hashset.count(candidates[i]) > 0)
			continue;
		hashset.insert(candidates[i]);
		item.push_back(candidates[i]);
		sum += candidates[i];
		dfs2(candidates, i + 1, target, sum);
		item.pop_back();
		sum -= candidates[i];
	}
	
}
//leetcode 刷题班的解法,上面的问题需要每次重新计算sum?
vector<vector<int>> combinationSum2_2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());//求子集2,不能重复,需要先排序
	dfs2(candidates, 0,target,0);
	return res;
}

void test01()
{
	vector<int> candidates{ 10, 1, 2, 7, 6, 1, 5 };

	auto ret = combinationSum2_2(candidates, 8);
	for (auto iter : ret) {
		for (auto inneriter : iter)
			cout << inneriter << " ";
		cout << endl;
	}
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif