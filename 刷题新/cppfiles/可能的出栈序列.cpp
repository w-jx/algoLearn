#if 0
#include "../headers/wjxHeaders.h"
/*
΢��������,�澭


*/

vector<vector<int> > res;//���ܵĳ�ջ���н��
vector<int> seq;//ĳһ����ջ����
int resnum;
/*
�����е���ջ�����Ѿ�ȫ����ջ����ֻ�ܳ�ջ
��ջΪ��ʱ��ֻ�ܽ�ջ
��������ջԪ����ջ��Ϊ��ʱ��������ջ��Ҳ���Գ�ջ

��ջ -> �ݹ鴦����һ����ջԪ�� -> �ָ�δ��ջ״̬
��ջ -> ����ջԪ����ӵ���ջ���� -> �ݹ鴦��ǰ��ջԪ�� -> �ָ�ջ�ͳ�ջ������һ����״̬
*/

/// <summary>
/// 
/// </summary>
/// <param name="in">��ջ����</param>
/// <param name="i">��ǰ����ջ���еĵڼ���Ԫ��</param>
/// <param name="stk">ջ</param>
void generate(vector<int>& in, int i, stack<int>& stk)
{
	if (i > in.size())
		return;
	else if (i == in.size()) {
	//���������Ѿ�ȫ����ջ��,ֻ�ܳ�ջ��,��ջ�����Ԫ�ض���ӵ�seq�ĺ���
	//����seq
		if (!stk.empty()) {
			int topelem = stk.top();
			seq.push_back(topelem);
			stk.pop();
			//����i==�����С,�ݹ�ؽ�Ԫ�ظ��Ƶ�seq��
			generate(in, i, stk);//�ݹ�ִ��,ÿ��ջ����pop,���뵽������,ֱ��ջΪ��
			stk.push(topelem);//����
			seq.pop_back();
		}
		else {
			res.push_back(seq);//������
			++resnum;
		}
		
	}
	else {
		//����һ������Ԫ��,������ջ,���Բ���,����ջ���Ѿ��е�Ԫ��
		
		//��ջ�����
		stk.push(in[i]);
		generate(in, i + 1, stk);
		stk.pop();//����,�ָ�ջ֮ǰ��״̬

		//���ջΪ��,ֻ����ջ,����ĳ���ִ��

		//����ջԪ��,ջҲ��Ϊ��,������ջ,Ҳ���Գ�ջ
		//��ջ
		if (!stk.empty()) {
			int topelem = stk.top();
			stk.pop();
			seq.push_back(topelem);
			generate(in, i, stk);
			seq.pop_back();//����,�ָ�ջ������֮ǰ�����
			stk.push(topelem);
		}
	}
}
/// <summary>
/// 
/// </summary>
/// <param name="in">��ջ����</param>
/// <returns>���ɿ��ܵĳ�ջ���н��</returns>
int getNums(vector<int>& in)
{
	stack<int> mystack;
	generate(in, 0, mystack);
	return resnum;
}
void test01()
{
	vector<int> nums{ 1,2,3 };
	cout << getNums(nums) << endl;
	for (auto arr : res) {
		for (auto elem : arr)
			cout << elem << " ";
		cout << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif