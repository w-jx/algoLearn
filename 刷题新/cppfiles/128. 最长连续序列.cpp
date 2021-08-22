#if 0
#include "../headers/wjxHeaders.h"


//通过,预先排序,再利用哈希表,o(nlogn)
int longestConsecutive1(vector<int>& nums) {
	if (nums.empty())
		return 0;
	sort(nums.begin(), nums.end());
	//key->nums[i],value当前的长度
	unordered_map<int, int> hashmap;

	hashmap[nums[0]] = 1;
	int n = nums.size();
	int maxlen = 1;
	for (int i = 1; i < n; ++i) {
		if (hashmap.find(nums[i] - 1) != hashmap.end()) {
			hashmap[nums[i]] = hashmap[nums[i] - 1] + 1;
			maxlen = std::max(hashmap[nums[i]], maxlen);
		}
		else
			hashmap[nums[i]] = 1;
	}
	return maxlen;
}
//通过.不用预先排序,但是时间复杂度也很高
int longestConsecutive2(vector<int>& nums) {
	if (nums.empty())
		return 0;

	//key->nums[i],value当前的长度
	unordered_set<int> num_set;
	for (const auto& num : nums)
		num_set.insert(num);
	int n = nums.size();
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (num_set.find(nums[i] - 1) != num_set.end())
			continue;
		int base = nums[i]+1;
		int curlen = 1;
		while (num_set.find(base) != num_set.end()) {
			++base;
			++curlen;
		}
		cur = std::max(cur, curlen);

	}
	return cur;
}

void test01()
{
	vector<int> nums{100,4,200,1,3,2};
	cout << longestConsecutive1(nums) << endl;
}
int main()
{
	test01();
}
#endif