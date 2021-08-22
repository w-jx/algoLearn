#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ���������� nums �������е�Ԫ�� ������ͬ �����ظ��������п��ܵ��Ӽ����ݼ�����

�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯��

nums = [1,2,3]
�Ӽ���
[ [],[1],[2],[3],[1,3],[2,3],[1,2],[1,2,3] ] һ����8��

��[1,2]���Ӽ�
[ [],[1],[2],[1,2] ]

������������
subset([1,2,3]) - subset([1,2])= [3],[1,3],[2,3],[1,2,3]��������subset([1,2])ÿ�����ϼ�3

���A=subset([1,2]),��ôsubset([1,2,3])=A�е�ÿ��Ԫ�ؼ�3

����2�������㷨

*/
//����1 �ǵݹ鷽������ѧ���ɷ�
vector<vector<int>> subsets(vector<int>& nums) {
	if (nums.empty()) return { {} };
	int n = nums.back();//ȡ�����һ��Ԫ��
	nums.pop_back();//ȡ�����һ��Ԫ��

	auto res = subsets(nums);//�����ǰ��Ԫ�ص��Ӽ�
	int len = res.size();//��Ϊ1��2��3���Ӽ���1��2���Ӽ�
	for (int i = 0; i < len; i++) {
		res.push_back(res[i]);
		res.back().push_back(n);
		/*
		ԭ����					�Ӽ�
		�գ�					[[]]
		1					1.��ԭ�����ټӵ�res����  [ [],[]]
							2.β��Ԫ�ؼ���ǰһ�������Ԫ�ظ�����0��ʱ�����Ϊ1��ֻ��һ���ռ���
								���Ա�� [[],[1]]
		2.					1.�Ȱ�ԭ���ļӵ�res���棬���μ� [[],[1],[]],Ȼ�������ǰ
							һ�������Ԫ�ظ�����1��ʱ�����Ϊ2�� [[],[1],[2]]
							2.�������  [[],[1],[2],[1]] ,��β�����һ��2Ҳ�������ս��Ϊ
							[[],[1],[2],[1,2] ]
		*/
	}
	return res;
}
vector<vector<int>> res;
void dfs(vector<int>& nums, int start, vector<int>& track)
{
	res.push_back(track);
	for (int i = start; i < nums.size(); i++) {
		//��ѡ��
		track.push_back(nums[i]);
		//����
		dfs(nums, i + 1, track);//ǧ���ס��i+1������ start+1
		track.pop_back();//����ѡ��
	}
}


vector<vector<int>> subsets2(vector<int>& nums)
{
	vector<int> track;//��¼�߹���·��
	dfs(nums, 0, track);
	return res;

}
// ����3 λ����
vector<vector<int>> subsets3(vector<int>& nums)
{
	int all_set = 1<< nums.size();//���� ȫ�����ϵ����ֵ+1��

	for (int i = 0; i < all_set; ++i) {
		std::vector<int> item;
		for (int j = 0; j < nums.size(); ++j) {
			if (i & (1 << j)) //001->c  010->b 100->a 
				item.push_back(nums[j]);
			/*
			��������I ����ļ��ϣ���Ԫ�ش洢��item��
			����i�����0��2^n-1 һ��2^n������
			1<<j ���� nums����ĵ�j��Ԫ�أ���i & (1 << j)�Ͱ�nums[j]�Ž�ȥ
			���� A=100 4 B=010 2 C=001 1 
			*/
		}
		res.push_back(item);
	}
	return res;

}
void test01()
{
	int a = 1 << 3;
	cout << a << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif