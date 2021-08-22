#if 0
#include "../headers/wjxHeaders.h"

/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

*/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if (nums.size() < 2)
		return false;
	unordered_map<int, vector<int>> hashtable;
	
	int index = 0;
	int length = nums.size();
	while (index < length) {
		if (hashtable.count(nums[index]) > 0) {
			
			for (auto iter : hashtable[nums[index]]) {
				if (abs(iter - index) <= k)
					return true;
			}
			hashtable[nums[index]].push_back(index);
		}
		else {
			hashtable[nums[index]].push_back(index);
		}
			

		index++;
	}
	return false;
}
void test01()
{
	//unordered_map<int, vector<int>> hashtable;
	//hashtable[0].push_back(1);
	//hashtable[0].push_back(2);
	//hashtable[0].push_back(3);
	//for (auto iter : hashtable) {
	//	for (auto it : iter.second)
	//		cout << it << " ";
	//
	//	cout << endl;
	//}
	

}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif