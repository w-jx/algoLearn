#if 0
#include "../headers/wjxHeaders.h"
/*
对于[1,3],将数组铺开
[1 3 3 3]
1:1/4
3:3/4
前缀和数组:
[1,4]

0_1_2_3_4

[0,1)的概率和取到下标0的概率是一样的

取到下标1 和取到[1,4)范围内的概率也是一样的

取下标的问题就转换成了取某一个和的问题,要注意使用随机数产生器
取到的和target ,需要使用二分法来找到最近的一个前缀和
大于target 的下标



题目： 给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，
它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

思路：因为选取下标i的概率与w[i]成正比，先计算出w[i]的和，即所有i的权重之和，
再在这个权重和的范围内随机取值。然后根据取得的数值确定其对应的i的位置。

更新w数组，用于存储累计和，即截至当前数字累计的权重。原地更新w (不新建数组) 以节省空间。
在“权重之和”（即w[-1])内随机获取数字target。
因为w存储的是截至当前数字累计的权重，查找到target应插入的位置，就可以确认这个元素原来所在的位置。
代码


*/
class Solution {
public:
    Solution(vector<int>& w):p_sum(std::move(w)){
        partial_sum(p_sum.begin(), p_sum.end(), p_sum.begin());
        sum = p_sum.back();//和

    }
    //使用随机数产生器取到的和 target，
    //需要使用二分法来找到最近的一个前缀和大于 target 的的下标。
    int pickIndex() {
        //得到需要的前缀和
        int target = (rand() % sum)+1;
        //利用二分查找逐步搜索
        int left = 0, right = p_sum.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            //如果前缀和小了,就需要把左指针往右移动
            //等于情况也不行,相当于碰到了下一个区间的起始位置
            if (p_sum[mid] <= target) {
                left = mid + 1;
            }
            else
                right = mid;
        }
        return left;

    }
private:
    vector<int> p_sum;
    int sum;
};

void test01()
{
    vector<int> nums{ 1,2,3,4,5 };
    vector<int> ret(5);
    partial_sum(nums.begin(), nums.end(), ret.begin());
    printVector(ret);
}
int main()
{
    test01();
}


#endif