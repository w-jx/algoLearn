#if 0 
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
string addBinary(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    string str;
    int remain = 0;
    while (i >= 0 && j >= 0) {
        int n1 = a[i] - '0';
        int n2 = b[j] - '0';
        int cur = (n1 + n2 + remain) % 2;
        remain = (n1 + n2 + remain) / 2;

        str += cur + '0';
        --i;
        --j;
    }
    while (i >= 0) {
        int n1 = a[i] - '0';
        int cur = (n1 + remain) % 2;
        remain = (n1 + remain) / 2;
        str += cur + '0';
        --i;
    }
    while (j >= 0) {
        int n2 = b[j] - '0';
        int cur = (n2 + remain) % 2;
        remain = (n2 + remain) / 2;
        str += cur + '0';
        --j;
    }
    while (remain != 0) {
        str += remain % 2 + '0';
        remain /= 2;
    }
    reverse(str.begin(), str.end());
    return str;
}
void test01()
{
    string a = "100", b = "110010";
    cout << addBinary(a, b) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif