#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
//死记硬背 还没有完全理解的代码
vector<vector<int> > res;//保存最终的结果
vector<int> item;//这个保存了中间某一次排列的结果
void dfs(vector<int>& nums, int idx, int len) {
    if (idx == len) {
        res.push_back(nums);
    }
    set<int> myset;
    for (int i = idx; i < len; ++i) {
        if (myset.find(nums[i]) != myset.end())
            continue;
        myset.insert(nums[i]);
        swap(nums[i], nums[idx]);
        dfs(nums, idx + 1, len);
        swap(nums[i], nums[idx]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    dfs(nums, 0, nums.size());
    return res;
}
/// <summary>
///  item 一次排列结果,res最终结果
/// </summary>
/// <param name="nums">原数组</param>
/// <param name="visit">标记是否已经选择过</param>
/// <param name="len">nums的长度</param>
void backtrace(vector<int>& nums, vector<int>& visit,int &len ) {
    if (item.size() == len) {
        res.push_back(item);
        return;
    }
    /*
    * 题解链接,解释为什么要加visit[i-1]==0
    https://leetcode-cn.com/problems/permutations-ii/solution/47hui-su-jian-zhi-zhong-fu-shu-by-bu-zhi-h7dm/
    */
    for (int i = 0; i < len; ++i) {
//这个代码要结合46全排列标记数组的来看,第一次标记[1,0,0]后
//第二次把第二个数字当成第一个数字的时候,标记已经归零,变成[0,1,0]了,
// 如果此时第一个数字和第二个数字,相同,并且第一个数字还没有访问,说明在同一层,需要剪枝
// 
//剪枝发生在同一层决策中面临多个选择，如果两个选择之后的决策树一致，那么就剪掉一个，重点在于是否在同一层
        if (visit[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == 0))
            continue;////剪枝,visit[i-1]==0 保证确实是在同一层发生了重复的选择
        //visit[i]已经选择过了,或者visit[i]和visti[i-1]都没有访问过
        item.push_back(nums[i]);
        visit[i] = 1;
        backtrace(nums, visit, len);
        item.pop_back();//撤销选择
        visit[i] = 0;
    }
}
vector<vector<int>> permuteUnique2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> visit(n);
    backtrace(nums, visit,n);
    return res;
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