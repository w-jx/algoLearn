#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> hashmap;
	for (int i = 0; i < nums.size(); i++) {
		if (hashmap.count(target - nums[i]) > 0)
			return { hashmap[target - nums[i]],i };
		hashmap.insert(make_pair(nums[i], i));
	}
	return { -1,-1 };

}
void test01()
{
	vector<int> v{ 1,6,32,10,27 };
	vector<int> ret = twoSum(v, 38);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif