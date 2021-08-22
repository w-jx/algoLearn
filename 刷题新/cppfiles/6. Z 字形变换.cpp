#if 0
#include "../headers/wjxHeaders.h"

//��������Լ�д��,ͨ����,���ǿռ临�Ӷ�o(n^2)
string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
	int n = s.size();
	int less = numRows-2;
	vector<vector<char> > used(numRows, vector<char>(n / 2+1,' '));
	bool flag = true;
	int idx = 0;
	int i = 0, j = 0;
	while (idx < n) {
		if (flag) {
			int cnt = 0;
			while (cnt < numRows && idx<n) {
				used[i++][j] = s[idx++];
				++cnt;
			}
			flag = !flag;
			++j;
			--i;
			--i;
		}
		else {
			int cnt = 0;
			while (cnt < less && idx<n) {
				used[i--][j++] = s[idx++];
				++cnt;
			}
			flag = !flag;
		}
	}
	string ret;
	for (auto outer : used) {
		for (auto inner : outer) {
			if (inner != ' ')
				ret += inner;
		}
	}
	return ret;
}
//�����ķ���
string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
	//s="abc",��numRows=5,���ֻ������
	vector<string> rows(min(numRows, int(s.size())));
	bool goingdown = false;
	int curRow = 0;//�ʼ�ӵ�0�п�ʼ
	//��ÿ���ַ���ӵ����ʵ���
	//ֻ�������ƶ������������,���������ƶ������������,����ı�
	for (char ch : s) {
		rows[curRow] += ch;
		if (curRow == 0 || curRow == numRows - 1)
			goingdown = !goingdown;
		curRow += goingdown ? 1 : -1;
	}
	string ret;
	for (const string& row : rows)
		ret += row;
	return ret;

}
void test01()
{
	string str = "PAYPALISHIRING";
	cout << convert(str, 4) << endl;
}
int main()
{
	test01();
}
#endif