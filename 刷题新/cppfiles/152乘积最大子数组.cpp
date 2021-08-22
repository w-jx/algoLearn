#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
/*
不能再向求子数组最大和那样处理了
[-2,3,-4]
这个测试用例最大乘积 = (-2)*3*(-4)=24

当前位置的最优解,不一定是前一个位置的最优解转移得到的


找到当前位置的最大乘积fmax
找到当前位置的最小成绩fmin
当前位置的最优解可能是
正数×正数
负数×负数
当前元素

之前的解法忽略了负数×负数的情况

*/
//没有优化空间的
int maxProduct(vector<int>& nums) {
    if (nums.empty())
        return 0;
    int n = nums.size();
    vector<int> dpmax(n);
    vector<int> dpmin(n);
    int maxpro = nums[0];
    dpmax[0] = dpmin[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        dpmin[i] = std::min({ dpmax[i - 1] * nums[i], nums[i], dpmin[i - 1] * nums[i] });
        dpmax[i] = std::max({ dpmax[i - 1] * nums[i], nums[i], dpmin[i - 1] * nums[i] });
        

        maxpro = std::max(dpmax[i], maxpro);
    }
    return maxpro;
}
//优化空间的
int maxProduct2(vector<int>& nums) {

    int n = nums.size();
    int maxpro = nums[0];
    int fmax = nums[0], fmin = nums[0];
    for (int i = 1; i < n; ++i) {
        int premax = fmax;//这边一定要利用premax,否则重复计算
        fmax = std::max({ premax * nums[i],nums[i],fmin * nums[i] });
        fmin = std::min({ premax * nums[i],nums[i],fmin * nums[i] });
        maxpro = std::max(maxpro, fmax);
    }
    return maxpro;
}
void test01()
{
    vector<int> nums{ -4,-3,-2 };
    cout << maxProduct2(nums) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif