#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecode题目介绍:

二零一五年三月二十三日
*/
bool isUnit(char ch) {
    //bool is_unit = false;
    //if (ch == '十' || ch == '百' || ch == '千' || ch == '万' || ch == '亿')
    //    is_unit = true;
    //return is_unit;
    return ch == '十' || ch == '百' || ch == '千' || ch == '万' || ch == '亿';
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
    charmap.insert({ '零',0 });
    charmap.insert({ '一', 1 });
    charmap.insert({ '二', 2 });
    charmap.insert({ '两', 2 });
    charmap.insert({ '三', 3 });
    charmap.insert({ '四', 4 });
    charmap.insert({ '五', 5 });
    charmap.insert({ '六', 6 });
    charmap.insert({ '七', 7 });
    charmap.insert({ '八', 8 });
    charmap.insert({ '九', 9 });
    charmap.insert({ '十', 10 });
    charmap.insert({ '百', 100 });
    charmap.insert({ '千', 1000 });
    charmap.insert({ '万', 10000 });
    charmap.insert({ '亿', 100000000 });

    //cout << myatoi("二万一千二百三十八",charmap) << endl;
  
}
void test02() {
    map<char, int> charmap;
    charmap.insert({ '零',0 });
    charmap.insert({ '一', 1 });
    charmap.insert({ '二', 2 });
    charmap.insert({ '两', 2 });
    charmap.insert({ '三', 3 });
    charmap.insert({ '四', 4 });
    charmap.insert({ '五', 5 });
    charmap.insert({ '六', 6 });
    charmap.insert({ '七', 7 });
    charmap.insert({ '八', 8 });
    charmap.insert({ '九', 9 });
    charmap.insert({ '十', 10 });
    charmap.insert({ '百', 100 });
    charmap.insert({ '千', 1000 });
    charmap.insert({ '万', 10000 });
    charmap.insert({ '亿', 100000000 });
    string str = "二万一千二百三十八";
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