#if 0
#include "../headers/wjxHeaders.h"
#include <string>
/*
leecode题目介绍:


*/

bool isnum(char ch)
{
	return ch >= '0' && ch <= '9';
}
bool isoperator(char ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
int getpriority(char ch) {
	if (ch == '*' || ch == '/')
		return 2;
	else if (ch == '+' || ch == '-')
		return 1;
	return 0;
}
bool isLeft(char ch)
{
	return ch == '(';
}
bool isright(char ch) {
	return ch == ')';
}
/// <summary>
/// 中缀 转 后缀
/// </summary>
/// <param name="s">中缀表达式</param>
/// <returns>后缀表达式,存储在数组里</returns>
vector<string> pre_to_post(string s)
{	//string str("1+(2+3)*4-5");
	stack<string> mystack;
	vector<string> ret;
	string str("");
	for (int i = 0; i < s.size();i++) {
		if (isnum(s[i]))//
			str += s[i] ;
		else {
			if (str != "") {
				ret.push_back(str);
				str = "";
			}
			string oper;
			oper.push_back(s[i]);//构造字符串
			//操作符
			if (isoperator(s[i])) {

				if (mystack.empty())
					mystack.push(oper);
				else {
					while (!mystack.empty()) {
						string ch = mystack.top();
						if (getpriority(ch[0]) < getpriority(s[i])) {
							mystack.push(oper);
							break;
						}
						else {
							ret.push_back(ch);
							mystack.pop();
							if (getpriority(ch[0]) == getpriority(s[i]) || mystack.empty()) {
								mystack.push(oper);
								break;
							}
			
						}
					}
				}
			}
			//左括号
			else if (isLeft(s[i])) {
				mystack.push(oper);
			}
			//右括号
			else if (isright(s[i])) {
				while (!mystack.empty()) {
					string temp = mystack.top();
					mystack.pop();
					if (isLeft(temp[0])) 
						break;	
					ret.push_back(temp);
				}
			}

		}
	}//for
	if (str != "")
		ret.push_back(str);
	while (!mystack.empty()) {
		ret.push_back(mystack.top());
		mystack.pop();
	}

	return ret;
}
int calculate(string s) {
	auto ret = pre_to_post(s);
	stack<int> mystack;
	for (auto iter : ret) {
		if (isnum(iter[0])) {
			mystack.push(stoi(iter));
		}
		else {
			auto right = mystack.top();
			mystack.pop();
			auto left = mystack.top();
			mystack.pop();
			if (iter[0] == '*') {
				mystack.push(left * right);
			}
			else if (iter[0] == '/')
				mystack.push(left / right);
			else if (iter[0] == '+')
				mystack.push(left + right);
			else if (iter[0] == '-')
				mystack.push(left - right);
		}
	}
	return mystack.top();
}
void test01()
{
	//string str("1+(2+3)*4-5");
	//auto ret = pre_to_post(str);
	//for (auto iter : ret)
	//	cout << iter << " ";
	//cout << endl;

	string str("3+2*2");
	cout << calculate(str) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif