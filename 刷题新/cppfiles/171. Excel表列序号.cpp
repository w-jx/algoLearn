#if 0
#include "../headers/wjxHeaders.h"

/*
* �����ⶼ��
* A->1
* B->2
* ..
* AB->28
168��Ŀ�Ǹ�������,��������
�����Ǹ�������,��������


*/
//ͨ��,��Ϊ���˹�ϣ��,ʱ���ϱȽ�����
int titleToNumber(string columnTitle) {
	unordered_map<char, int> letter_dict;
	for (char ch = 'A'; ch <= 'Z'; ++ch)
		letter_dict[ch] = ch - 'A' + 1;
	int n = columnTitle.size();
	int base = pow(26, n - 1);
	long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += letter_dict[columnTitle[i]] * pow(26, n - i - 1);
	}
	return ret;
}
//�����Ż���ϣ��Ϊ�ַ������ϣ
int titleToNumber2(string columnTitle) {
	
	int letter_dict[128] = { 0 };
	for (char ch = 'A'; ch <= 'Z'; ++ch)
		letter_dict[ch] = ch - 'A' + 1;
	int n = columnTitle.size();
	int base = pow(26, n - 1);
	long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += letter_dict[columnTitle[i]] * pow(26, n - i - 1);
	}
	return ret;
}
//��һ���Ż�,������pow����
int titleToNumber3(string columnTitle) {

	int letter_dict[128] = { 0 };
	for (char ch = 'A'; ch <= 'Z'; ++ch)
		letter_dict[ch] = ch - 'A' + 1;
	int n = columnTitle.size();
	long base = 1;
	long ret = 0;
	for (int i = n-1; i >=0; --i) {
		ret += letter_dict[columnTitle[i]] *base;
		base *= 26;
	}
	return ret;
}

//��׼��
int titleToNumber4(string columnTitle) {

	int n = columnTitle.size();
	long base = 1;
	long ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		ret += (columnTitle[i]-'A'+1) * base;
		base *= 26;
	}
	return ret;
}
void test01()
{
	string columnTitle = "ZY";
	cout << titleToNumber(columnTitle) << endl;
}
int main()
{
	test01();
	return 0;
}


#endif