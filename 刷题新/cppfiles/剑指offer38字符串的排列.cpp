#if 0
#include "../headers/wjxHeaders.h"
/*
解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：
1、路径：也就是已经做出的选择。
2、选择列表：也就是你当前可以做的选择。
3、结束条件：也就是到达决策树底层，无法再做选择的条件。

result = []
def backtrack(路径, 选择列表):
	if 满足结束条件:
		result.add(路径)
		return

	for 选择 in 选择列表:
		做选择
		backtrack(路径, 选择列表)
		撤销选择

*/
//x是下标
void dfs(string s, int x,vector<string > &res)
{
	if (x == s.size() - 1) {
		res.push_back(s);//排列完成了
		return;
	}
	set<int> st;
	for (int i = x; i < s.size(); i++) {
		if (st.count(s[i]) > 0) continue;//重复了，因此剪枝
		st.insert(s[i]);

		swap(s[i], s[x]);//交换，将s[i] 固定在第x 位上
		dfs(s, x + 1,res); //其核心就是 for 循环里面的递归，在递归调用之前「做选择」，在递归调用之后「撤销选择
		swap(s[i], s[x]);//恢复交换
	}
}
vector<string> permutation(string s) {
	
	vector<string > res;
	dfs(s, 0,res);

	return res;
}



void test01()
{
	string str = "abc";
	auto res = permutation(str);
	for (auto iter : res) {
		cout << iter << " ";
	}
	cout << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif