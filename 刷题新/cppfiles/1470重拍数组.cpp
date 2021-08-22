#if false
#include <iostream>
using namespace std;
#include <vector>
/*
leecode题目介绍:
给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。

请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。
输入：nums = [2,5,1,3,4,7], n = 3
输出：[2,3,5,4,1,7]
解释：由于 x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 ，所以答案为 [2,3,5,4,1,7]


*/
void printVector(vector<int>& v);

vector<int> shuffle(vector<int>& nums, int n) {
	vector<int> v;

	vector<int> v1;
	vector<int> v2;
	int k = 0;
	for (int i = 0; i < n; i++) {
		v1.push_back(nums[i]);
	}
	for (int i = 0; i < n; i++) {
		v2.push_back(nums[n + i]);
	}


	for (int i = 0; i < n; i++) {
		v.push_back(v1[i]);
		v.push_back(v2[i]);

	}
	return v;

}

vector<int> shuffle1(vector<int>& nums, int n) {
	vector<int> v;

	for (int i = 0; i < n; i++) {
		
		v.push_back(nums[i]);
		v.push_back(nums[n + i]);
	}

	return v;

}

void printVector(vector<int>& v)
{
	for (auto iter : v) {
		cout << iter << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	printVector(v);

	auto v1 = shuffle1(v, 3);

	printVector(v1);


}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif