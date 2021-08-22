#if 0
#include "../headers/wjxHeaders.h"

/*
169是一样的,但是169题
题目保证一定有超过数组一般数量的元素
本题如果不存在,就返回-1,

直观的想法还是所谓投票法,两辆相消,用一个变量记录出现次数
*/

int majorityElement(vector<int>& nums) {

    if (nums.empty())
        return -1;
    //3 2 3 
    //3 2 1 
    //6 5 5
    int major = nums.front();
    int times = 0;
    int pre = major;
    for (const int& num : nums) {
        if (num == major) {
            ++times;
        }
        else {
            --times;
            if (times == 0) {
                major = num;
                times = 1;
            }
        }
    }
    int cnt = 0;
    for (const int& num : nums) {
        if (num == major)
            ++cnt;
    }
    int n = nums.size();
    if (cnt >= n / 2)
        return major;
    return -1;
}
//简单的优化一下
int majorityElement2(vector<int>& nums) {

    if (nums.empty())
        return -1;
    int major = nums.front();
    int times = 1;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        if (nums[i] == major) {
            ++times;
        }
        else {
            --times;
            if (times == 0) {
                major = nums[i];
                times = 1;
            }
        }
    }
    times = 0;
    for (const int& num : nums) {
        if (num == major)
            ++times;
    }
    if (times > n / 2)
        return major;
    return -1;

   
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