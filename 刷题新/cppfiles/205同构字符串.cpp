#if 0
#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> hashtable;//s-t
    unordered_map<char, char> hashtable2;//t-s
    int size = 0;
    while (size < s.size()) {
        if (hashtable.count(s[size]) > 0) {
            if (t[size] != hashtable[s[size]])
                return false;
            size++;
            continue;
        }
        else {
            if (hashtable2.count(t[size]) > 0) {
                if (s[size] != hashtable2[t[size]])
                    return false;
            }
        }
        hashtable.insert(make_pair(s[size], t[size]));
        hashtable2.insert(make_pair(t[size], s[size]));
        size++;
    }
    return true;
}
void test01()
{
	auto str1 = "paper";
	auto str2 = "title";
	cout<<isIsomorphic(str1, str2) << endl;;

}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif