#if 0
#include "../headers/wjxHeaders.h"
/*



*/
int findMinArrowShots(vector<vector<int>>& points) {
	if (points.empty()) //空数据，返回0
		return 0;
	sort(points.begin(), points.end(), [=](vector<int>& p1, vector<int>& p2)->bool {
		return p1.front() < p2.front();
		});

	int shoot_num = 1;//最少需要一个箭
	int shoot_begin = points.front().front();
	int shoot_end = points.front().back();//初始化 射击区间

	for (int i = 1; i < points.size(); ++i) {
		if (points[i].front()<=shoot_end && points[i].front()>=shoot_begin) {
			shoot_begin = points[i].front();//更新射击区间左端
			if (points[i].back() < shoot_end) 
				shoot_end = points[i].back();//更新射击区间右端
		}
		else {//说明 射击区间不能被更新了，得整新射击区间了
			++shoot_num;
			shoot_begin = points[i].front();
			shoot_end = points[i].back();
		}
	}
	return shoot_num;

}
void test01()
{ 
	//int a = 1,b=2;
	//int* p = &a;
	//*(p+1)= b;

	//cout << p[0] << endl;

	//cout << p[1] << endl;
	//cout << *(p) << endl;

	//cout << *(p++) << endl;
	//cout << *(p) << endl;
	//cout << *(p) << endl;

	//int arr[2] = { 1,2 };
	//cout << arr[2] << endl;
	//cout << *(arr+2) << endl;
	//cout << *(arr + 2) << endl;
	//cout << *(arr + 2) << endl;
	//int* p = arr;
	//cout << p[2] << endl;
	//cout << *(p+2) << endl;


}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif