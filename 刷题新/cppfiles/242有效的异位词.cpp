#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
方法1：将string 排序，然后将其作为一个key
方法2：统计每个元素中26个字母各出现几次，存储在数组中
要是字母异位词，那么这个出现的字母次数是一样的，以这个为key

*/

//统计每个单词 26个字母各出现几次
void change_to_vector(string& str, vector<int>& vec)
{
    vec.resize(26, 0);
    for (int i = 0; i < str.size(); i++)
        vec[str[i] - 'a']++;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > vret;
    //unordered_map<vector<int>, vector<string>> hashtable;
    map<vector<int>, vector<string>> hashtable;//注意不能用unordered_map,提示没有构造函数
    for (auto iter : strs) {
        vector<int> vec;
        change_to_vector(iter, vec);
        hashtable[vec].push_back(iter);
    }
    for (auto iter : hashtable)
        vret.push_back(iter.second);
    return vret;
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif