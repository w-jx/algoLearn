#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
红黑树 是一种平衡二叉树，平衡二叉树又是一种二叉搜索树
题目：在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于k

|nums[i]-nums[j]|<=t
|i-j|<=k

*/
//方法1：直接求解
/*
维护一个k大小的滑动窗口，这种情况，条件2一直满足
我们只要去判断条件1是否满足就行了


*/
bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = max(i - k, 0); j < i; ++j) {
            long long numi = nums[i];
            long long numj = nums[j];
            long long mynum = abs(numi - numj);
            if (mynum <= t)
                return true;
        }
    }
    return false;
}
bool containsNearbyAlmostDuplicate2(std::vector<int>& nums, int k, int t) {
    if (nums.empty() || k < 0 || t < 0) return false;

    set<long long > myset;//防止溢出
    for (int i = 0; i < nums.size(); ++i) {
        auto lower = myset.lower_bound(nums[i]);//返回首个大于等于目标元素的迭代器
        if (lower != myset.end() && *lower <= nums[i] + t) return true;

        auto upper = myset.upper_bound(nums[i]);//upper_bound返回的是<=目标元素的最大元素的后一个元素（即大于目标元素的最小元素）

        if (upper != myset.begin() && nums[i] <= *(--upper) + t) return true;//(--upper)是为了构造小于等于目标元素的数字
        //注意比较是和begin比较

        myset.insert(nums[i]);
        if (myset.size() > k)//树的大小超过了k,移除最早加入树的那个元素
            myset.erase(nums[i - k]); 
    }
    return false;
}
void test01()
{
    cout << log(16) / log(2) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif