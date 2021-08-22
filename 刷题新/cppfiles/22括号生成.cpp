#if 0
#include "../headers/wjxHeaders.h"

/*  Ϊ�˽���Ϸ����������⣬�����Ƚ�������������ŵ�����
�����������2����������2�����ŵ��������
*/
string item;
vector<string> res;
void dfs(int n)
{
	if (item.size() == 2*n) {
		res.push_back(item);
		return;
	}
	item.push_back('(');
	dfs(2);
	item.pop_back();

	item.push_back(')');
	dfs(2);
	item.pop_back();
	
	
}
//����һ�Ա���������
//�����������Ŷ�Ҫ��n��
//ֻ���ȷ������ţ��ٷ������Ųſ��ܺϷ���Ҳ����left<rightʱ�ŷ�������
void dfs2(int n,int left,int right)
{
	if (left==0 && right==0) {//����Ҫ�ĳ��������������size()==2*n
		res.push_back(item);
		return;
	}
	if (left > 0) {
		item.push_back('(');
		dfs2(2,left-1,right);
		item.pop_back();
	}
	if (left < right) {//�����ŷ��õı������Ŷ���,����Ӧ�÷���������
		item.push_back(')');
		dfs2(2,left,right-1);
		item.pop_back();
	}
}
vector<string> generateParenthesis(int n) {
	dfs(2);
	return res;
}
vector<string> generateParenthesis2(int n) {
	dfs2(n,n,n);
	return res;
	
}
//�������ţ���û�м���Ƿ�Ϸ�
void test01()
{
	auto res = generateParenthesis(2);
	for (auto iter : res)
		cout << iter << endl;

}
void test02()
{
	auto res2 = generateParenthesis2(2);
	for (auto iter : res)
		cout << iter << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#endif