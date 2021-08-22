#if 0
#include <iostream>
#include <vector>
using namespace std;
/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
void printVector(vector<int>& nums)
{
	for (auto iter : nums) {
		cout << iter << " ";
	}
	cout << endl;
}
typedef void(*PRINTVECTOR)(vector<int>&);
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


	PRINTVECTOR print = printVector;
	print(nums);
	return m_Size;
}
void test01()
{
	//vector<int> v;
	//v.push_back(3);
	//v.push_back(2);
	//v.push_back(2);
	//v.push_back(3);
	//cout << removeElement(v, 3) << endl;


	vector<int> v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(0);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	
	cout << removeElement(v, 2) << endl;
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif