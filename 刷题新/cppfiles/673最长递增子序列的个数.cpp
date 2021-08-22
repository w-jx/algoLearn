#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	vector<int> dp(n, 1);//dp[i]������nums[i]��β��LIS����
	vector<int> count(n , 1);//count[i]��nums[i]��β��LIS�ĸ���

/*
��nums[i] > nums[j]ǰ���£������[0, i-1]�ķ�Χ�ڣ��ҵ���j��ʹ��dp[j] + 1 > dp[i]��
˵���ҵ���һ�������ĵ��������С�
��ô��jΪ��β���Ӵ�������������еĸ���,�������µ���iΪ��β���Ӵ�������������еĸ���
����count[i] = count[j]��


��nums[i] > nums[j]ǰ���£������[0, i-1]�ķ�Χ�ڣ��ҵ���j��ʹ��dp[j] + 1 == dp[i]
˵���ҵ���������ͬ���ȵĵ���������
��ô��iΪ��β���Ӵ�������������еĸ��� ��Ӧ�ü�����jΪ��β���Ӵ�������������еĸ�����
����count[i] += count[j];
*/

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] > nums[j]) {

				if (dp[j] + 1 > dp[i]) {//��һ���ҵ�
					dp[i] = dp[j] + 1;//����dp[i]
					count[i] = count[j];
				}
				else if (dp[j] + 1 == dp[i]) {
					count[i] += count[j];
				}
			}
		}
	}
	//���������еĳ���
	int maxlen = *std::max_element(dp.begin(), dp.end());
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (dp[i] == maxlen)
			res += count[i];
	}
	return res;
}
void test01()
{
	vector<int> nums{ 1,2,4,3,5,4,7,2 };
	//vector<int> nums{ 1,2,4,3};
	cout << findNumberOfLIS(nums) << endl;




	

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif