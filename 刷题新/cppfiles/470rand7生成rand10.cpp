#if 0
#include "../headers/wjxHeaders.h"
/*
����:
���a>b ,һ��������randaʵ��randb
����rand7ȥʵ��rand5
int Rand5(){
    //int x = ~(1<<31); // max int
    int x = 7;//��5���
    while(x > 5)
        x = Rand7();
    return x;
}
һ����ʽ
int Randb() {
    int x = ~(1 << 31); // max int
    while (x > b)
        x = Randa();
    return x;
}
//����a<b,������Ҫ��randaȥʵ��randb
����rand5ʵ��rand 7,ֻҪʵ�ָ����ӳ�伴��
rand5+rand5-1���Գ���1-9����,���Ǹ��ʲ���
��Ϊ����1ֻ�ܴ�1,1����,����2���Դ�1,2 ����2,1����,���Ը��ʲ���
Ҫ����ø�����ͬ������
�������:
(rand5-1)*5+rand5 ����
rand5 ���Եȸ��ʳ���1,2,3,4,5
rand5-1���Եȸ��ʳ���0,1,2,3,4
�ٳ���5���Եȸ��ʳ���0,5,10,15,20
�ټ���rand5���Եȸ��ʳ���1-25��ĳ����
�������൱�����ǵõ���rand25,��ȥʵ��rand7���ù�ʽ����

�����ı׶���:rand25()���ɺܶ�1-25,�����кܶ಻����Ҫ���,��Ҫ����rand25�ķ�Χ
�����ҵ����
����Ӧ��Ҫ����������������
��x����ӽ�25����С��25,ͬʱ��7�ı������
x��ȡֵ�ͱ����1-21
int Rand7(){
    int x = ~(1<<31); // max int
    while(x > 21)
        x = 5 * (Rand5() - 1) + Rand5() // Rand25
    return x%7 + 1;


https://blog.csdn.net/u010025211/article/details/49668017
}

*/


int rand10() {

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