#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
struct Cmp {
    bool operator()(vector<int>& v1, vector<int> &v2) {
        //int dis1 = sqrt(abs(v1[0]) * abs(v1[0]) + abs(v1[1]) * abs(v1[1]));
        //int dis2 = sqrt(abs(v2[0]) * abs(v2[0]) + abs(v2[1]) * abs(v2[1]));
        //不要sqrt,int型的会出现相同元素
        int dis1 = abs(v1[0]) * abs(v1[0]) + abs(v1[1]) * abs(v1[1]);
        int dis2 = abs(v2[0]) * abs(v2[0]) + abs(v2[1]) * abs(v2[1]);
        return dis1 < dis2;
    }
};
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), Cmp());
    vector<vector<int>> res(k);

    std::copy(points.begin(), points.begin() + k, res.begin());

    return res;

}
void test01()
{
    vector<vector<int>> points{ {1,3},{-2,2} };
    //auto res = kClosest(points, 1);
    //printvectorvector(res);
    vector<vector<int>> points2{ {-5,4 }, { -6,-5 }, { 4,6 } };
    sort(points2.begin(), points2.end(), Cmp());
    printvectorvector(points2);
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif