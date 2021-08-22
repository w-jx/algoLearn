#if 0
#include "../headers/wjxHeaders.h"
/*
结论:
如果a>b ,一定可以用randa实现randb
例如rand7去实现rand5
int Rand5(){
    //int x = ~(1<<31); // max int
    int x = 7;//比5大的
    while(x > 5)
        x = Rand7();
    return x;
}
一般表达式
int Randb() {
    int x = ~(1 << 31); // max int
    while (x > b)
        x = Randa();
    return x;
}
//现在a<b,我们想要用randa去实现randb
例如rand5实现rand 7,只要实现更大的映射即可
rand5+rand5-1可以出现1-9数字,但是概率不等
因为数字1只能从1,1出现,数字2可以从1,2 或者2,1出现,所以概率不等
要解决让概率相同的问题
解决方法:
(rand5-1)*5+rand5 即可
rand5 可以等概率出现1,2,3,4,5
rand5-1可以等概率出现0,1,2,3,4
再乘以5可以等概率出现0,5,10,15,20
再加上rand5可以等概率出现1-25的某个数
这样就相当于我们得到了rand25,再去实现rand7套用公式即可

这样的弊端是:rand25()生成很多1-25,可能有很多不符合要求的,想要降低rand25的范围
快速找到结果
我们应该要让舍弃的数尽量少
让x与最接近25但是小于25,同时是7的倍数相比
x的取值就变成了1-21
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