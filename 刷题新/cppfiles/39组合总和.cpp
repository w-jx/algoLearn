#if 0
#include "../headers/wjxHeaders.h"

//可以使用重复的数,但是结果不能重复
vector<vector<int>>res;
vector<int> item;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	backtrace(candidates, 0, target);
    return res;
}
//idx代表当前在candidates数组的第idx位,还剩下target要凑,已经凑好的存放在item中
void backtrace(vector<int>& candidates, int idx, int target) {
	if (idx == candidates.size())
		return;
	//待凑的是0,item的和就是最开始的目标target
	if (target == 0) {
		res.push_back(item);
		return;
	}
	//上面是递归终止条件:待凑的元素<=0,或者,数组里面的元素已经被用完了

	//跳过candidates[idx],用下一个数
	backtrace(candidates, idx + 1, target);
	//不跳过candidates[idx],还不够
	if (target - candidates[idx] >= 0) {
		item.emplace_back(candidates[idx]);//使用当前candidates[idx]
		//因为可以重复,所以还是从idx开始,待凑的减去candidates[idx]
		backtrace(candidates, idx, target-candidates[idx]);//注意细节,还是从idx开始
		item.pop_back();
	}
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}


#endif