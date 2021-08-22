#if 0
#include "../headers/wjxHeaders.h"
/*
贪心算法：

给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。

优先保留结尾小且不相交的区
间。

*/
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty())
		return 0;
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), [=](vector<int>& v1, vector<int>& v2)->bool {
		return v1.back() < v2.back();
		});//按照结尾 从小到大排序
	int total = 0, prev = intervals.front().back();//[0][1],第一个元素的结尾

	for (int i = 1; i < n; ++i) {
		if (intervals[i][0] < prev)//[1,2] .[1,3]重叠了
			++total;
		else {
			prev = intervals[i][1];//[1,2] [3,9] 不重叠，更新下prev = [3,9]
		}
	}//从第二个元素遍历

	return total;

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