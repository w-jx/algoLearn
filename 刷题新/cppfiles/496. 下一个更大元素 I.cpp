#if 0
#include "../headers/wjxHeaders.h"

/*
* ͨ��
* 
* ��ÿ�εĽⷨ������rightMax����,������õ���ջ,���������Ƶ�
* ��ʵ�ҵ�˼·���ǵ���ջ
* 
* 
˼·�����Ȼ��nums2��rightMax����
����rightMax[i]�洢����nums2[i]�Ҳ��һ��������Ԫ�ص�����
Ȼ����Ҫһ����ϣ��,�洢nums[2]�е�ÿһ��Ԫ�صĶ�Ӧ������

����nums1,����һ���ҵ���Ԫ�ض�Ӧ��nums2�е��±�idx
������rightMax[idx]�õ����

*/
//rightMax[i]���ұ߱�nums[i]����±�,���û�о���-1
vector<int> getRightMax(vector<int>& nums,int& maxval)
{
	int n = nums.size();
	vector<int> rightMax(n, -1);
	
	for (int i = n - 2; i >= 0; --i) {
		maxval = std::max(maxval, nums[i]);
		if (nums[i] < nums[i + 1]) {
			rightMax[i] = i + 1;
		}
		else if (nums[i] == nums[i + 1])
			rightMax[i] = rightMax[i + 1];
		else {//nums2[i]>nums2[i+1]
			int idx = i + 1;
			while (idx < n && rightMax[idx] < n && rightMax[idx] != -1) {
				if (nums[i] < nums[rightMax[idx]]) {
					rightMax[i] = rightMax[idx];
					break;
				}
				else {
					idx = rightMax[idx];
				}
			}
		}
	}
	return rightMax;
}
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int maxval = nums2.back();
	//rightMax[i]���ұ߱�nums2[i]����±�,���û�о���-1
	vector<int> rightMax = getRightMax(nums2, maxval);
	
	
	vector<int> num_map(maxval+1);
	for (int i = 0; i < n2; ++i)
		num_map[nums2[i]] = i;
	
	vector<int> ret(n1);
	for (int i = 0; i < n1; ++i) {
		int curnum = nums1[i];//��ǰԪ��
		int curidx = num_map[curnum];//��ǰԪ����nums����������±�
		int curbig_idx = rightMax[curidx];//������Ԫ���±�
		if (curbig_idx == -1)
			ret[i] = -1;
		else
			ret[i] = nums2[curbig_idx];
	}
	return ret;
}
//�����ķ���,����ջ
vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int maxval = *max_element(nums2.begin(), nums2.end());
	vector<int> ret_hash(maxval + 1,-1);

	vector<int> stk;//����ջ
	stk.reserve(n2);
	for (int i = 0; i < n2; ++i) {
		while (!stk.empty() && stk.back() < nums2[i]) {
			ret_hash[stk.back()] = nums2[i];
			stk.pop_back();
		}
		stk.push_back(nums2[i]);
	}
	//����nums1�õ����
	vector<int> ret(n1);
	for (int i = 0; i < n1; ++i) {
		ret[i] = ret_hash[nums1[i]];
	}
	return ret;

}
void test01()
{
	vector<int> nums1{ 1,3,5,2,4 }, nums2{ 6,5,4,3,2,1,7 };
	printVector(nextGreaterElement(nums1, nums2));

}
int main()
{
	test01();
}
#endif