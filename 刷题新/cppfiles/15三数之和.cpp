#if 0
#include "../headers/wjxHeaders.h"

//先尝试输出一个数字所有的三个元素的组合
//为了避免重复,采取子集2的方式处理
vector<vector<int>>res;
vector<int> item;
void dfs(int start,vector<int>&nums) {
	if (item.size() > 3)
		return;
	if (item.size() == 3) {
		res.push_back(item);
		return;
	}
	unordered_set<int> hashset;
	for (int i = start; i < nums.size(); ++i) {
		if (hashset.find(nums[i]) != hashset.end())
			continue;
		hashset.insert(nums[i]);
		item.push_back(nums[i]);
		dfs(i + 1, nums);
		item.pop_back();
	}
}
vector<vector<int>> helper(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	dfs(0, nums);
	return res;
}
void dfs2(int start, vector<int>& nums,int sum) {
	if (item.size() > 3)
		return;
	if (item.size() == 3) {
		if (sum == 0) {
			res.push_back(item);
		}
		return;
			
		
	}
	unordered_set<int> hashset;
	for (int i = start; i < nums.size(); ++i) {
		if (hashset.find(nums[i]) != hashset.end())
			continue;
		hashset.insert(nums[i]);
		item.push_back(nums[i]);
		sum += nums[i];
		dfs2(i + 1, nums,sum);
		item.pop_back();
		sum -= nums[i];
	}
}
//下面尝试解决问题
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	dfs2(0, nums, 0);
	return res;
}
//结论：利用回溯无法解决问题
//leetcode答案题解
vector<vector<int>> threeSum2(vector<int>& nums) {
	if (nums.size() < 3)
		return {};
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int i = 0;//第一个数下标初始化为0
	//排序后,第一个数小于等于0,最后一个数大于等于0,才可能有三数之和等于0
	if (nums[0] <= 0 && nums.back() >= 0) {
		while (i < n - 2) {//要有三个数,i<n-2才能保证有三个数
			if (nums[i] > 0)//排序后第一个数大于0,肯定无法凑成
				break;//最左侧已经大于0了,后面的三数之和肯定大于0
			int first = i + 1;//第二个是第一个数后面一个
			int last = n - 1;//第三个数从最后一个开始
			while (first < last) {
				//if (nums[i] * nums[last] > 0)
				//	break;//三个数字是同样的符号//这个越界了
				if ((nums[i] > 0 && nums[last] > 0) || (nums[i] < 0 && nums[last] < 0))
					break;//三个数字是同样的符号,和肯定不是0
				int sum = nums[i] + nums[first] + nums[last];
				if (sum == 0) {
					res.push_back({ nums[i],nums[first],nums[last] });
				}
				//一定是小于等于,千万注意这边不是else if ,而是if
				if (sum <= 0) {
					while (first < n - 2 && nums[first] == nums[first + 1])
						++first;
					++first;//去除重复值,再向右移动一个位置
				}
				else if (sum > 0) {
					while (last > 2 && nums[last] == nums[last - 1])
						--last;
					--last;//去除重复值
				}
			}//while first<last;
			//i前进
			while (i + 1 < n - 2 && nums[i] == nums[i + 1])
				++i;//去除重复值,前进
			++i;
		}//while i<n-2
	}
	return res;
}
vector<vector<int>> threeSum3(vector<int>& nums) {
	if (nums.size() < 2)
		return {};
	sort(nums.begin(), nums.end());
	int n = nums.size();
	if (nums.front() <= 0 && nums.back() >= 0) {
		for (int i = 0; i < n - 2;) {
			if (nums[i] > 0) break;
			int first = i + 1;
			int last = n - 1;
			if (nums[i] < 0 && nums[last] < 0)
				break;

			while (first < last) {

				int sum = nums[i] + nums[first] + nums[last];
				if (sum == 0) {
					res.push_back({ nums[i],nums[first],nums[last] });

				}
				if (sum <= 0) {
					//first前进
					while (first + 1 < n - 1 && nums[first] == nums[first + 1])
						++first;
					++first;
				}
				else if (sum > 0) {
					//last 后退
					while (last - 1 > 1 && nums[last] == nums[last - 1])
						--last;
					--last;
				}


			}//while first<last;
			while (i + 1 < n - 2 && nums[i + 1] == nums[i])
				++i;
			++i;
		}//i<n-2;
	}//if
	return res;
}
//2021年5月28日,复习,好理解的标准答案
vector<vector<int>> threeSum2(vector<int>& nums) {
	if (nums.size() < 2)
		return {};
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int> > res;
	int first = 0;
	if (nums.front() <= 0 && nums.back() >= 0) {
		while (first < n - 2) {
			if (nums[first] > 0)
				break;
			int second = first + 1;
			int third = n - 1;

			while (second < third) {
				//if (nums[first]>0 && nums[third]>0)
				 //   break;
				//if (nums[first]<0 && nums[third]<0)
				//    break;
				//前面已经确保nums[first]<=0 了,所以
				//只要判断nums[third]是否小于0即可
				if (nums[third] < 0)
					break;

				int sum = nums[first] + nums[second] + nums[third];
				if (sum == 0) {
					res.push_back({ nums[first],nums[second],nums[third] });
					while (second < n - 2 && nums[second] == nums[second + 1])
						++second;
					++second;
				}
				else if (sum < 0) {
					while (second + 1 < n - 1 && nums[second] == nums[second + 1])
						++second;
					++second;
				}
				else if (sum > 0) {
					while (third > 2 && nums[third] == nums[third - 1])
						--third;
					--third;
				}
			}//
			while (first + 1 < n - 2 && nums[first] == nums[first + 1])
				++first;
			++first;
			}
		}
	return res;
	}
void test01()
{
	//vector<int> nums{ 1,2,3,3,5 };
	//printvectorvector(helper(nums));
	vector<int> nums2{ -1,0,1,2,-1,-4 };
	printvectorvector(threeSum3(nums2));
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif