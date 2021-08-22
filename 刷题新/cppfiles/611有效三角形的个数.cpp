#if 0
#include "../headers/wjxHeaders.h"
/*
亚马逊面试题,我遇到了,没写出来啊
*/

//暴力解法,o(n^3)超时
bool isTriangle(int first, int second, int third) {
    return first + second > third && first + third > second && second + third > first;
}
int triangleNumber(vector<int>& nums) {
    if (nums.size() < 2)
        return 0;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int first = 0;
    int cnt = 0;
    while (first < n - 2) {
        for (int second = first + 1; second < n - 1; ++second) {
            for (int third = n - 1; third > second; --third) {
                if (isTriangle(nums[first], nums[second], nums[third])) {
                    ++cnt;
                }
            }
        }//second
        ++first;
    }//whilf first<n-2
    return cnt;
}
//仍然超时
int triangleNumber2(vector<int>& nums) {
    if (nums.size() < 2)
        return 0;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int first = 0;
    int cnt = 0;
    while (first < n - 2) {
        for (int second = first + 1; second < n - 1; ++second) {
            auto iter = lower_bound(nums.begin() + second+1, nums.end(), nums[first] + nums[second]);

            for (auto it = nums.begin() + second+1; it != iter; it++) {
                if (isTriangle(nums[first], nums[second], *it))
                    ++cnt;
            }
        }//second
        ++first;
    }//whilf first<n-2
    return cnt;
}
int triangleNumber2(vector<int>& nums) {
    if (nums.size() < 2)
        return 0;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int cnt = 0;
    //因为排序过的,我们判断a+b>c即可,如果nums[first]=0,不论如何a+b>c都不满足
    for (int first = 0; first < n - 2; ++first) {
        for (int second = first + 1; second < n - 1 && nums[first]!=0; ++second) {
            auto third = lower_bound(nums.begin() + second + 1, nums.end(), nums[first] + nums[second]);
            cnt += third - nums.begin() - 1 - second;
        }
    }
    return cnt;
}
void test01()
{
    vector<int> nums{ 0,0,0 };
    cout << triangleNumber2(nums) << endl;;
}
int main()
{
	test01();
}
#endif