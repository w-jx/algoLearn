#if 0
#include "../headers/wjxHeaders.h"

/*
* 两道题都是
* A->1
* B->2
* ..
* AB->28
168题目是给你数字,返回名称
本体是给你名称,返回数字


*/
//通过,因为用了哈希表,时间上比较拉跨
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
//尝试优化哈希表为字符数组哈希
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
//进一步优化,不适用pow函数
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

//标准答案
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