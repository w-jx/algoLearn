#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

*/
string longestCommonPrefix(vector<string>& strs)
{
   
    if (strs.empty()) return {};
    string temp = strs.front();
    int index = 0;
    int len = temp.size();
    for (auto iter : strs) {//找到最小长度
        if (iter.size() < len)
            len = iter.size();

    }
    string str = "";
    str.resize(len);
    while (index<len) {

        for (auto iter : strs) {
            if (temp[index] != iter[index])
                return str;
            
        }
        str[index] = temp[index];
        index++;
    }

    return str;
}
void test01()
{
    vector<string> v = {
        "flower","flow","flight"
    };
    cout << longestCommonPrefix(v) << endl;

  /*  string str = "";
    str.resize(10);
    str[0] = 'a';
    str[1] = 'b';
    cout << str << endl;*/
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif