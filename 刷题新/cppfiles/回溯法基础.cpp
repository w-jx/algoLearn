#if 0
#include "../headers/wjxHeaders.h"
/*
���ǻ��ݷ��� Ԥ��֪ʶ
����һ������1 2 3 ������� 1��1 2 ��1 2 3

*/
//��ѭ���ķ���ȥ��
void getRes(vector<int>& nums)
{
	vector<int> item;
	vector<vector<int> > res;
	for (auto iter : nums) {
		item.push_back(iter);
		res.push_back(item);
	}
	for (auto iter : res) {
		for (auto it : iter)
			cout << it << " ";
		cout << "\n-------------\n";
	}
}
vector<int> item2;
vector<vector<int>> res2;
void dfs(vector<int>& nums,int start)
{
	if (start >= nums.size())
		return;
	item2.push_back(nums[start]);
	res2.push_back(item2);
	dfs(nums, start + 1);
}
//�û��ݵķ���ȥ��
void getRes2(vector<int>& nums)
{
	dfs(nums, 0);
	for (auto iter : res2) {
		for (auto it : iter)
			cout << it << " ";
		cout << "\n-------------\n";
	}
}
void test01()
{
	vector<int> v{ 1,2,3 };
	//getRes(v);

	getRes2(v);//���ݷ�
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif