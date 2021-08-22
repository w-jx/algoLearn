#if 0
#include "../headers/wjxHeaders.h"

//允许有两个重复的
int removeDuplicates(vector<int>& nums) {
	int len = nums.size();
	if (len == 2)
		return len;
	int i = 0;
	int j = i + 1;
	for (; j < len; j++) {
		if (nums[j] != nums[j - 1]) {
			i++;
			nums[i] = nums[j];
			continue;
		}
		if (nums[j] == nums[j - 1]) {
			if ((j + 1 == len) || nums[j] != nums[j + 1]) {
				i++;
				nums[i] = nums[j];
			}
		}
	}
	return i + 1;

}
void test01()
{
	vector<int> v1{ 0,0,1,1,1,2,2,2,2,3 };
	vector<int> v2{ 0,0,0};
	auto len = removeDuplicates(v2);
	for (auto i = 0; i < len; i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif