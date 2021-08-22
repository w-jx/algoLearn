#if 0
#include "../headers/wjxHeaders.h"
/*

leecodeÌâÄ¿½éÉÜ:

*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	set<int> s;
	size_t size1 = nums1.size();
	size_t size2 = nums2.size();

	for (auto i = 0; i < size1; i++) {

		for (int j = 0; j < size2; j++) {
			if (nums1[i] == nums2[j]) {
				s.insert(nums1[i]);
				break;
			}		
		}
		
	}
	vector<int> v;
	for (auto iter : s) {
		v.push_back(iter);
	}
	
	return v;

}
void test01()
{
	vector<int> v1 = { 1,2,3,4,5,6 };
	vector<int> v2 = { 4,5,6,7,8,9 };
	
	printVector(intersection(v1, v2));

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif