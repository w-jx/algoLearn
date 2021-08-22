#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecode题目介绍:


*/
//我的解法通过了一些测试用例,但是还是有边界情况没有考虑到
/*
".1"  true

*/
bool isNumber(string str) {

	int n = str.size(), i = 0;
	for (; i < n; ++i) {
		if (str[i] != ' ')
			break;
	}
	if (i == n)
		return false;
	if (str[i] == '+' || str[i] == '-')
		++i;
	bool hasdot = false;//是否已经出现小数
	bool hasnum = false;
	bool hase = false;
	bool hasoperator = false;
	for (; i < n; ++i) {
		if (str[i] >= '0' && str[i] <= '9')
			hasnum = true;
		else if (str[i] == '.') {
			if (hasdot || hase || !hasnum)//已经遇到小数点,又遇到小数点的情况
				return false;//前面有e的情况,不能有小数点
			hasdot = true;
			hasnum = false;

		}
		else if (str[i] == 'e' || str[i] == 'E') {
			if (!hasnum || hase)//e前面要有数字,有了e不能再遇到e
				return false;
			hase = true;
		}
		else if (str[i] == '+') {
			if (!hase || hasoperator)
				return false;
			hasoperator = true;
		}
		else if (str[i] == '-' || str[i] == '.') {
			if (!hase || hasoperator || hasdot)
				return false;
			hasoperator = true;
		}

	}
	return hasnum;
}
/*
首先定义了四个flag，对应四种字符
是否有数字：hasNum
是否有e：hasE
是否有正负符号：hasSign
是否有点：hasDot
其余还定义了字符串长度n以及字符串索引index
先处理一下开头的空格，index相应的后移
然后进入循环，遍历字符串
如果当前字符c是数字：将hasNum置为true，index往后移动一直到非数字或遍历到末尾位置；如果已遍历到末尾(index == n)，结束循环

如果当前字符c是'e'或'E'：如果e已经出现或者当前e之前没有出现过数字，返回fasle；
否则令hasE = true，并且将其他3个flag全部置为false，因为要开始遍历e后面的新数字了

如果当前字符c是+或-：如果已经出现过+或-或者已经出现过数字或者已经出现过'.'，返回flase；否则令hasSign = true

如果当前字符c是'.'：如果已经出现过'.'或者已经出现过'e'或'E'，返回false；否则令hasDot = true

如果当前字符c是' '：结束循环，因为可能是末尾的空格了，但也有可能是字符串中间的空格，在循环外继续处理

如果当前字符c是除了上面5种情况以外的其他字符，直接返回false

处理空格，index相应的后移

如果当前索引index与字符串长度相等，说明遍历到了末尾，但是还要满足hasNum为true才可以最终返回true，
因为如果字符串里全是符号没有数字的话是不行的，而且e后面没有数字也是不行的，但是没有符号是可以的，
所以4个flag里只要判断一下hasNum就行；所以最后返回的是hasNum && index == n

如果字符串中间有空格，按以上思路是无法遍历到末尾的，index不会与n相等，返回的就是false

*/
bool isNumber2(string str) {
	int idx = 0;
	int n = str.size();
	while (str[idx] == ' ')++idx;
	if (idx == n)
		return false;
	bool hasNum = false;
	bool hasE = false;
	bool hasOperator = false;
	bool hasDot = false;

	while (idx < n) {
		while (idx < n && isdigit(str[idx]) != 0) {
			hasNum = true;
			++idx;
		}
		if (idx == n)
			break;
		if (str[idx] == 'e' || str[idx] == 'E') {
			if (hasE || !hasNum)//已经有e,或者前面没有数字
				return false;
			hasE = true;
			hasNum = false;//因为要开始遍历e后面的新数字了
			hasOperator = false;
			hasDot = false;
		}
		else if (str[idx] == '.') {
			//已经出现e,已经出现小数点
			if (hasE || hasDot)
				return false;
			hasDot = true;
		}
		else if (str[idx] == '+' || str[idx] == '-') {
			//已经出现数字,已经出现小数点,已经出现运算符
			if (hasDot || hasOperator||hasNum)
				return false;
			hasOperator = true;
		}
		else if (str[idx] == ' ') {
			break;//可能是末尾空格,也可能是中间空格,在循环外面处理
		}
		else//其他符号,直接返回false
			return false;
		++idx;
	}
	while (idx < n && str[idx] == ' ')
		++idx;
	return idx == n && hasNum;
}
void test01()
{
	//cout << isNumber(".1") << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif