#if 0
#include "../headers/wjxHeaders.h"
/*回溯算法
leecode题目介绍:
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。




*/
void dfs(int n, int k, int start, vector<int>& temp);
vector<vector<int>> res;
/// <summary>
/// 给定整数n,和k,返回1....n中所有k个数的组合
/// </summary>
/// <param name="n">n是给的数字上限，1-n</param>
/// <param name="k">k个数的组合</param>
/// <returns>返回组合</returns>
vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) return res;
    vector<int> temp;
    dfs(n, k, 1,temp);
    return res;
}
void dfs(int n, int k, int start,vector<int>& temp) {
    
    if (k == temp.size()) {
        res.push_back(temp);
        return;
    }
    //从start 开始递增，不是从0，是从1
    for (int i = start; i <= n; i++) {
        //做选择
        temp.push_back(i);
        dfs(n, k, i + 1, temp);
        temp.pop_back();
    }
 
}
void test01()
{

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif