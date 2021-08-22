#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//���Զ�ά������������
int sortinterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
	return 0;
}
//leetcode �����
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	if (intervals.empty()) {
		intervals.push_back(newInterval);
		return intervals;
	}
	int left = newInterval[0], right = newInterval[1];
	vector<vector<int>> ans;
	/*
		���� [left,right] = [5,8]
	[first,second] ,second<5˵�����ص�,
	����first>8,˵�����ص�,���Һ���Ķ������ص���
	*/
	bool placed = false;//�Ƿ��Ѿ�����������
	for (auto interval : intervals) {
		if (interval[0] > right) {
			if (!placed) {
				ans.push_back({ left,right });
				placed = true;
			}
			ans.push_back(interval);
		}
		else if (interval[1] < left) {
			ans.push_back(interval);
		}
		else {//���ص�������
			left = std::min(left, interval[0]);
			right = std::min(right, interval[1]);
		}
	}
	if (!placed)
		ans.push_back({ left,right });
	return ans;

}
void test01()
{
	vector<vector<int>> intervals{ {-1,0}, {1,3},{2,5} ,{6,9} };
	vector<int> newInterval{ -2,3 };
	cout << sortinterval(intervals, newInterval) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif