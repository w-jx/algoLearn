#if 0
#include "../headers/wjxHeaders.h"
//"3[a]2[bc]"--->"aaabcbc"
string decodeString(string s) {
	int cnt = 0;
	vector<int> stknum;
	vector<string> stkword;
	string str;
	string ret;
	for (int i = 0; i < s.size();++i) {
		if (s[i] == ']') {
			stkword.push_back(str);
			str.clear();
			string newword;
			for (int i = 0; i < stknum.back(); ++i)
				newword += stkword.back();
			stkword.pop_back();
			stkword.push_back(newword);
			stknum.pop_back();
		}
		else if (s[i] == '[') {
			stknum.push_back(cnt);
			cnt = 0;
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			cnt = cnt*10 + s[i] - '0';
		}
		else {
			str += s[i];
		}

	}
	for (auto word : stkword) {
		cout << word << " ";
	}
	return ret;
}
bool isdigit(char const& ch)
{
	return ch >= '0' && ch <= '9';
}

string getnum(string s, size_t & idx)
{
	string ret;
	while (isdigit(s[idx])) {
		ret += s[idx++];
	}
	return ret;
}

string getstr(string s, size_t& idx) {
	string str;
	while (s[idx] != ']' && !isdigit(s[idx])) {
		str += s[idx++];
	}
	return str;
	
}
//答案题解,2021年6月19日
string decodeString2(string s) {
	int n = s.size();
	//利用vector来模拟 栈
	vector<string> stk;
	string num;//数字字符串
	for (size_t i = 0; i < n; ) {
		//获取一个数字并进栈.因为可能是连续的比如23
		//所以要一直解析,直到遇到非数字
		if (isdigit(s[i])) {
			num = getnum(s, i);
		//可以利用一个str 进行拼接,答案里是通过一个函数,一次性解析全部的数字
		//这样的好处我们可以方便地结束数字的解析
			stk.push_back(num);
		}
		//说明可以拼凑[]的字符了
		else if (s[i] == ']') {
			++i;
			vector<string> wordvec;
			while (stk.back() != "[") {
				wordvec.push_back(stk.back());
				stk.pop_back();
			}
			reverse(wordvec.begin(), wordvec.end());
			//里面还多个左括号
			stk.pop_back();
			//此时栈顶是次数
			int cnt = stoi(stk.back());
			stk.pop_back();//让数字出栈
			//构造单个字符串
			string word;
			for (const auto& ch : wordvec)
				word += ch;
			//构造多个字符串
			string wordin;
			for (int j = 0; j < cnt; ++j)
				wordin += word;
			//重新入栈
			stk.push_back(wordin);
		}
		//如果是字母或者[,直接入栈
		else if (isalpha(s[i]) ||s[i] == '[') {
			//string(size_t count,char ch),构造count个ch
			stk.push_back(string(1, s[i++]));
		}
		
	}
	string retword;
	for (auto& word : stk)
		retword += word;
	return retword;
}

void test01()
{
	string str = "3[a]2[bc]";
	string str1 = "3[a2[c]]";
	auto strret = decodeString2(str1);
	cout << strret << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif