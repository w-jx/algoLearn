#if 0
#include "../headers/wjxHeaders.h"
/*
���һ���������⣬ʵ���Ͼ���һ���������ı������̡���ֻ��Ҫ˼�� 3 �����⣺
1��·����Ҳ�����Ѿ�������ѡ��
2��ѡ���б�Ҳ�����㵱ǰ��������ѡ��
3������������Ҳ���ǵ���������ײ㣬�޷�����ѡ���������

result = []
def backtrack(·��, ѡ���б�):
	if �����������:
		result.add(·��)
		return

	for ѡ�� in ѡ���б�:
		��ѡ��
		backtrack(·��, ѡ���б�)
		����ѡ��

*/
//x���±�
void dfs(string s, int x,vector<string > &res)
{
	if (x == s.size() - 1) {
		res.push_back(s);//���������
		return;
	}
	set<int> st;
	for (int i = x; i < s.size(); i++) {
		if (st.count(s[i]) > 0) continue;//�ظ��ˣ���˼�֦
		st.insert(s[i]);

		swap(s[i], s[x]);//��������s[i] �̶��ڵ�x λ��
		dfs(s, x + 1,res); //����ľ��� for ѭ������ĵݹ飬�ڵݹ����֮ǰ����ѡ�񡹣��ڵݹ����֮�󡸳���ѡ��
		swap(s[i], s[x]);//�ָ�����
	}
}
vector<string> permutation(string s) {
	
	vector<string > res;
	dfs(s, 0,res);

	return res;
}



void test01()
{
	string str = "abc";
	auto res = permutation(str);
	for (auto iter : res) {
		cout << iter << " ";
	}
	cout << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif