#if 0
#include "../headers/wjxHeaders.h"
/*
���ַ����У����ǽ���ǰ URL �ڼ���������Ϊ�ؼ��ֽ��м��ܣ���������ִ����� 62 ���ƣ�
����ÿһλӳ�䵽һ������Ϊ 62 λ�ı��ж�Ӧ����ĸ��Ϊ��ϣֵ��
�˷����У�����ʹ��һϵ����������ĸ�������ܣ������ǽ���ʹ�����ֽ��м��ܡ�

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