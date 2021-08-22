#if 0
#include "../headers/wjxHeaders.h"


vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    if (list1.size() == 0 || list2.size() == 0)
        return {};
    unordered_map<string, int> hashtable1;
    unordered_map<string, int> hashtable2;
    vector<string> vret;

    int index = 0;
    int num = 0;
    while (index < list1.size()) {
        hashtable1.insert(make_pair(list1[index], index));
        index++;
    }

    index = 0;
    while (index < list2.size()) {
        if (hashtable1.count(list2.at(index)) > 0) {
            int sumindex = hashtable1[list2.at(index)] + index;
            //cout << "string=" << list2.at(index) << ",sumindex="<<sumindex << endl;
            if (hashtable2.empty()) {
                hashtable2.insert(make_pair(list2[index], sumindex));
                num++;
            }
            else {
                auto iter = hashtable2.begin();

                if (sumindex == iter->second) {
                    hashtable2.insert(make_pair(list2[index], sumindex));
                }
                else if (sumindex < iter->second) {
             
                    int value = iter->second;
                    while (true) {
                        auto it = hashtable2.begin();
                        if (it == hashtable2.end())
                            break;
                        if (it->second == value) {
                            hashtable2.erase(it->first);
                        }
                    }
                    hashtable2.insert(make_pair(list2[index], sumindex));
                }
            }
        }
        index++;
    }//while 
    for (auto it : hashtable2) {
        vret.push_back(it.first);
    }
    return vret;
}
void test01()
{
	vector<string> list1{ "Shogun","Tapioca Express","Burger King","KFC" };
	vector<string> list2{ "Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun" };
    vector<string> list3{ "Shogun","Tapioca Express","Burger King","KFC" };
    vector<string> list4{ "KFC", "Shogun", "Burger King" };

	//printVector(findRestaurant(list1, list2));//这两个测试用例通过
    printVector(findRestaurant(list3, list4));//这两个测试用例通过

}
int main()
{
    test01();
    return 0;
    system("pause");

}
#endif