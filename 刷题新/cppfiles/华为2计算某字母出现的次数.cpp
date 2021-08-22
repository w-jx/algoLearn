#if 0
#include "../headers/wjxHeaders.h"

int findlettertimes(const string& str, const char& ch)
{
    int len = str.size();
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) == tolower(ch))
            idx++;
    }
    return idx;

}
void test01()
{
    string str = "8 8 8  8A i i OOI              IIIaa";
    const char ch = 'A';

    cout << findlettertimes(str, ch) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif