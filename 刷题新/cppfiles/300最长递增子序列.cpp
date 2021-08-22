#if 0
#include "../headers/wjxHeaders.h"

//方法1:动态规划 o(n^2)
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp(nums.size(),1);//dp[i]代表以nums[i]结尾,最长子序列长度
	dp[0] = 1;
	int maxres = 1;

	for (int i = 1; i < nums.size(); ++i) {
		for (int k = 0; k < i; k++) {
			if (nums[i] > nums[k]) {
				int temp = dp[k] + 1;
				dp[i] = std::max(dp[i], temp);
			}
			//如果nums[i]小于等于 min(nums[0],..nums[i-1]
			//所以最长子序列中只有nums[i],那么dp[i]就应该是默认值1
		}
		maxres = std::max(dp[i], maxres);
	}
	return maxres;

}
//方法2 用vector模拟栈
int lengthOfLIS2(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> mystack;//用vector模拟

	mystack.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] > mystack.back())
			mystack.push_back(nums[i]);
		else {//栈顶大于等于当前元素
			for (int j = 0; j < mystack.size(); ++j) {
				//注意这边必须是大于等于,[4,10,4..]这样的,否则第二个4不会替换第一个4
				//替换了10,导致序列长度减少1个
				if (mystack[j] >= nums[i]) {
					mystack[j] = nums[i];
					break;
				}
			}
		}
	}
	printVector(mystack);
	return mystack.size();

}
//上面  替换的部分,改成二分查找  找到>=nums[i]的下标 
//如果==nums[i]直接返回下标,如果大于,直接返回下一个
int search_right(vector<int>& mystack, int target) {
	int left = 0, right = mystack.size(),mid=0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (mystack[mid] == target)
			left = mid + 1;
		else if (mystack[mid] > target)
			right = mid;
		else if (mystack[mid] < target)
			left = mid + 1;
	}
	if (left > 0 && mystack[left - 1] == target)
		return left-1;
	return left;

}
int lengthOfLIS3(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> mystack;//用vector模拟

	mystack.push_back(nums[0]);
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] > mystack.back())
			mystack.push_back(nums[i]);
		else if (nums[i] == mystack.back())
			continue;
		else {//栈顶大于等于当前元素
			int pos = search_right(mystack, nums[i]);
			
			mystack[pos] = nums[i];
		
			
		}
	}
	return mystack.size();

}
int binary_search4(vector<int>& num_vec, int target) {
	int left = 0, right = num_vec.size(), mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (num_vec[mid] == target)
			left = mid + 1;
		else if (num_vec[mid] > target)
			right = mid;
		else if (num_vec[mid] < target)
			left = mid + 1;
	}
	if (left > 0 && num_vec[left - 1] == target)
		return left - 1;
	return left;

}
//2021年5月16日,复习
int lengthOfLIS4(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();
	int n = nums.size();
	vector<int> num_vec;
	num_vec.push_back(nums[0]);

	for (int i = 1; i < n; ++i) {
		if (nums[i] > num_vec.back())
			num_vec.push_back(nums[i]);
		else {// nums[i]<=num_vec.back()
			int pos = binary_search4(num_vec, nums[i]);
			num_vec[pos] = nums[i];
		}
	}
	return num_vec.size();
}
//2021年5月20日复习,超过99.46
int findpos(vector<int>& nums, int target) {
	int left = 0, right = nums.size(), mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	if (left > 0 && nums[left - 1] == target)
		return left - 1;
	return left;

}
int lengthOfLIS5(vector<int>& nums) {
	int n = nums.size();
	vector<int> stk;
	stk.push_back(nums[0]);
	for (int i = 1; i < n; ++i) {
		if (nums[i] > stk.back())
			stk.push_back(nums[i]);
		else {//nums[i]<=stk.back()
			int pos = findpos(stk, nums[i]);
			stk[pos] = nums[i];
		}
	}
	return stk.size();
}


void test01()
{
	vector<int> v{ 10,9,2,5,3,7,101,18 };
	vector<int> v1{ 0,1,0,3,2,3 };
	vector<int> v2{ 7,7,7,7,7,7,7 };
	vector<int> v3{ 4, 10, 4, 3, 8, 9 };
	cout << lengthOfLIS2(v) << endl;
	//cout << lengthOfLIS(v) << endl;
	//cout << lengthOfLIS(v1) << endl;
	//cout << lengthOfLIS(v2) << endl;
	//cout << lengthOfLIS(v3) << endl;
	cout << "--------------------------\n";
	//cout << lengthOfLIS3(v) << endl;
	//cout << lengthOfLIS3(v1) << endl;
	//cout << lengthOfLIS3(v2) << endl;
	//cout << lengthOfLIS4(v2) << endl;

}
//测试下二分查找,查找右边界的返回值
void test02()
{
	vector<int> lis{ 10 };
	cout << search_right(lis, 9) << endl;//我们应该把10替换成9

	vector<int> lis2{ 2,5 };
	cout << search_right(lis2, 3)<<endl;

	vector<int> lis3{ 2,3,7,101 };
	cout << search_right(lis3, 18) << endl;

	vector<int> lis4{ 4,10 };
	cout << search_right(lis4, 4) << endl;
}
int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}


#endif