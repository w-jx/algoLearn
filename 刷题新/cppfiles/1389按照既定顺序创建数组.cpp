#if 0

#include "../headers/wjxHeaders.h"

/*
leecodeÌâÄ¿½éÉÜ:


*/
vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
	
	vector<int> target;

	int size = nums.size();
	for (int i = 0; i < size; i++) {
		auto iter = target.begin() + index[i];
		target.insert(iter, nums[i]);
	}
	return target;

}
void test01()
{
	vector<int>nums = { 0,1,2,3,4 };
	vector<int> index = { 0,1,2,2,1 };
	auto  p = createTargetArray(nums, index);
	printVector(p);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif