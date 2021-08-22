#if 0
#include "../headers/wjxHeaders.h"

/*
1.最大值在原数组中
2.最大值在环形数组中
    A[0],A[N-1]一定会被选中,同时说明在A[1],A[N-2]子数组肯定有负数
    因此只要把A[1]到A[N-2]的负数的最小和求出来

    然后用数组的和-负数最小和就得到了环形数组的最大和

最后再比较即可

*/
int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int cur = nums[0], res = nums[0];

    int sum = nums[0];//数组的和
    for (int i = 1; i < n; ++i) {
        cur = std::max(cur + nums[i], nums[i]);
        res = std::max(res, cur);
        sum += nums[i];
    }//上面求的是非环形数组的最大和

    //下面求nums[1]到nums[2]的最小负数和
    int cur1 = nums[0];
    int res1 = 0;
    for (int i = 1; i < n - 1; ++i) {
        cur1 = std::min(cur1 + nums[i], nums[i]);
        res1 = std::min(cur1, res1);
    }

    return std::max(res, sum - res1);

}
void test01()
{
    vector<int> nums{ 5,-3,5 };
    cout << maxSubarraySumCircular(nums) << endl;
}
int main()
{
	test01();
}
#endif