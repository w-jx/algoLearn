#if 0
#include "../headers/wjxHeaders.h"
/*
亚马逊 面试的时候被问到了没有做出来
方法:
1.for 循环,效率太低了
2.递归解法,分为A=0,A=1,A=2,A>2四种情况进行讨论

注意解法都适用两个正数的乘积
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
    //A>2的情况,拆分成2和A-2两种
    return (B << 1) + helper(A - 2, B);

}
int multiply(int A, int B) {
    //保证A是小的那一个
    if (A > B)
        swap(A, B);
    return helper(A, B);
}
/*
上面的解法适用于都是正数,如果有负数的情况,就不适用了
下面的解法针对正数,负数都可以
*/
int multiply2(int A, int B) {
    if (A == 0 || B == 0)
        return 0;
    bool flag = true;
    if (A < 0) {
        flag = !flag;
        A = ~(A - 1);//正数转为负数
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