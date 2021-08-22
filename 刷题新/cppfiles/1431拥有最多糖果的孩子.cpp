#if 0
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
leecode题目介绍:
给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目。

对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目



*/
bool isGreater(vector<int>& candies, int elem) {
	bool flag = true;
	for (auto iter : candies) {
		if (elem < iter)
			flag = false;
	}
	return flag;
}
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

	vector<bool> v;
	for (auto iter : candies) {
		v.push_back(isGreater(candies, iter+ extraCandies));
	}

	return v;

}
vector<bool> kidsWithCandies2(vector<int>& candies, int extraCandies) {

	vector<bool> v;
	int lastNum = candies[0];
	bool flag = false;
	for (auto iter : candies) {
		
		if ((iter + extraCandies) >= lastNum) {
			flag = true;	
		}
		v.push_back(flag);
		if (flag) {
			lastNum = iter + extraCandies;
			flag = false;
		}		
	}
	if (candies[0] + extraCandies < lastNum) {
		v[0] = false;
	}

	return v;

}

void printVector(vector<bool>& v) {
	for (auto iter : v) {
		cout << iter << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v = { 2,3,5,1,3 };
	//vector<int> v = { 4,2,1,1,2 };
	int extraCandies = 3;
	vector<bool> v1 = kidsWithCandies(v, extraCandies);
	printVector(v1);
	//printVector(kidsWithCandies(v, extraCandies));
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif