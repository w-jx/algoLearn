#if 0
#include "../headers/wjxHeaders.h"
/*
̰���㷨��

����������䣬��������Щ���以���ص�����Ҫ�Ƴ���������ٸ�������ֹ���������ص���

���ȱ�����βС�Ҳ��ཻ����
�䡣

*/
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	if (intervals.empty())
		return 0;
	int n = intervals.size();
	sort(intervals.begin(), intervals.end(), [=](vector<int>& v1, vector<int>& v2)->bool {
		return v1.back() < v2.back();
		});//���ս�β ��С��������
	int total = 0, prev = intervals.front().back();//[0][1],��һ��Ԫ�صĽ�β

	for (int i = 1; i < n; ++i) {
		if (intervals[i][0] < prev)//[1,2] .[1,3]�ص���
			++total;
		else {
			prev = intervals[i][1];//[1,2] [3,9] ���ص���������prev = [3,9]
		}
	}//�ӵڶ���Ԫ�ر���

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