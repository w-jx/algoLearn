#if 0
#include "../headers/wjxHeaders.h"

//这个是我自己写的,通过了,但是空间复杂度o(n^2)
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
//答案题解的方法
string convert(string s, int numRows) {
	if (numRows == 1)
		return s;
	//s="abc",而numRows=5,最多只有三行
	vector<string> rows(min(numRows, int(s.size())));
	bool goingdown = false;
	int curRow = 0;//最开始从第0行开始
	//将每个字符添加到合适的行
	//只有向上移动到最上面的行,或者向下移动到最下面的行,方向改变
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