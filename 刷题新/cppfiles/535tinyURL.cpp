#if 0
#include "../headers/wjxHeaders.h"
/*
这种方法中，我们将当前 URL 第几个出现作为关键字进行加密，将这个出现次序看做 62 进制，
并将每一位映射到一个长度为 62 位的表中对应的字母作为哈希值。
此方法中，我们使用一系列整数和字母表来加密，而不是仅仅使用数字进行加密。

*/
string charSet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
unordered_map<string, string> mp;
int cnt = 1;

string encode(string longUrl) {
    string short_s = "";
    int id = cnt;
    while (id > 0) {
        short_s += charSet[id % 62];
        id /= 62;
    }
    mp[short_s] = longUrl;
    cnt++;
    return short_s;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
   return mp[shortUrl];;
}
void test01()
{
    string longurl = "https://leetcode.com/problems/design-tinyurl";
    cout << encode(longurl) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif