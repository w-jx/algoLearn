#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


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
//复习,简单实现,合并排序,在求解
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
//方法3:不用真正地合并,只需要移动指针
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() && nums2.empty())
		return 0.0;
	int n1 = nums1.size();
	int n2 = nums2.size();
	//看是奇数个还是偶数个
	//奇数个的话:(n1+n2)/2;
	//偶数个:
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
//方法4 二分查找
/*
特殊情况:
数组1的长度比较短
	1.数组1在分割线的左边没有元素
	2.数组1在分割线的右边没有元素
数组1和数组2长度相同
	3.分割线在数组1的左边没有元素
	4.分割线在数组1的右边没有元素
*/
double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size())//确保第一个数组长度更小
		return findMedianSortedArrays4(nums2, nums1);
	int n1 = nums1.size();
	int n2 = nums2.size();
	//分割线左边的元素个数 
	int totalleft = (n1 + n2 + 1) / 2;
	//在nums1的区间[0,n1]查找合适的分割线
	/*
	要满足交叉小于等于条件
	nums1[i-1] <=nums2[j]
	nums2[j-1] <=nums1[i]	
	*/
	int left = 0, right = n1;
	//分割线在第一个数组右边的下标i,分割线在第一个数组左边的元素个数就是i
	//分割线在第二个数组右边的下标j,分割线在第二个数组左边的元素个数就是j
	//i+j=(n1+n2+1)/2;
#if true
	while (left < right) {//left==right退出 
		//分割线在第一个数组右边的下标i,分割线在第一个数组左边的元素个数
		//int i = left + (right - left) / 2;
		//为了防止[left,right]死循环,把区间改成这个,这样i不会等于0,所以下面i-1不会小于0
		int i = left + (right - left+1) / 2;
		int j = totalleft - i;
		//应该是nums[i-1]<=nums2[j],现在这种情况
		//说明分割线在数组1中太靠右了,应该往左边走点
		if (nums1[i - 1] > nums2[j]) {
			right = i - 1;//下一轮搜索的区间[left,i-1]
		}
		else {
			//下一轮搜索区间[i,right]
			left = i;//[left(i),right]进入left,死循环
		}
	}//while
#endif

#if false //按照这个条件来判断  nums2[j-1] <=nums1[i]	
	while (left < right) {//left==right退出 
		//分割线在第一个数组右边的下标i,分割线在第一个数组左边的元素个数
		//int i = left + (right - left) / 2;
		//为了防止[left,right]死循环,把区间改成这个,这样i不会等于0,所以下面i-1不会小于0
		int i = left + (right - left + 1) / 2;
		int j = totalleft - i;
		//应该是nums[i-1]<=nums2[j],现在这种情况
		//说明分割线在数组1中太靠右了,应该往左边走点
		if (nums1[i - 1] > nums2[j]) {
			right = i - 1;//下一轮搜索的区间[left,i-1]
		}
		else {
			//下一轮搜索区间[i,right]
			left = i;//[left(i),right]进入left,死循环
		}
	}//while
#endif
	int i = left;
	int j = totalleft - i;
	//对应数组1在分割线的左边没有元素
	//这样在比较的时候,在分割线左边要选出最大值,不会选中数组1的左边
	int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
	//数组1在分割线的右边没有元素
	//这样在比较的时候,分割线右边要选出最小值,不会选中数组1的右边
	int nums1RightMin = i ==n1?INT_MAX: nums1[i];
	//数组2在分割线的左侧没有元素
	//这样在比较的时候,分割线左边要选出最大值,不会选中数组2的左边
	int nums2LeftMax = j==0?INT_MIN:nums2[j - 1];
	//数组2在分割线的右侧没有元素
	//这样在比较的时候,分割线右边要选出最小值,不会选中数组2的右边
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