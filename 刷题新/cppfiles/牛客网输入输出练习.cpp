#if 0
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//��������aa,bb,cc,eee,ddd,wqwq�������ַ������ָ
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
	while (getline(cin, str)) {//��ȡһ���ַ��� aa,bb,cc
		stringstream ss(str);
		while (getline(ss, strtemp, ',')) {//���ն��ŷָ�
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