#if 0
#include "../headers/wjxHeaders.h"
/*
* 没思路
leecode题目介绍:
其他数字出现3次,有个数字只出现一次,找到那个数字

*/

int singleNumber(vector<int>& nums) {

	map<int , int > m;
	int size = nums.size();
	for (size_t i = 0; i < size; i++) {
		
		auto iter= m.find(i);

		

	}

}
void test01()
{
	vector<int> v = { 9,1,7,9,7,9,7 };
	cout << singleNumber(v) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif