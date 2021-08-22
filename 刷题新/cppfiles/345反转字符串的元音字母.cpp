#if 0
#include "../headers/wjxHeaders.h"


string reverseVowels(string s) {
    int len = s.size();
    if (len == 1)
        return s;
    auto isVovels = [=](const char& letter)->bool {
        return letter == 'a' || letter == 'o' || letter == 'u' || letter == 'e'||letter=='i';
    };
    int beg = 0, end = len - 1;
    while (beg < end) {
        if (isVovels(s[beg]) && isVovels(s[end])) {
            swap(s[beg], s[end]);
            beg++;
            end--;
            continue;
        }
        if (!isVovels(s[beg]))
            beg++;
        if (!isVovels(s[end]))
            end--;

    }

    return s;
}
void test01()
{
    string s = "hello";
    reverseVowels(s);
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif