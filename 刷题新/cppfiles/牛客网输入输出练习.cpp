#if 0
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//给出形如aa,bb,cc,eee,ddd,wqwq这样的字符串，分割开
vector<string> getMerge(string s)
{
	stringstream ss(s);
	string temp;
	vector<string > vret;
	while (getline(ss, temp, ','))
		vret.push_back(temp);
	return vret;

}

void test01()
{
	string str = "aa,bb,cea,ewaew,ewew,rrr,qqq,wewe,re";
	auto vret = getMerge(str);
	for (auto iter : vret)
		cout << iter << " ";
	cout << endl;

}

int main(void)
{
#if 0
	string str;
	string strtemp;
	multiset<string> myset;
	stringstream sin(strtemp);
	while (getline(cin, str)) {//读取一行字符串 aa,bb,cc
		stringstream ss(str);
		while (getline(ss, strtemp, ',')) {//按照逗号分割
			myset.insert(strtemp);
		}
		auto it = myset.begin();
		for (; it != --myset.end(); it++) {
			cout << *it;
			cout << ",";
		}
		cout << *it;

		cout << endl;
		myset.clear();

	}
#endif
	test01();
	return 0;

}

#endif