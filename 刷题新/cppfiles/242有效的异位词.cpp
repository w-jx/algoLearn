#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����1����string ����Ȼ������Ϊһ��key
����2��ͳ��ÿ��Ԫ����26����ĸ�����ּ��Σ��洢��������
Ҫ����ĸ��λ�ʣ���ô������ֵ���ĸ������һ���ģ������Ϊkey

*/

//ͳ��ÿ������ 26����ĸ�����ּ���
void change_to_vector(string& str, vector<int>& vec)
{
    vec.resize(26, 0);
    for (int i = 0; i < str.size(); i++)
        vec[str[i] - 'a']++;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > vret;
    //unordered_map<vector<int>, vector<string>> hashtable;
    map<vector<int>, vector<string>> hashtable;//ע�ⲻ����unordered_map,��ʾû�й��캯��
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