#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

string reverseWords(string s) {
	if (s.empty()) return "";
	vector<string> v;

	int len = s.size();
	string temp = "";
	int begin = 0;
	int minNum = 1;
	bool startFlag = false;
	for (size_t i = 0; i < len; i++) {
		if (s[i] == ' ') {
			if (temp.size() > 0) {
				v.push_back(temp);
				temp.clear();
				minNum = 1;
				begin = 0;
			}
			continue;
		}
		else if (s[i] != ' ') {
			startFlag = true;
		}
		if (startFlag==true) {
			temp.resize(minNum++);
			temp[begin++] = s[i];
		}

	}
	if (temp != "")
		v.push_back(temp);
	string str = "";

	cout << v.size() << endl;
	for (int j = v.size() - 1; j >= 0; j--) {
		str.append(v[j]);
		if(j>0)
			str.append(" ");
	}
	
	return str;
	
}
//2021年5月14日复习
string reverseWords2(string s) {
	vector<string> word_vec;
	bool start = false;
	string word;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ' ') {
			if (start) {
				word_vec.push_back(word);
				word.clear();
				start = false;
			}
		}
		else {
			word.push_back(s[i]);
			start = true;
		}
	}
	if (!word.empty())
		word_vec.push_back(word);
	word.clear();
	for (auto iter = word_vec.rbegin(); iter != word_vec.rend(); ++iter) {
		word += *iter;
		word += ' ';
	}
	word.pop_back();
	return word;
}
//利用streamstream 方法
string reverseWords3(string s) {
	stringstream ss(s);
	
	string temp;
	vector<string> word_vec;
	while (getline(ss, temp, ' ')) {
		if (temp != " "&&!temp.empty())
			word_vec.push_back(temp);
	}
	for (auto iter : word_vec) {
		cout << iter << " ";
	}
	cout << endl;
	string word;
	for (auto iter = word_vec.rbegin(); iter != word_vec.rend(); iter++) {
		word += *iter;
		word += ' ';
	}
	word.pop_back();
	return word;
}
//原地解法
string reverseWords4(string s) {
	reverse(s.begin(), s.end());
	int idx = 0, start = 0;
	int  n = s.size();
	while (start < n) {
		if (s[start] != ' ') {
			if (idx != 0)
				s[idx++] = ' ';
			int end = start;
			while (end < n && s[end] != ' ')
				s[idx++] = s[end++];
			reverse(s.begin() + idx - (end - start), s.begin() + idx);
			start = end;
		}
		++start;
	}
	return s.substr(0, idx);
}
void test01()
{
	//string s = "      i am your          father";
	//cout << reverseWords(s) << endl;

	string s =
		"a good   example";
	string s1 = "  hello world  ";
	cout << reverseWords4(s1) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif


#if 0
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string reverseWords(string s)
{
	reverse(s.begin(), s.end());
	string ret;
	string word;
	int idx = 0, n = s.size();
	while (idx < n)
	{
		if (s[idx] != ' ')
		{
			word += s[idx++];
		}
		else
		{
			reverse(word.begin(), word.end());
			ret += word;
			ret += ' ';
			while (idx < n && s[idx] == ' ')
			{
				++idx;
			}
			word.clear();
		}
	}
	ret.pop_back();
	return ret;
}
int main()
{
	std::string input = "the sky is blue";
	auto ret = reverseWords(input);
	cout << ret << endl;
}
#endif 