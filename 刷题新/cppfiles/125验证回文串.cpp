#if 0
#include "../headers/wjxHeaders.h"

bool isLetter(const char& s)
{
    return (s>=65 &&s<=90 || s>=97&&s<=122);
}
bool isNumber(const char& s)
{
    return s >= 48 && s <= 57;
}
bool isOther(const char& s)
{
    return (!isLetter(s)) && (!isNumber(s));
}
bool isPalindrome(string s) {
    int len = s.size();
    if (len <= 1)
        return true;
    int pstart = 0;
    int pend = len - 1;
    while (pstart < pend) {
        auto start = s[pstart];
        auto end = s[pend];

        if (isNumber(start) && isLetter(end))
            return false;
        if (isNumber(end) && isLetter(start))
            return false;
        if (isLetter(start) && isLetter(end)) {
            if (start == end || abs(start-end)==32) {
                pstart++;
                pend--;
                continue;
            }
            return false;
        }
        if (isNumber(start) && isNumber(end)) {
            if (start == end ) {
                pstart++;
                pend--;
                continue;
            }
            return false;
        }
        if (isOther(start)) {
            pstart++;
        }
        if (isOther(end))
            pend--;
    }
    return true;
      

}
bool isPalindrome2(string s) {
    int len = s.size();
    if (len <= 1)
        return true;
    int i = 0, j = len - 1;
    while (i < j) {
        if (!isalnum(s[i])) {
            i++;
            continue;
        }
        if (!isalnum(s[j])) {
            j--;
            continue;
        }
        if (toupper(s[i]) == toupper(s[j])) {
            ++i;
            --j;
            continue;
        }
        return false;
    }
    return true;

}
void test01()
{
    //string s{ "A man, a plan, a canal: Panama" };
    //cout << isPalindrome(s) << endl;
    //string s1{ "ab_a" };
    //cout << isPalindrome(s1) << endl;

    //cout << isNumber('0') << endl;
    //cout << isNumber('1') << endl;
    //cout << isNumber('2') << endl;
    //cout << isNumber('3') << endl;
    //cout << isNumber('4') << endl;
    //cout << isNumber('5') << endl;
    //cout << isNumber('6') << endl;
    //cout << isNumber('7') << endl;
    //cout << isNumber('8') << endl;
    //cout << isNumber('9') << endl;
    //cout << isNumber('a') << endl;


    string s2{ "A man, a plan, a canal: Panama" };
    cout << isPalindrome2(s2) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif