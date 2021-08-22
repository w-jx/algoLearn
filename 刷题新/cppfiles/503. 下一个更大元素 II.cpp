#if 0
#include "../headers/wjxHeaders.h"

//这个方法不行
//1.数组中存在重复元素
vector<int> nextGreaterElements(vector<int>& nums) {
	
	int n = nums.size();
	nums.insert(nums.end(), nums.begin(), nums.end());//再来一份
	vector<int> stk;//单调栈
	stk.reserve(n);
	int doublen = n * 2;

	unordered_map<int, int> num_dict;//存储下标->值的映射
	for (int i = 0; i < n; ++i) {
		num_dict[i] = nums[i];
	}
	//key->元素,val->比key大的右边元素,没有的话是-1    
	unordered_map<int, int> num_hash;
	
	for (int i = 0; i < doublen; ++i) {
		while (!stk.empty() && stk.back() < nums[i] ){
			if (num_hash.find(stk.back()) == num_hash.end())
				num_hash[stk.back()] = nums[i];
			stk.pop_back();
			
		}
			stk.push_back(nums[i]);
		

	}

	vector<int> ret(n,-1);
	for (int i = 0; i < n; ++i) {
		if (num_hash.find(nums[i]) != num_hash.end()) {
			ret[i] = num_hash[nums[i]];
		}
		else
			ret[i] = -1;
		
	}
	return ret;
}
//答案题解:单调栈
vector<int> nextGreaterElements2(vector<int>& nums) {
	//单调栈存储的是数组的下标,从栈底到栈顶下标对应的值
	//是单调不升的(越来越小,或不变)
	//我上面傻傻的在原数组后面又拼了一个原数组,实际上不需要真正的拼接
	//只需要对数组下标进行取模就可以,而且不用拼n个元素,只需要(n-1)个元素
	int n = nums.size();
	vector<int> stk;//存储的是下标,下标下标
	stk.reserve(n);
	vector<int> ret(n, -1);
	int len = 2 * n - 1;
	for (int i = 0; i < len; ++i) {
		while (!stk.empty() && nums[stk.back()]< nums[i%n]) {
			ret[stk.back()] = nums[i];
			stk.pop_back();
		}
		stk.push_back(i%n);
	}
	return ret;

}
void test01()
{
	vector<int> nums{ 100,1,11,1,120,111,123,1,-1,-100 };
	auto ret = nextGreaterElements(nums);
	printVector(ret);
}
int main()
{
	test01();
}
#endif