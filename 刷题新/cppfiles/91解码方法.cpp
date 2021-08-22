#if 0
#include "../headers/wjxHeaders.h"


int numDecodings(string s) {
	int n = s.size();
	if (s[0] == '0')
		return 0;
	vector<int> dp(n, 0);
	dp[0] = 1;
	//"06","0","306"
	for (int i = 1; i < n; ++i) {
		if ((s[i - 1] == '1' && s[i] >= '1' && s[i] <= '9') || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
			if (i > 2)
				dp[i] = dp[i - 1] + dp[i - 2];
			else
				dp[i] = dp[i - 1] + 1;
		}
		//10011
		else if (s[i] == '0') {
			if (s[i - 1] >= '3' || s[i - 1] <= '0')
				return 0;
			if (i > 2)
				dp[i] = dp[i - 2];
			else
				dp[i] = 1;
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	return dp[n - 1];
}
//2021��6��6�ո�ϰ
int numDecodings2(string s) {
	int n = s.size();
	//dp[i]����s[i]�ж�����ӳ�䷽��
	vector<int> dp(n);

	if (s[0] == '0')
		return 0;
	dp[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] == 0 && (s[i - 1] < '1' || s[i - 1]>'2'))
			return 0;
		if (s[i] == 0)
			dp[i] = 1;
		else {
			if ((s[i - 1] == '1' && s[i] > '0' && s[i] <= '9') || (s[i - 1] == '2' && s[i] > '0' && s[i] <= '6'))
				dp[i] = dp[i - 1] + 1;
		}
	}
	return dp[n - 1];
}
//���
int numDecodings3(string s) {
	int n = s.size();
	//֮����Ҫn+1,��Ϊdp(i)���ܺ�dp(i-2)�й�
	//���Լ򻯱߽�
	vector<int> dp(n + 1);
	//dp[0]=1,���ַ���Ҳ��1�ֽ��뷽��,���ַ���
	//�����ķ���=ֻ�õ�ǰ�ַ�����+�õ�ǰ�ַ���ǰһ���ַ�����
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		//ֻҪ��ǰ�ַ���Ϊ'0',��ô����ǰһ���ַ��Ľ�����
		if (s[i - 1] != '0')
			dp[i] += dp[i - 1];
		//�������ַ�,���ܴ���26
		//����2���ַ�,i����Ҫ����1����

		//iΪ1->�ַ����±�0,iΪ2->�ַ����±�1(��ʱ��0,1�����ַ�)
		if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) {
			dp[i] += dp[i - 2];//ǰi-2���ַ����dp[i-2]����
		}
	}
	return dp[n];
}
//���Ļ�����״̬ѹ��
int numDecodings4(string s) {
	int n = s.size();
	int first = 1, second = 1, cur = 0;
	for (int i = 1; i <= n; ++i) {
		//ֻҪ��ǰ�ַ���Ϊ'0',��ô����ǰһ���ַ��Ľ�����
		if (s[i - 1] != '0')
			cur += second;
		//�������ַ�,���ܴ���26
		//����2���ַ�,i����Ҫ����1����

		//iΪ1->�ַ����±�0,iΪ2->�ַ����±�1(��ʱ��0,1�����ַ�)
		if (i > 1 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) {
			cur += first;//ǰi-2���ַ����dp[i-2]����
		}
		first = second;
		second = cur;
		cur = 0;
	}
	return second;
}
void test01()
{
	cout << numDecodings2("10") << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif