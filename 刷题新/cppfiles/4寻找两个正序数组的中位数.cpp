#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() && nums2.empty())
		return 0.0;
	int n1 = nums1.size(), n2 = nums2.size(), ptr1 = 0, ptr2 = 0, ptr = 0;
	bool isEven = (n1 + n2) % 2 == 0;
	int backidx;
	vector<int> nums((n1 + n2) / 2 + 1, 0);

	while (true) {
		if (ptr1 < n1 && ptr2 < n2) {
			if (nums1[ptr1] < nums2[ptr2])
				nums[ptr++] = nums1[ptr1++];
			else
				nums[ptr++] = nums2[ptr2++];
		}
		else if (ptr1 < n1) {
			nums[ptr++] = nums1[ptr1++];
		}
		else if (ptr2 < n2)
			nums[ptr++] = nums2[ptr2++];
		if (ptr == (n1 + n2) / 2 + 1)
			break;
	}

	if (!isEven)
		return nums.back();
	return (nums[nums.size() - 1] + nums[nums.size() - 2]) * 0.5;
}
//��ϰ,��ʵ��,�ϲ�����,�����
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
	int n1 = nums1.size();
	int n2 = nums2.size();
	int n = n1 + n2;
	if (n == 0)
		return 0;
	vector<double> temp(n1 + n2);
	merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), temp.begin());
	if (n % 2 != 0)
		return temp[n / 2];
	return (temp[n / 2] + temp[n / 2 - 1]) * 0.5;
}
//����3:���������غϲ�,ֻ��Ҫ�ƶ�ָ��
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() && nums2.empty())
		return 0.0;
	int n1 = nums1.size();
	int n2 = nums2.size();
	//��������������ż����
	//�������Ļ�:(n1+n2)/2;
	//ż����:
	bool iseven = ((n1 + n2) % 2 == 0);

	int i = 0, j = 0, n = 0;
	int first = 0, second = 0;
	while (n < (n1 + n2) / 2 + 1) {
		if (i == n1) {
			if (n == (n1 + n2) / 2 - 1) {
				first = nums2[j];
			}
			if (n == (n1 + n2) / 2 ) {
				second = nums2[j];
				break;
			}
			++j;
		}
		else if (j == n2) {
			if (n == (n1 + n2) / 2 - 1) {
				first = nums1[i];
			}
			if (n == (n1 + n2) / 2) {
				second = nums1[i];
				break;
			}
			++i;
		}
		else if (nums1[i] < nums2[j]) {
			if (n == (n1 + n2) / 2 - 1) {
				first = nums1[i];
				
			}
			if (n == (n1 + n2) / 2) {
				second = nums1[i];
				break;
			}
			++i;
		}
		else if (nums1[i] >= nums2[j]) {
			if (n == (n1 + n2) / 2 - 1) {
				first = nums2[j];
			}
			if (n == (n1 + n2) / 2) {
				second = nums2[j];
				break;
			}
			++j;
		}
		++n;

	}
	if (iseven)
		return (first + second) * 0.5;
	return second;
}
//����4 ���ֲ���
/*
�������:
����1�ĳ��ȱȽ϶�
	1.����1�ڷָ��ߵ����û��Ԫ��
	2.����1�ڷָ��ߵ��ұ�û��Ԫ��
����1������2������ͬ
	3.�ָ���������1�����û��Ԫ��
	4.�ָ���������1���ұ�û��Ԫ��
*/
double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size())//ȷ����һ�����鳤�ȸ�С
		return findMedianSortedArrays4(nums2, nums1);
	int n1 = nums1.size();
	int n2 = nums2.size();
	//�ָ�����ߵ�Ԫ�ظ��� 
	int totalleft = (n1 + n2 + 1) / 2;
	//��nums1������[0,n1]���Һ��ʵķָ���
	/*
	Ҫ���㽻��С�ڵ�������
	nums1[i-1] <=nums2[j]
	nums2[j-1] <=nums1[i]	
	*/
	int left = 0, right = n1;
	//�ָ����ڵ�һ�������ұߵ��±�i,�ָ����ڵ�һ��������ߵ�Ԫ�ظ�������i
	//�ָ����ڵڶ��������ұߵ��±�j,�ָ����ڵڶ���������ߵ�Ԫ�ظ�������j
	//i+j=(n1+n2+1)/2;
