#if 0
#include "../headers/wjxHeaders.h"

class cmp {
    
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2) {
        return p1.second < p2.second;
    }
};
//这个成功通过
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> nummap;
    for (int i = 0; i < nums.size(); ++i) {
        nummap[nums[i]]++;
    }
    priority_queue<std::pair<int, int>, vector<std::pair<int, int> >, cmp> que;

    for (auto iter = nummap.begin(); iter != nummap.end(); ++iter) {
        que.push({ (*iter).first,(*iter).second });
    }
    vector<int> res;
    int i = 0;
    while (i < k) {
        res.push_back(que.top().first);
        que.pop();
        ++i;
    }
    return res;

}
void test01()
{
    vector<int> nums{ 1,1,1,2,2,3 };
    printVector(topKFrequent(nums, 2));

}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif