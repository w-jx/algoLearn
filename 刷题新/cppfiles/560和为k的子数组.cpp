#if 0
#include "../headers/wjxHeaders.h"
/*
前缀和
*/
/*
这是我写的前缀和方法,虽然用到了前缀和
时间复杂度仍然是O(n^2),空间复杂度O(n)
仍然是超时的
*/
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> segmentSum(n);
    segmentSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        segmentSum[i] = nums[i] + segmentSum[i - 1];
    }
    int cnt = 0;
    if (segmentSum[0] == k)
        ++cnt;
    for (int i = 1; i < n; ++i) {
        if (segmentSum[i] == k)
            ++cnt;
        for (int j = 0; j < i; ++j) {
            if (segmentSum[i] - segmentSum[j] == k)
                ++cnt;
        }
    }//
    return cnt;
}
/*
前缀和加hashmap
/细节，这里需要预存前缀和为 0 的情况，会漏掉前几位就满足的情况
        //例如输入[1,1,0]，k = 2 如果没有这行代码，则会返回0,漏掉了1+1=2，和1+1+0=2的情况
        //输入：[3,1,1,0] k = 2时则不会漏掉
        //因为presum[3] - presum[0]表示前面 3 位的和，所以需要map.put(0,1),垫下底

     pre[i]代表到下标i的前缀和
     pre[i]=pre[i-1]+nums[i],是到下标i-1的前缀和加nums[i]

     假如从j-i的连续数组和为k
     则 pre[i]-pre[j-1]=k;因为要包括nums[j]所以是j-1
     我们可以通过移项得到符合连续数组和等于k的下标j的值
     pre[j-1]=pre[i]-k,pre[i]是到当前元素的前缀和
     然后我们判断hashmap种是否有pre[i]-k,就可以知道这段连续数组和
     是否等于k,加上pre[j-1]的次数即可
     

*/
int subarraySum1(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> hashmap;
    hashmap.insert({ 0,1 });//防止k==nums[i]
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        //当前的前缀和为sum,如果有sum-k的前缀和,那我们就能
        //确定有区间的前缀和是k,就是符合要求的
        if (hashmap.count(sum - k) > 0)
            cnt += hashmap[sum - k];

        hashmap[sum]++;
    }

    return cnt;
}
void test01()
{
    vector<int> nums{ 3,4,7,2,-3,1,4,2 };
    cout<<subarraySum1(nums,7) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif