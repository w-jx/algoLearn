#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。



*/
vector<vector<int>> res;
vector<int> item;
void dfs(vector<int>& nums, int idx, int len);
vector<vector<int>> permute(vector<int>& nums) {
    int len = nums.size();
    dfs(nums, 0, len);
    return res;
}
/*
[1,2,3]
idx 代表当前要填第几个位置,初始从第0个位置开始填,idx=0
每个位置都是可以分别用每个元素来填

首先用第0个元素填第0个位置[1...],剩下的两个位置只能用[2,3]来填
然后开始填第1个位置,idx=1,所以下标int i = idx=1开始,因为只能从[2,3]中选,
显然第一个位置 用第1个元素来填[1,2..],剩下的一个位置只能用[3]来填


然后开始填第2个位置,idx=2,下标int i=idx=2,因为只能从[3]中选择
[1,2,3]下面填充第3个位置

idx=3

我们发现3==len,这就是一个结果之1,

dfs(nums,3,len)执行结束
swap(nums[i],nums[idx]),此时idx=2,i=2,相当于不交换
进入下一次for循环,i=3
swap(nums[3],nums[2]),也就是用元素3填充第1个位置,[1,3..]
dfs(nums,3,len),J进入以后我们发现

*/
void dfs(vector<int>& nums, int idx, int len) {
    if (idx == len) {
        res.push_back(nums);
        return;
    }
    //使得数组里面的每个元素分别成为数组里面的第一个元素
    for (int i = idx; i < len; i++) {
     
        swap(nums[i], nums[idx]);
        dfs(nums, idx + 1, len);
        swap(nums[i], nums[idx]);
    }
}
void generate(vector<int>& nums, int usedcnt, vector<int>& visit) {
    if (usedcnt == nums.size()) {
        res.push_back(item);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visit[i] == 0) {
            visit[i] = 1;
            item.push_back(nums[i]);
            generate(nums, usedcnt + 1, visit);
            item.pop_back();
            visit[i] = 0;
        }
    }
}
//leetcode 答案题解,使用一个数组标记已经访问过的数字
//时间复杂度增加,但是输出按照字典序输出
vector<vector<int>> permute2(vector<int>& nums) {
    vector<int> visit(nums.size());//标记是否访问过
    generate(nums, 0, visit);
    return res;

}

void helper(vector<int>& nums, vector<int>& used) {

    if (item.size() == nums.size()) {//如果item的size达到nums.size()
        res.push_back(item);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] == 0) {//下一次遍历当前元素的used[i]变成1了
            item.push_back(nums[i]);
            used[i] = 1;//这个位置用过了
            helper(nums, used);//进入下一次遍历
            item.pop_back();//把当前
            used[i] = 0;
        }
    }
}
//2021年5月27日复习,不会写
vector<vector<int>> permute3(vector<int>& nums) {
    int n = nums.size();
    vector<int> used(n);
    helper(nums, used);

    return res;

}

void test01()
{
    vector<int> nums{ 1,2,3 };
    printvectorvector(permute(nums));
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif