#if 0
#include "../headers/wjxHeaders.h"
/*
����ѷ������,��������,ûд������
*/

//�����ⷨ,o(n^3)��ʱ
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
//��Ȼ��ʱ
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
    //��Ϊ�������,�����ж�a+b>c����,���nums[first]=0,�������a+b>c��������
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