#if 0
#include "../headers/wjxHeaders.h"

/*
1.���ֵ��ԭ������
2.���ֵ�ڻ���������
    A[0],A[N-1]һ���ᱻѡ��,ͬʱ˵����A[1],A[N-2]������϶��и���
    ���ֻҪ��A[1]��A[N-2]�ĸ�������С�������

    Ȼ��������ĺ�-������С�;͵õ��˻������������

����ٱȽϼ���

*/
int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int cur = nums[0], res = nums[0];

    int sum = nums[0];//����ĺ�
    for (int i = 1; i < n; ++i) {
        cur = std::max(cur + nums[i], nums[i]);
        res = std::max(res, cur);
        sum += nums[i];
    }//��������Ƿǻ������������

    //������nums[1]��nums[2]����С������
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