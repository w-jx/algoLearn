#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

̰���㷨

1.���к��ӵ� �ǹ��� ��ʼ��Ϊ1
2.�������ұ���
	����ұߺ��ӵ����ֱ���ߵĸߣ��ұߺ��ӵ��ǹ�������Ϊ��ߺ��ӵ��ǹ���+1
3.�� �����������
	�����ߺ��ӵ����ֱ��ұߵĸߣ�����ߺ��ӵ�ǰ���ǹ��� ������ �ұߺ��ӵ��ǹ���
	�����ǹ�������Ϊ�ұߺ��ӵ��ǹ���+1

	��������Ϊ[1,0,2]  ���Ϊ5
һ��ʼ��Ҫ���ǹ�Ϊ��1��1��1��,��һ�α���[1,1,2],�ڶ��α���[2,1,2],һ��Ҫ5����

*/
int candy(vector<int>& ratings) {
	int size = ratings.size();
	if (size < 2)
		return size;//ֻ��һ�����ӻ���û�к���

	vector<int> candys(size, 1);//��ʼ��ʱ��ÿ�����ӷ�һ����
	for (int i = 1; i < size; ++i) {
		if (ratings[i] > ratings[i - 1]) {//�ұߺ��ӵ����ֱ���߸�
			candys[i] = candys[i - 1] + 1;
		}
	}
	for (int i = size - 1; i > 0; --i) {
		if (ratings[i] <ratings[i-1]) {//ratings[i-1]�����
			//��ߺ��ӵ����� ���ұߺ������ָ�
			//��ߺ��ӵ��ǹ� ������ �ұߺ��ӵ��ǹ�����
			candys[i - 1] = max(candys[i - 1], candys[i] + 1);
		}
	}
	int num = accumulate(candys.begin(), candys.end(), 0);


	return num;
	
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