#if true
	while (left < right) {//left==right�˳� 
		//�ָ����ڵ�һ�������ұߵ��±�i,�ָ����ڵ�һ��������ߵ�Ԫ�ظ���
		//int i = left + (right - left) / 2;
		//Ϊ�˷�ֹ[left,right]��ѭ��,������ĳ����,����i�������0,��������i-1����С��0
		int i = left + (right - left+1) / 2;
		int j = totalleft - i;
		//Ӧ����nums[i-1]<=nums2[j],�����������
		//˵���ָ���������1��̫������,Ӧ��������ߵ�
		if (nums1[i - 1] > nums2[j]) {
			right = i - 1;//��һ������������[left,i-1]
		}
		else {
			//��һ����������[i,right]
			left = i;//[left(i),right]����left,��ѭ��
		}
	}//while
#endif

#if false //��������������ж�  nums2[j-1] <=nums1[i]	
	while (left < right) {//left==right�˳� 
		//�ָ����ڵ�һ�������ұߵ��±�i,�ָ����ڵ�һ��������ߵ�Ԫ�ظ���
		//int i = left + (right - left) / 2;
		//Ϊ�˷�ֹ[left,right]��ѭ��,������ĳ����,����i�������0,��������i-1����С��0
		int i = left + (right - left + 1) / 2;
		int j = totalleft - i;
		//Ӧ����nums[i-1]<=nums2[j],�����������
		//˵���ָ���������1��̫������,Ӧ��������ߵ�
		if (nums1[i - 1] > nums2[j]) {
			right = i - 1;//��һ������������[left,i-1]
		}
		else {
			//��һ����������[i,right]
			left = i;//[left(i),right]����left,��ѭ��
		}
	}//while
#endif
	int i = left;
	int j = totalleft - i;
	//��Ӧ����1�ڷָ��ߵ����û��Ԫ��
	//�����ڱȽϵ�ʱ��,�ڷָ������Ҫѡ�����ֵ,����ѡ������1�����
	int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
	//����1�ڷָ��ߵ��ұ�û��Ԫ��
	//�����ڱȽϵ�ʱ��,�ָ����ұ�Ҫѡ����Сֵ,����ѡ������1���ұ�
	int nums1RightMin = i ==n1?INT_MAX: nums1[i];
	//����2�ڷָ��ߵ����û��Ԫ��
	//�����ڱȽϵ�ʱ��,�ָ������Ҫѡ�����ֵ,����ѡ������2�����
	int nums2LeftMax = j==0?INT_MIN:nums2[j - 1];
	//����2�ڷָ��ߵ��Ҳ�û��Ԫ��
	//�����ڱȽϵ�ʱ��,�ָ����ұ�Ҫѡ����Сֵ,����ѡ������2���ұ�
	int nums2RightMin = j==n2?INT_MAX:nums2[j];

	if ((n1 + n2) % 2 == 1)
		return std::max(nums1LeftMax, nums2LeftMax);
	return static_cast<double>(std::max(nums1LeftMax, nums2LeftMax)+ std::min(nums1RightMin, nums2RightMin))*0.5


}
void test01()
{
	vector<int> v1{ 1,3,5,7,9 };
	vector<int> v2{ 2,4,6,8,10 };
	cout << findMedianSortedArrays2(v1, v2) << endl;
}
void test02() {
	vector<int> v1{ 0, 0, 0, 0, 0 };
	vector<int> v2{ -1, 0, 0, 0, 0, 0, 1};
	//vector<int> v1{ 1,3,5,7,9 };
	//vector<int> v2{ 2,4,6,8,10 };
	int n1 = v1.size();
	int n2 = v2.size();
	vector<int> temp(n1 + n2);
	
	std::merge(v1.begin(), v1.begin()+n1, v2.begin(), v2.end(), temp.begin());

	for (auto iter : temp)
		cout << iter << " ";
	cout << endl;
}
void test03()
{
	vector<int> v1{ 1,3,5,7,9 };
	vector<int> v2{ 2,4,6,8,10 };
	cout << findMedianSortedArrays3(v1, v2) << endl;

}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
#endif