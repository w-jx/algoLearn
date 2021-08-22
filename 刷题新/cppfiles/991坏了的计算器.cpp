#if 0
#include "../headers/wjxHeaders.h"
//逆向思维更好
int brokenCalc(int x, int y) {
    if (x >= y)
        return x - y;
    int times = 0;
    //x<y  x只能乘以2,或者减1,那么y只能除以2,或者+1
    //除2 y下降的快,贪心贪的是贪心的次数
    /*
    例如y=64,偶数
    (64+1+1)/2 = 33
    64/2+1=33,同样是得到33,我们发现
    先加2再除以2使用了3次运算,而先除以2再加1只使用了1次运算

    例如y=31,奇数
    (31+1)/2 +1= 17
    (31+1+1+1)/2=17
    同样得到17,上面运算了2次,下面运算了4次
    所以在y>x的情况下
    y是偶数,先除以2再加上1
    y是奇数,先加1再除以2,

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