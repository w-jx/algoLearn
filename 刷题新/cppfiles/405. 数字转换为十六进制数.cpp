#if 0
#include "../headers/wjxHeaders.h"
/*
正数的补码是本身
负数的补码:原码的基础上,符号位不变,其余各位取反,最后+1
*/

vector<int> get(int num)
{
	int i = 31;
	vector<int> ret(32);

	while (i >= 0) {
		ret[i] = num & 1;
		--i;
		num >>= 1;
	}
	return ret;
}

string str;
unordered_map<int, char> num_char;
//通过,但是有很多可以优化的地方
string toHex(int num) {
	if (num == 0)
		return "0";
	for (int i = 0; i < 10; ++i)
		num_char[i] = i + '0';
	for (int i = 10; i < 16; ++i)
		num_char[i] = 'a' + i - 10;


	int i = 1;
	int base = 1;
	int j = 0;
	int val = 0;
	string retstr;
	while (i <33) {
		int curbit = num & 1;
		val += curbit * base;
		base *= 2;
		if (i % 4 == 0) {
			retstr += num_char[val];
			val = 0;
			base = 1;
		}
		num >>= 1;
		++i;
	}
	while (!retstr.empty() && retstr.back() == '0')
		retstr.pop_back();
	reverse(retstr.begin(), retstr.end());
	return retstr;

}
//"3b9aca00" 这个测试用例,就是有连续的0
string toHex2(int num) {
	if (num == 0)
		return "0";
	char numHash[16];//优化1,用字符数组代替unordered_map
	for (int i = 0; i < 10; ++i)
		numHash[i] = i + '0';
	for (int i = 10; i < 16; ++i)
		numHash[i] = 'a' + i - 10;


	int i = 1;
	int base = 1;
	int j = 0;
	int val = 0;
	string retstr;
	
	while (i < 33) {
		int curbit = num & 1;
		val += curbit * base;
		base *= 2;
		if (i % 4 == 0) {
			retstr += numHash[val];
			val = 0;
			base = 1;
		}
		num >>= 1;
		++i;
	}
	while (!retstr.empty() && retstr.back() == '0')
		retstr.pop_back();
	reverse(retstr.begin(), retstr.end());
	return retstr;

}
//进一步优化
string toHex3(int num) {
	if (num == 0)
		return "0";
	string numHash = "0123456789abcdef";

	int i = 1;
	int base = 1;
	int j = 0;
	int val = 0;
	string retstr(8,' ');//肯定是8位
	int idx = 7;

	while (i < 33) {
		int curbit = num & 1;
		val += curbit * base;
		base *= 2;
		if (i % 4 == 0) {
			retstr[idx--]= numHash[val];
			val = 0;
			base = 1;
		}
		num >>= 1;
		++i;
	}
	while (++idx < 8) {
		if (retstr[idx] != '0')
			break;
	}
	return retstr.substr(idx);
}
//进进一步优化
string toHex4(int num) {
	if (num == 0)
		return "0";
	string numHash = "0123456789abcdef";
	numHash.resize(23);
	int i = 1;
	int base = 1;
	int j = 0;
	int val = 0;
	
	int idx = 22;

	while (i < 33) {
		int curbit = num & 1;
		val += curbit * base;
		base *= 2;
		if (i % 4 == 0) {
			numHash[idx--] = numHash[val];
			val = 0;
			base = 1;
		}
		num >>= 1;
		++i;
	}
	while (++idx < 23) {
		if (numHash[idx] != '0')
			break;
	}
	return numHash.substr(idx);
}
void test01() 
{
	cout << toHex3(1000000000) << endl;
}
int main()
{
	test01();
}
#endif