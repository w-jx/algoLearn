#if 0
#include "../headers/wjxHeaders.h"


vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() == 0 || nums2.size() == 0)
		return {};
	int size1 = nums1.size();
	int size2 = nums2.size();
	unordered_map<int, int> hashtable;
	
	vector<int> vret;
	int index = 0;
	
	while (index < size1) {
		if (hashtable.count(nums1[index]) > 0)
			hashtable[nums1[index]]++;
		else 
			hashtable.emplace(make_pair(nums1[index], 1));
		index++;
	}
	index = 0;
	while (index < size2) {
		if (hashtable.count(nums2[index]) > 0 && hashtable[nums2[index]]>0) {
				hashtable[nums2[index]]--;
				vret.emplace_back(nums2[index]);
			
		}
		index++;
	}
		
	return vret;
}
void test01()
{
	//不能把v1,v2识别成元素2，正确答案是2，2
	//也不能把v3,v4识别成是4，9，4，9，正确答案是4，9
	vector<int> v1{ 1,2,2,1 };
	vector<int> v2{ 2,2 }; 
	vector<int> v3{ 4,9,5 };
	vector<int> v4{ 9,4,9,8,4 };
	printVector(intersect(v1, v2));
	printVector(intersect(v3, v4));
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif