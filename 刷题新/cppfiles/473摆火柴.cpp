#if 0
#include "../headers/wjxHeaders.h"

bool generate(int start, vector<int>& matchsticks, int target, int bucket[])
{
	if (start >= matchsticks.size()) {
		return bucket[0] == target && bucket[1] == target
			&& bucket[2] == target && bucket[3] == target;
	}
	//分别向4个桶中尝试
	for (int j = 0; j < 4; j++) {
		if (bucket[j] + matchsticks[start] > target)
			continue;
		bucket[j] += matchsticks[start];
		if (generate(start + 1, matchsticks, target, bucket))
			return true;
		bucket[j] -= matchsticks[start];
	}
	return false;
}

bool makesquare(vector<int>& matchsticks) {
	if (matchsticks.size() < 4)
		return false;
	int sum = 0;
	sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

	if (sum % 4 != 0)
		return false;
	//按照从大到小排序
	sort(matchsticks.rbegin(), matchsticks.rend());

	int bucket[4] = { 0 };
	return generate(0, matchsticks, sum / 4, bucket);
}

//方法2 :位运算法
bool makesquare2(vector<int>& matchsticks) {
	if (matchsticks.size() < 4)
		return false;
	int sum = 0;
	sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

	if (sum % 4 != 0)
		return false;
	//到这边的逻辑和方法1 都是一模一样的

	int target = sum / 4;
	vector<int> ok_subset;//满足条件的一个边的集合
	vector<int> ok_half;//满足 条件的两个边的集合

	int all = 1 << matchsticks.size();

	for (int i = 0; i < all; ++i) {
		int sum = 0;
		for (int j = 0; j < matchsticks.size(); j++) {
			if (i & (1 << j))
				sum += matchsticks[j];
		}//sum
		if (sum == target)
			ok_subset.push_back(i);
	}

	for (int i = 0; i < ok_subset.size(); i++) {
		for (int j = i + 1; j < ok_subset.size(); j++) {
			if ((ok_subset[i] & ok_subset[j]) == 0) {//代表无交集的两个集合,也就是选择的是不同的火柴棒
				ok_half.push_back(ok_subset[i] | ok_subset[j]);//代表所有满足一半的结果
			}
		}
	}

	for (int i = 0; i < ok_half.size(); i++) {
		for (int j = i + 1; j < ok_half.size(); j++) {
			if ((ok_half[i] & ok_half[j])==0)//说明集合无交集,选择的是不同的火柴棒 
				return true;
		}
	}
	return false;

}
bool makesquare3(vector<int>& matchsticks) {
	if (matchsticks.size() < 4)
		return false;
	int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
	if (sum % 4 != 0)
		return false;

	int allset = 1 << matchsticks.size();
	int target = sum / 4;

	vector<int> subset;
	vector<int> halfset;

	for (int i = 0; i < allset; ++i) {
		int partsum = 0;
		for (int j = 0; j < matchsticks.size(); j++) {
			if (i & (1 << j)) {
				partsum += matchsticks[j];
			}
		}
		if (partsum == target)
			subset.push_back(i);
	}

	for (int i = 0; i < subset.size(); ++i) {
		for (int j = i + 1; j < subset.size(); ++j) {
			if ((subset[i] & subset[j]) == 0)
				halfset.push_back(subset[i] | subset[j]);
		}
	}

	for (int i = 0; i < halfset.size(); ++i) {
		for (int j = i + 1; j < halfset.size(); ++j) {
			if ((halfset[i] & halfset[j]) == 0)
				return true;
		}
	}
	return false;
}
void test01()
{
	vector<int> match{ 5,5,5,5,4,4,4,4,3,3,3,3 };
	cout << makesquare3(match) << endl;;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif