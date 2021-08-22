#if 0
#include "../headers/wjxHeaders.h"


//遇到的问题：hashtable 哈希映射插入的顺序会变化？因为本身就是无序的


template<class T1,class T2>
void printHash(unordered_map<T1, T2>& hashtable)
{
    for (auto iter : hashtable) {
        cout << iter.first << " ";
    }
    cout << "--------------------------------------" << endl;
}



//387. 字符串中的第一个唯一字符
int firstUniqChar(string s)
{
    if (s.size() == 0)
        return -1;
    unordered_map<char, int> hashtable;
    vector<char> vret;
    hashtable.rehash(s.size() - 1);
    int i = 0;
    auto begin = hashtable.begin();
    while (i < s.size()) {

        if (hashtable.count(s.at(i)) > 0) {
          //  cout << " s.at(i)= " << s.at(i) <<",value="<< hashtable[s.at(i)]<<endl;
            hashtable[s.at(i)] += 1;
            auto it=std::remove(vret.begin(), vret.end(), s.at(i));
            vret.erase(it, vret.end());
        }
        else {
           // cout << "insert s.at(i)=" << s.at(i) << endl;
            //hashtable.insert(make_pair(s.at(i), 1));
            //hashtable[s.at(i)] = 1;
            hashtable.emplace(make_pair(s[i], 1));
            vret.emplace_back(s[i]);
        }
        cout << "第" << i << "次插入结束后：";
        i++;
        //printHash(hashtable);
        printVector(vret);
    }

    //for (auto iter : hashtable) {
    //    cout << "iter.first=" << iter.first << ",second=" << iter.second << endl;
    //    // if (iter.second==1) {   
    //    //     return s.find(iter.first);
    //    // }

    //    continue;
    //}
    return -1;
}
//用哈希表判断重复，用链表来存储,上面用vector效率低
int firstUniqChar2(const string& s)
{
    if (s.size() == 0)
        return -1;
    unordered_map<char, int> hashtable;
    list<char> Mylist;
    int index = 0;
    while (index < s.size()) {

        if (hashtable.count(s.at(index)) > 0) {
            
			Mylist.remove(s.at(index));
        }
        else {

            hashtable.insert(make_pair(s.at(index), 1));
            Mylist.push_back(s.at(index));
        }
        index++;
    }
    if (Mylist.size() == 0)
        return -1;
    else
        return s.find(Mylist.front());
}

void test01()
{
	string str1("leetcode");
	string str2("loveleetcode");
    string teststr("loveleetcode");

    //cout << "等待遍历的字符串是:" << str1 << endl;
    //cout << firstUniqChar(str1) << endl;;
    cout << firstUniqChar2(str2) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif