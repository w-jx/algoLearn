#if 0
#include "../headers/wjxHeaders.h"

//����1-��ָ�뷨
/*
��һ�α������Ȱ�0���������ף�����һ���±ָ꣨�룩����¼0��λ��
�ڶ��α�������1����0�ĺ��
*/
void sortColors(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1)
		return;
	int idx = 0;
	for (int i = 0; i < len; i++) {
		if (nums.at(i) == 0) {
			swap(nums[i], nums[idx]);
			++idx;
		}	
	}
	for (int i = idx; i < len; i++) {
		if (nums.at(i) == 1) {
			swap(nums[i], nums[idx]);
			++idx;
		}
	}

}
//˫ָ�뷨
void sortColors2(vector<int>& nums)
{
	int len = nums.size();
	if (len == 1)
		return;
	int p0 = 0, p1 = 0;
	for (int i = 0; i < len; i++) {
		if (nums[i] == 1) {
			swap(nums[i], nums[p1]);
			p1++;
			continue;
		}
		if (nums[i] == 0) {
			swap(nums[i], nums[p0]);
			if (p0 < p1)
				swap(nums[i], nums[p1]);
			p0++;
			p1++;
			continue;
		}

	}
}
//��ָ�뷨
void test01()
{
	vector<int> v{ 0,2,2,1,1,0,1,2,1 };
	sortColors(v);
	printVector(v);
}
//˫ ָ�뷨
void test02()
{
	vector<int> v{ 0,2,2,1,1,0,1,2,1 };
	sortColors2(v);
	printVector(v);
}
int main()
{
	//test01();//��ָ�뷨
	test02();//˫ָ�뷨
	system("pause");
	return 0;
}


#endif