#if 0
#include "../headers/wjxHeaders.h"

//�ȳ������һ���������е�����Ԫ�ص����
//Ϊ�˱����ظ�,��ȡ�Ӽ�2�ķ�ʽ����
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
//���波�Խ������
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	dfs2(0, nums, 0);
	return res;
}
//���ۣ����û����޷��������
//leetcode�����
vector<vector<int>> threeSum2(vector<int>& nums) {
	if (nums.size() < 3)
		return {};
	sort(nums.begin(), nums.end());
	int n = nums.size();
	int i = 0;//��һ�����±��ʼ��Ϊ0
	//�����,��һ����С�ڵ���0,���һ�������ڵ���0,�ſ���������֮�͵���0
	if (nums[0] <= 0 && nums.back() >= 0) {
		while (i < n - 2) {//Ҫ��������,i<n-2���ܱ�֤��������
			if (nums[i] > 0)//������һ��������0,�϶��޷��ճ�
				break;//������Ѿ�����0��,���������֮�Ϳ϶�����0
			int first = i + 1;//�ڶ����ǵ�һ��������һ��
			int last = n - 1;//�������������һ����ʼ
			while (first < last) {
				//if (nums[i] * nums[last] > 0)
				//	break;//����������ͬ���ķ���//���Խ����
				if ((nums[i] > 0 && nums[last] > 0) || (nums[i] < 0 && nums[last] < 0))
					break;//����������ͬ���ķ���,�Ϳ϶�����0
				int sum = nums[i] + nums[first] + nums[last];
				if (sum == 0) {
					res.push_back({ nums[i],nums[first],nums[last] });
				}
				//һ����С�ڵ���,ǧ��ע����߲���else if ,����if
				if (sum <= 0) {
					while (first < n - 2 && nums[first] == nums[first + 1])
						++first;
					++first;//ȥ���ظ�ֵ,�������ƶ�һ��λ��
				}
				else if (sum > 0) {
					while (last > 2 && nums[last] == nums[last - 1])
						--last;
					--last;//ȥ���ظ�ֵ
				}
			}//while first<last;
			//iǰ��
			while (i + 1 < n - 2 && nums[i] == nums[i + 1])
				++i;//ȥ���ظ�ֵ,ǰ��
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
					//firstǰ��
					while (first + 1 < n - 1 && nums[first] == nums[first + 1])
						++first;
					++first;
				}
				else if (sum > 0) {
					//last ����
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
//2021��5��28��,��ϰ,�����ı�׼��
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
				//ǰ���Ѿ�ȷ��nums[first]<=0 ��,����
				//ֻҪ�ж�nums[third]�Ƿ�С��0����
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