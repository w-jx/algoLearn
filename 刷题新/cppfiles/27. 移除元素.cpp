#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
int removeElement(vector<int>& nums, int val) {
	int m_Size = nums.size();

	for (int i = 0; i < m_Size; i++) {
		if (nums[i] == val) {
			auto iter = nums.begin() + i;
			nums.erase(iter);
			m_Size--;
			i--;
		}
	}
	return m_Size;

}
int removeElement2(vector<int>& nums, int val) {
	if (nums.empty()) return 0;
	int len = nums.size();
	int index = len;
	
	for (size_t i = 0; i < len; i++) {
		if (nums[i] != val) {
			nums.resize(nums.size()+1);
			nums[index++] = nums[i];
		}
	}
	nums.erase(nums.begin(), nums.begin() + len);

	return nums.size();

}
void test01()
{
	vector<int> v = { 1,3,4,0,19,2,3,4,6 };

	int len = removeElement(v, 3);
	for (size_t i = 0; i < len; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	int len2 = removeElement2(v, 3);
	for (size_t i = 0; i < len2; i++) {
		cout << v[i] << " ";
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