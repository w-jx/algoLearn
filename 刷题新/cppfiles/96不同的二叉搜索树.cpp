
#if 0
#include "../headers/wjxHeaders.h"

/*
G(n)代表n个结点能构造的二叉搜索树的数量
F(i,n)代表以i为根结点能构造的二叉搜索树的数量 

那么G(n)=F(1,n)+F(2,n)+...+F(n,n)

F(i,n)以i为根,[1,i-1]为左子树,[i+1,n]右子树
分别确定左右子树能构造出几种二叉搜索树
F(i,n)=Fleft*Fright=G(i-1)*G(n-i)

G(n) =1-n::G(i-1)*G(n-i)= G(0)*G(n-1)+G(1)*G(n-2)+...G(n-1)*G(0)

*/
//错误的
int numTrees(int n) {
    vector<int> dp(n + 1);//代表能构造的二叉搜索树的数量
    dp[0] = 0;
    dp[1] = 1;
    //i代表求第几个数字构造的二叉搜索树的数量
    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            dp[i] += dp[k - 1] * dp[n - k];
        }
    }
    return dp[n];

}
//leetcode 写的
int numTrees2(int n) {
    vector<int> dp(n + 1);
    /*
    dp[n]代表n个结点能够组成的不同二叉搜索树
    dp[n]的根结点可以从1-n
    dp[n]=f(1,n)+f(2,n)+..f(n,n);
    以i为根,则左子树1,i-1,共i-1个,能组成dp[i-1]种
    右子树i+1,n,一共n-i个,能组成dp[n-i]种

    dp[n]=dp[1-1]*dp[n-1]+dp[2-1]*dp[n-2]+...dp[n-1]*dp[n-n];
    */
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
void test01()
{
    cout << numTrees2(3) << endl;

}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif