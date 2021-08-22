#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
int arrayPairSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int sums = 0;
	int index = 1;
	for (auto iter : nums) {
		index++;
		if (index % 2 == 0) {
			sums +=iter;
			index = 0;
		}
		
	}

	return sums;
}
int arrayPairSum2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int sums = 0;
	
	int len = nums.size();
	
	for (size_t i = 0; i < len; i++) {
		if (i % 2 != 0)
			continue;
		sums += nums[i];
	}

	return sums;
}
void test01()
{
	vector<int> v = { 1,18,7,-3,2,15,32 };
	cout << arrayPairSum(v) << endl;
	cout << arrayPairSum2(v) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif