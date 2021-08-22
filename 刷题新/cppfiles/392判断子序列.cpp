#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
//暴力法可以通过，但是如果数据很大，
要用动态规划的方法优化

*/
int isSubsequence(string t, int right, char ch) {
    for (int i = right; i >= 0; --i) {
        if (t[i] == ch)
            return i;
    }
    return -1;
}
bool isSubsequence(string s, string t) {
    int n = s.size(), idx = t.size();
    for (int i = n - 1; i >= 0; --i) {
        idx = isSubsequence(t, idx - 1, s[i]);
        if (idx == -1)
            return false;
    }
    return true;
}
void test01()
{
    string s{ "abc" }, t{ "ahbgdc" };
    cout << isSubsequence(s, t) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif