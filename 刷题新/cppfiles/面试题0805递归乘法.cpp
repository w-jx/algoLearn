#if 0
#include "../headers/wjxHeaders.h"
/*
����ѷ ���Ե�ʱ���ʵ���û��������
����:
1.for ѭ��,Ч��̫����
2.�ݹ�ⷨ,��ΪA=0,A=1,A=2,A>2���������������

ע��ⷨ���������������ĳ˻�
*/
int helper(int A, int B) {
    switch (A)
    {
    case 0:
        return 0;
    case 1:
        return B;
    case 2:
        return B << 1;
    default:
        break;
    }
    //A>2�����,��ֳ�2��A-2����
    return (B << 1) + helper(A - 2, B);

}
int multiply(int A, int B) {
    //��֤A��С����һ��
    if (A > B)
        swap(A, B);
    return helper(A, B);
}
/*
����Ľⷨ�����ڶ�������,����и��������,�Ͳ�������
����Ľⷨ�������,����������
*/
int multiply2(int A, int B) {
    if (A == 0 || B == 0)
        return 0;
    bool flag = true;
    if (A < 0) {
        flag = !flag;
        A = ~(A - 1);//����תΪ����
    }
       
    if (B < 0) {
        flag = !flag;
        B = ~(B - 1);
    }
    if (A > B)
        swap(A, B);
    int res = helper(A, B);

    if (!flag)
        res = ~(res - 1);

    return res;
}
void test01()
{

}
int main()
{
	test01();
}
#endif