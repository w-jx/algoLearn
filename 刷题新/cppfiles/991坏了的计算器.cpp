#if 0
#include "../headers/wjxHeaders.h"
//����˼ά����
int brokenCalc(int x, int y) {
    if (x >= y)
        return x - y;
    int times = 0;
    //x<y  xֻ�ܳ���2,���߼�1,��ôyֻ�ܳ���2,����+1
    //��2 y�½��Ŀ�,̰��̰����̰�ĵĴ���
    /*
    ����y=64,ż��
    (64+1+1)/2 = 33
    64/2+1=33,ͬ���ǵõ�33,���Ƿ���
    �ȼ�2�ٳ���2ʹ����3������,���ȳ���2�ټ�1ֻʹ����1������

    ����y=31,����
    (31+1)/2 +1= 17
    (31+1+1+1)/2=17
    ͬ���õ�17,����������2��,����������4��
    ������y>x�������
    y��ż��,�ȳ���2�ټ���1
    y������,�ȼ�1�ٳ���2,

    */
    while (x < y) {
        if (y % 2 == 0) {
            y /= 2;
        }
        else {
            y += 1;
        }
        ++times;
    }
    return times + x - y;
   

  
    



 
}
void test01()
{
    cout << brokenCalc(3, 10) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif