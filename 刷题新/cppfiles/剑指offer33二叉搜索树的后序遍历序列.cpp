#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

���ں���������У����Ƕ���������������֪��
���������ȸ�С�����������ȸ���
*/
bool generate(vector<int>& post, int left, int right) {
	if (left >= right)
		return true;
	int rootval = post[right];
	int ptr = left;
	while (post[ptr] < rootval)
		++ptr;//���ܼӵ�һ���ȸ��ڵ���λ��,����ֱ�Ӽӵ����ڵ��λ��
	int leftend = ptr - 1;
	while (post[ptr] > rootval)
		++ptr;//����������λ�õ�����Ԫ�ض�Ӧ�ô��ڸ��ڵ�,ֱ�����ڵ�λ��

	//ptr==right��������߶��ȸ�����
	return ptr == right && generate(post, left, leftend) && generate(post, leftend + 1, right-1);

}
bool verifyPostorder(vector<int>& postorder) {
	int n = postorder.size();
	return generate(postorder, 0, n-1);
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