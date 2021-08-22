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
//�����,2021��6��19��
string decodeString2(string s) {
	int n = s.size();
	//����vector��ģ�� ջ
	vector<string> stk;
	string num;//�����ַ���
	for (size_t i = 0; i < n; ) {
		//��ȡһ�����ֲ���ջ.��Ϊ�����������ı���23
		//����Ҫһֱ����,ֱ������������
		if (isdigit(s[i])) {
			num = getnum(s, i);
		//��������һ��str ����ƴ��,������ͨ��һ������,һ���Խ���ȫ��������
		//�����ĺô����ǿ��Է���ؽ������ֵĽ���
			stk.push_back(num);
		}
		//˵������ƴ��[]���ַ���
		else if (s[i] == ']') {
			++i;
			vector<string> wordvec;
			while (stk.back() != "[") {
				wordvec.push_back(stk.back());
				stk.pop_back();
			}
			reverse(wordvec.begin(), wordvec.end());
			//���滹���������
			stk.pop_back();
			//��ʱջ���Ǵ���
			int cnt = stoi(stk.back());
			stk.pop_back();//�����ֳ�ջ
			//���쵥���ַ���
			string word;
			for (const auto& ch : wordvec)
				word += ch;
			//�������ַ���
			string wordin;
			for (int j = 0; j < cnt; ++j)
				wordin += word;
			//������ջ
			stk.push_back(wordin);
		}
		//�������ĸ����[,ֱ����ջ
		else if (isalpha(s[i]) ||s[i] == '[') {
			//string(size_t count,char ch),����count��ch
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