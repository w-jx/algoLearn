#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecode��Ŀ����:

����һ�������¶�ʮ����
*/
bool isUnit(char ch) {
    //bool is_unit = false;
    //if (ch == 'ʮ' || ch == '��' || ch == 'ǧ' || ch == '��' || ch == '��')
    //    is_unit = true;
    //return is_unit;
    return ch == 'ʮ' || ch == '��' || ch == 'ǧ' || ch == '��' || ch == '��';
}
int myatoi(string const & str, map<char, int> &charmap) {
    int n = str.size();
    int temp = 0;
    vector<int> retval;
    for (int i = 1; i < n; i+=2) {
        if (!isUnit(str[i])) {
            temp += charmap[str[i]];
            if (i == n - 1)
                retval.push_back(temp);
        }
        else {
            temp *= charmap[str[i]];
            if ((i < n - 1 && !isUnit(str[i + 1]) )|| i == n - 1) {
                retval.push_back(temp);
                temp = 0;
            }
        }
    }
    int res = 0;
    for (auto num : retval)
        res += num;

    return res;
}
void test01()
{
    map<char, int> charmap;
    charmap.insert({ '��',0 });
    charmap.insert({ 'һ', 1 });
    charmap.insert({ '��', 2 });
    charmap.insert({ '��', 2 });
    charmap.insert({ '��', 3 });
    charmap.insert({ '��', 4 });
    charmap.insert({ '��', 5 });
    charmap.insert({ '��', 6 });
    charmap.insert({ '��', 7 });
    charmap.insert({ '��', 8 });
    charmap.insert({ '��', 9 });
    charmap.insert({ 'ʮ', 10 });
    charmap.insert({ '��', 100 });
    charmap.insert({ 'ǧ', 1000 });
    charmap.insert({ '��', 10000 });
    charmap.insert({ '��', 100000000 });

    //cout << myatoi("����һǧ������ʮ��",charmap) << endl;
  
}
void test02() {
    map<char, int> charmap;
    charmap.insert({ '��',0 });
    charmap.insert({ 'һ', 1 });
    charmap.insert({ '��', 2 });
    charmap.insert({ '��', 2 });
    charmap.insert({ '��', 3 });
    charmap.insert({ '��', 4 });
    charmap.insert({ '��', 5 });
    charmap.insert({ '��', 6 });
    charmap.insert({ '��', 7 });
    charmap.insert({ '��', 8 });
    charmap.insert({ '��', 9 });
    charmap.insert({ 'ʮ', 10 });
    charmap.insert({ '��', 100 });
    charmap.insert({ 'ǧ', 1000 });
    charmap.insert({ '��', 10000 });
    charmap.insert({ '��', 100000000 });
    string str = "����һǧ������ʮ��";
    for (int i = 1; i < str.size(); i+=2) {
        cout << charmap[ str[i]] << endl;
    }
 
}
int main()
{
    test01();
    //test02();
	system("pause");
	return 0;
}
#endif