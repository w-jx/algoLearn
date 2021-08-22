#if 0
#include "../headers/wjxHeaders.h"
//#define VECTOR_TEST
//看下vector,unordered_map erase 的使用
void testvector()
{

    vector<int> v{ 1,2,3,4,5,6,7 };
    v.erase(v.begin());
    printVector(v);
    v.erase(v.begin() + 2);
    printVector(v);//vector 的erase 的使用就是erase 具体迭代器位置即可


    //unordered_map<int, int> hashtable;
    //for (int i = 0; i < 5; i++) {
    //    hashtable.emplace(make_pair(i, i*100));
    //}
    //printHashtable<int, int>(hashtable);
    //hashtable.erase(0);
    //printHashtable<int, int>(hashtable);
    


}

//这个程序有问题
/*
vector erase iterator outside range

*/
char firstUniqChar(string s) {
    int len = s.size();
    if (len == 0)
        return ' ';
    unordered_map<char, int> hashtable;
    list<char> vret;
    for (int i = 0; i < len; i++) {
        if (hashtable.count(s[i]) > 0) {
            vret.remove(s[i]);
            hashtable[s[i]]++;
        }
        else {
            hashtable.insert(make_pair(s[i], 0));
            vret.push_back(s[i]);
        }
    }
    if (hashtable.size() == 0)
        return ' ';

    return vret.front();
}

//357题我之前提交版本修改
int firstUniqChar2(const string s)
{
    if (s.size() == 0)
        return ' ';
    unordered_set<char> hashset;
    list<char> Mylist;
    int index = 0;
    while (index < s.size()) {

        if (hashset.count(s.at(index)) > 0) {

            Mylist.remove(s.at(index));
        }
        else {

            hashset.insert(s[index]);
            Mylist.push_back(s.at(index));
        }
        index++;
    }
    if (Mylist.size() == 0)
        return ' ';
    else
        return Mylist.front();
}
void test01()
{
    string s = "aadadaad";
    cout << firstUniqChar(s) << endl;

}
int main()
{
	//testvector();
    test01();
	system("pause");
	return 0;
}


#endif