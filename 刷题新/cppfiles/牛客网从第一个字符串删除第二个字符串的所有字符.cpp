#if 0
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//����They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.
void removeFromSecondString(string& first, string& second)
{
	unordered_set<char > hashset(second.begin(), second.end());
	string strtemp;
	for (auto iter : first) {
		if (hashset.count(iter) == 0)
			strtemp.push_back(iter);
	}
	first = strtemp;
}
int main(void)
{
	string first("They are students."), second("aeiou");
	removeFromSecondString(first, second);
	cout << first << endl;
	system("pause");
	return 0;
}
#endif