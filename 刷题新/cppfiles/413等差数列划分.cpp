#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    //dp[i]������nums[i]��β�ĵȲ����еĸ���
    //dp[0]=dp[1]=0,��Ϊ��������
    vector<int> dp(n);
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        //˵���ܹ���ɵȲ�����
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            dp[i] = dp[i - 1] + 1;
            cnt += dp[i];
        }
    }
    return cnt;
}
//�Ż��ռ�Ķ�̬�滮
int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    int last = 0;//ǰһ����������ɵȲ����еĸ���
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
        //˵���ܹ���ɵȲ�����
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            cnt += last + 1;
            last += 1;
        }
        else
            last = 0;
    }
    return cnt;
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