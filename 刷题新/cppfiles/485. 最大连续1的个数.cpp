#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
int findMaxConsecutiveOnes(vector<int>& nums) {

	if (nums.empty()) return 0;
	size_t len = nums.size();
	int maxlength = 0;
	int count = 0;
	for (size_t i = 0; i < len; i++) {
		if (nums[i] != 0)
			count++;
		else if (nums[i] == 0) {
			if (count > maxlength)
				maxlength = count;
			count = 0;
		}
	}
	if (count > maxlength)
		maxlength = count;
	return maxlength;
}
void test01()
{
	vector<int> v = { 1,1,1,0,1,1,0,1,1,1,1 };
	cout << findMaxConsecutiveOnes(v) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif