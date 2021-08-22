#if 0
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
/*
leecode题目介绍:

根据 逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
*/

bool isNumber(string& s) {

	stringstream sin(s);
	double d;
	char c;
	if (!(sin >> d))//转换不成功肯定是false
	{
		/*
		sin>>t表示把sin转换成double的变量（其实对于int和float型的都会接收），
		如果转换成功，则值为非0，如果转换不成功就返回为0 
		
		*/
		return false;
	}
	if (sin >> c)
	{
		/*解释：此部分用于检测错误输入中，数字加字符串的输入形式（例如：34.f），
		在上面的的部分（sin>>t）已经接收并转换了输入的数字部分，
		在stringstream中相应也会把那一部分给清除，如果此时传入字符串是
		数字加字符串的输入形式，则此部分可以识别并接收字符部分，例如
		上面所说的，接收的是.f这部分，所以条件成立，返回false;如果剩下
		的部分不是字符，那么则sin>>p就为0,则进行到下一步else里面
	  */
		return false;
	}
	return true;
}


int calculate(int left, int right, string& s) {

	switch (s[0])
	{
	case '+':
		return left + right;
		break;
	case '-':
		return left - right;
		break;
	case '*':
		return left * right;
		break;
	case '/':
		return left / right;
		break;
	default:
		break;
	}

}
int evalRPN(vector<string>& tokens) {

	stack<int> s;
	for (auto iter : tokens) {

		if (isNumber(iter)) {
			s.push(stoi(iter));//stoi string转int,  to_string(int val) int 转string
		}
		else {

			int rightNum = s.top();
			s.pop();
			int leftNum = s.top();
			s.pop();

			s.push(calculate(leftNum, rightNum, iter));
		}
	}
	int ret = 0;
	if (s.size() == 1) {
		ret = s.top();
		s.pop();
		return ret;
	}
	return ret;
}
void test01()
{
	//string s = "+";
	//cout << s[0] << endl;
	//cout << typeid(s[0]).name() << endl;

	//vector<string> v;
	//v.push_back("2");
	//v.push_back("1");
	//v.push_back("+");
	//v.push_back("3");
	//v.push_back("*");
	//
	//cout << evalRPN(v) << endl;


	//vector<string> v2;
	//v2.push_back("4");
	//v2.push_back("13");
	//v2.push_back("5");
	//v2.push_back("/");
	//v2.push_back("+");

	//cout << evalRPN(v2) << endl;


	vector<string> v3;
	v3.push_back("10");
	v3.push_back("6");
	v3.push_back("9");
	v3.push_back("3");
	v3.push_back("+");
	v3.push_back("-11");
	v3.push_back("*");
	v3.push_back("/");
	v3.push_back("*");
	v3.push_back("17");
	v3.push_back("+");
	v3.push_back("5");
	v3.push_back("+");
	cout << evalRPN(v3) << endl;
	
}

void test02()
{

	vector<string> v3;
	v3.push_back("10");
	v3.push_back("6");
	v3.push_back("9");
	v3.push_back("3");
	v3.push_back("-11");
	v3.push_back("17");
	v3.push_back("+");


	for (int i = 0; i < v3.size(); i++) {
		cout << isNumber(v3[i]) << " ";
	}
	cout << endl;

}
int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}
#endif