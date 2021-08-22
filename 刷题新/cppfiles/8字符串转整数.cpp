#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÃ‚ƒøΩÈ…‹:


*/
//2021.4.7 ∏¥œ∞
int myAtoi(string s) {

    long long N = 0;
    bool isNegative = false;
    int i = 0, n = s.size();

    while (i < n && s[i]==' ') ++i;
    if (i == n)
        return 0;
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-')
            isNegative = true;
        ++i;
    }
    while (i < n) {
        if (s[i] > '9' || s[i] < '0')
            break;
        N = N * 10 + s[i] - '0';
        if (N > INT_MAX) {
            if (!isNegative)
                return INT_MAX;
            else if (N - 1 > INT_MAX)
                return INT_MIN;
        }
        ++i;
    }
    if (isNegative)
        N *= (-1);
    return static_cast<int>(N);
}
void test01()
{
    string s= "   -42";
    cout << myAtoi(s) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif