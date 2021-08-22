#if 0
#include "../headers/wjxHeaders.h"
/*



*/
//�ҵĴ���Ľⷨ,[3,6,5,1,8]���15,Ӧ����18
int maxSumDivThree(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n);//dp[i]����Ԫ��i,�ܱ�3������Ԫ������
    vector<int> visit(n);
    if (nums[0] % 3 == 0) {
        dp[0] = nums[0];
        visit[0] = 1;
    }
    bool find = false;
    for (int i = 1; i < n; ++i) {
        if ((dp[i - 1] + nums[i]) % 3 == 0) {
            dp[i] = dp[i - 1] + nums[i];
            visit[i] = 1;
            find = true;
        }
        else {
            for (int j = 0; j < i; ++j) {
                if (visit[j] == 0 && (dp[i - 1] + nums[i] + nums[j]) % 3 == 0) {
                    dp[i] = dp[i - 1] + nums[i]+nums[j];
                    visit[j] = 1;
                    visit[i] = 1;
                    find = true;
                }
            }
        }//else
        if (!find) {
            dp[i] = dp[i - 1];
        }
        find = false;
       
    }
    return dp[n - 1];


}
//leetcode �����������
int maxSumDivThree2(vector<int>& nums) {

    /*
��ĿҪ����ѡ����������(��Ҫ������)�ĺ��ܹ����������������
���ǿ�����̰�ĵ��ۼ��������ֵĺͣ�Ȼ������޳�һЩ����ʹ�����ܹ�����������
������˵�������������ĺ�ǡ���ܹ����������������ǲ���Ҫ���κβ�����ֱ�ӷ��ء�
��������ۼӺ�sumsum modmod 3 == 1, �����ǿ�����2�ַ�ʽ�����ܹ���3����:
    1.�޳�һ������������mod3==1���ҽ�����С����
    2.�޳���������������mod3==2���ҽ�����С����
��������ۼӺ�sumsum modmod 3 == 2, �����ǿ�����2�ַ�ʽ�����ܹ���3����:
    1.�޳�һ������������mod3==2���ҽ�����С����
    2.�޳���������������mod3==1���ҽ�����С����
���ȡ���淽�������ֵ
    */
    int n = nums.size();
    int sum = 0;
    vector<int> one, two;
    for (int num : nums) {
        if (num % 3 == 1)
            one.push_back(num);
        if (num % 3 == 2)
            two.push_back(num);
        sum += num;
    }
    int res = sum % 3;
    if (res == 0)
        return sum;
    int ans = 0;
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    if (res % 3 == 1) {
        if (one.size() > 0)
            ans = std::max(ans, sum - one[0]);
        if (two.size() > 1)
            ans = std::max(ans, sum - two[0] - two[1]);
    }
    else if (res % 3 == 2) {
        if (two.size() > 0)
            ans = std::max(ans, sum - two[0]);
        if (one.size() > 1)
            ans = std::max(ans, sum - one[0] - one[1]);
    }
    return ans;


}
void test01()
{
    vector<int> nums{ 3,6,5,1,8 };
    cout << maxSumDivThree2(nums) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif