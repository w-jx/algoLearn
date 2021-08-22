#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���
���� [1,2,2]
���:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/
vector<vector<int> > res;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<int> temp;//��¼�߹���·
	sort(nums.begin(), nums.end());
	
	dfs(nums, temp, 0);

	return res;
}
void dfs(vector<int>& nums, vector<int>& temp, int start) {

	res.push_back(temp);
	for (int i = start; i < nums.size(); i++) {
		if (i > start && nums[i] == nums[i - 1])
			continue;
		temp.push_back(nums[i]);

		dfs(nums, temp, i + 1);
		temp.pop_back();
		

	}
}
int main()
{
	system("pause");
	return 0;
}
#endif