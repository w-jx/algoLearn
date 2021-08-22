#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

注意：没有要求顺序

*/
//代码1：leetcode 提交版
int longestPalindrome(string s) {
    if (s.size() <= 1)
        return s.size();
    unordered_set<char> hashset;
    int nums = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (hashset.count(s[i]) > 0) {
            nums += 2;
            hashset.erase(s[i]);
        }
        else
            hashset.insert(s[i]);
    }
    if (hashset.size() >= 1)
        nums += 1;
    return nums;

}
//刷题班教程 代码
int longestPalindrome2(string s) {
    int char_map[128] = { 0 };//字符哈希
    int max_length = 0;//回文串偶数部分的最大长度
    int flag = 0;//是否有中心点

    for (int i = 0; i < s.size(); i++) {
        char_map[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (char_map[i] % 2 == 0) {
            max_length += char_map[i];//对于字符数量是偶数个的，全部使用
        }
        else {//对于字符数量不是偶数的，那减去一个变成偶数
            max_length += char_map[i] - 1;
            flag = 1;
        }
    }
    return max_length + flag;

}
void test01()
{
    string str("abccccdd");
    cout << longestPalindrome2(str) << endl;

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif