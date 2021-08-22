#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
bool rotateString(string str1, string str2) {
    int n1 = str1.size();
    int n2 = str2.size();
    if (n1 != n2) return false;
    int i = 0;
    while (str1[i] != str2[0]) {
        i++;
        if (i == n1) return false;
    }
    int k = 0;//给str2用
    for (int j = i; j < n1; j++, k++) {
        if (str1[j] != str2[k])
            return false;

    }
    for (int m = 0; m < i; m++, k++) {
        if (str1[m] != str2[k])
         return false;
    }
    return true;


}
bool rotateString2(string  & str1, string  &str2)
{   
    int n1 = str1.size();
    int n2 = str2.size();
    string str = str1 + str1;
    int i = 0;
    while (str1[i] != str2[0]) {
        i++;
        if (i == n1) return false;
    }
    for (int k = i; k < 2 * n1; k++) {
        if (str2 == str.substr(k, n2))
            return true;
    }
    return false;

}
void test01()
{
    //string str1 = "abcde";
    //string str2 = "cdeab";
    //cout << rotateString(str1, str2) << endl;

    string str3 = "bbbacddceeb";
    string str4 = "ceebbbbacdd";//ceeb bbbacdd 避免这种情况的产生
    cout << rotateString2(str3, str4) << endl;

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif