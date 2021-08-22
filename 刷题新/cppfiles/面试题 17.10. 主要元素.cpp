#if 0
#include "../headers/wjxHeaders.h"

/*
169��һ����,����169��
��Ŀ��֤һ���г�������һ��������Ԫ��
�������������,�ͷ���-1,

ֱ�۵��뷨������νͶƱ��,��������,��һ��������¼���ִ���
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
//�򵥵��Ż�һ��
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