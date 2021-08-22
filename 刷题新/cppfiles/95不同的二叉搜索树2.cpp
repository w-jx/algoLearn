#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
[1,n]�������

���統ǰi�������
[1..i-1]������,[i+1,n]������,���������ֱ��Ƕ���������
[start,end]����ֵ�ļ���,ö��[start,end]�е�����ֵi��Ϊ��ǰ�������ĸ�
[start,i-1][i+1,end]��ÿ��е���������
��������������ѡ��һ��,ƴ�ӵ�����,�õ�����һ��������

start>end ��������Ϊ��,���ؿս��

*/


vector<TreeNode*> helper(int start,int end) {
	if (start > end)
		return { nullptr };
	vector<TreeNode*> alltrees;//���յķ��ؽ��
	//ö������������п��и����
	for (int i = start; i <= end; ++i) {
		auto lefttrees = helper(start, i - 1);
		auto righttrees = helper(i+1,end);

		//�ֱ�������������ó�һ�����,ƴһ��
		for (auto leftroot : lefttrees) {
			for (auto rightroot : righttrees) {
				//ϸ��,���ڵ�Ҫ��ѭ���ڲ�����
				TreeNode* node = new TreeNode(i);//�����,ϸ��,�����i,����left
				node->left = leftroot;
				node->right = rightroot;
				alltrees.emplace_back(node);//���е�һ�����
			}
		}

	}
	return alltrees;
}

//leetcode ���
vector<TreeNode*> generateTrees(int n) {
	if (n < 1)
		return {};
	return helper(1, n);
	
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