#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
leecode题目介绍:


*/
void printvectorvector(vector<vector<int>>& nums);
vector<vector<int>> vret;
vector<vector<int>> merge(vector<vector<int>>& intervals) {  //根据答案提示写的拉跨版

    if (intervals.empty()) return vret;
    sort(intervals.begin(), intervals.end());
    vector<int> v;
    for (auto i = 0; i < intervals.size(); i++) {
        auto one = intervals[i][0];
        auto two = intervals[i][1];
        if (v.empty()) {
            v.push_back(one);
            v.push_back(two);
            continue;
        }
        else if (!v.empty()) {
            if (one <= v[1]) {//可以合并
                if (v[1] < two)
                    v[1] = two;
                continue;
            }
            else {
                vret.push_back(v);
                v.clear();
                i--;
                continue;
            }
        }
    }
    vret.push_back(v);
    return vret;
}

vector<vector<int>> merge2(vector<vector<int>>& intervals) {

    if (intervals.empty()) return vret;

    vector<int> v;
    //[[1,4],[0,4]]
    //[[1,3],[2,6],[8,10],[15,18]]
    for (int i = 0; i < intervals.size(); i++) {
        auto one = intervals[i][0];
        auto two = intervals[i][1];
        if (v.empty()) {
            v.push_back(one);
            v.push_back(two);
            continue;
        }
        if (one >= v[0]) {

            if (v[1] >= one) { //可以合并

                if (v[1] < two) {
                    v[1] = two;
                }

                vret.push_back(v);
                v.clear();
                continue;
            }
            else if (v[1]<one){
                vret.push_back(v);
                v.clear();
                i--;
                continue;
            }

        }
        else if (one < v[0]) {

            if (two >= v[0]) { //可以合并

                if (v[1] < two) {
                    v[1] = two;
                }
                v[0] = one;

                vret.push_back(v);
                v.clear();
                continue;
                
            }
            else if (two < v[0]) {
                vret.push_back(v);
                v.clear();
                //v.push_back(one);
                //v.push_back(two);
                i--;
                continue;
            }
           
        }
       


    }
    return vret;
}
void printvectorvector(vector<vector<int>>& nums) {
    for(auto iter:nums) {
        for (auto iter2 : iter) {
            cout << iter2 << " ";
        }
    }
    cout << endl;;
}

void test01()
{
    vector<vector<int>> nums = { {1,3},{17,23},{8,10} ,{2,6},{15,18} };

    printvectorvector(merge(nums));

    /*vector<vector<int>> nums = { {1,4},{0,4} };

    printvectorvector(merge(nums));*/
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif