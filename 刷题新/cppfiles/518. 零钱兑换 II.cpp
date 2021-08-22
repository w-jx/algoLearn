#if 0
#include "../headers/wjxHeaders.h"

/*
背包问题:
这道题结合爬楼梯-- - 70来写
爬楼梯:每次走1步或者2步,最终判断走n台阶的方法
本题:每次可以走coins中的方法,最终判断走amount的方法数


区分排列数和组合数
爬楼梯计算的是排列数
本题计算的是组合数
子问题:
前k个硬币凑成金额i的组合数=
    前k-1个硬币凑成金额i的组合数+前k个硬币凑成i-k的组合数
直白点:要从k个硬币里面凑金额i的组合数
一种是已经在k-1个硬币中凑成的组合数
一种前面已经凑成i-k了,就差k了就能凑成i了

状态数组dp[k][i]前k个硬币凑成金额i的组合数
组合问题,我们不关心硬币使用的顺序,关心硬币有没有被用到
是否使用第k个硬币受之前情况的影响
状态转移方程
 如果金额数大于硬币
    dp[k][i]=dp[k-1][i]+dp[k][i-k];
 否则:
    dp[k][i] = dp[k-1][i]

problem(k,i) = problem(k-1, i) + problem(k, i-k)
*/


//2021年7月5日不会写,官方题解,通过
int change(int amount, vector<int>& coins) {
    //dp[i]代表金额i的组合数
	vector<int> dp(amount + 1);
    dp[0] = 1;//金额0,不用硬币,只有一种组合
	//外层遍历coin
	for (const int& coin : coins) {
		for (int i = coin; i <= amount; ++i)
			dp[i] += dp[i - coin];
	}
	return dp[amount];
}
//体会下这种方法为什么不能通过
/*
amount =3
coins = {1,2}

i=1,coin=1
dp[1] +=dp[1-coin]=1
i=1,coin=2,排除

i=2,coin=1
dp[2]+=dp[i-coin]
也就是dp[2]+=dp[1] =1 ,目前是1,1

i=2,coin=2
dp[2]+=dp[2-coin]
也就是dp[2]+=dp[0]=2,{1,1},{2}

i=3,coin=1
dp[3]+=dp[i-coin]
也就是dp[3]+=dp[2],dp[3]=2 ,{1,1,1},{2,1}

i=3,coin=2
dp[3]+=dp[i-coin]
也就是dp[3]+=dp[1],dp[3]=3,{1,2}可以发现重复的出现

为什么官方题解不会出现重复:
dp[2]用了1,2
dp[1]用了1
求dp[3]的时候,用到了dp[2],用了硬币1,2
又用到了dp[1],用了硬币2,1

官方题解思路是如下的,coin是固定的,每次遍历一种coin 
coin=1,i=1
dp[1]+=dp[i-coin]=1,{1}
coin=1,i=2
dp[2]+=dp[i-coin]
也就是dp[2]+=dp[1]=1,{1,1}
dp[3]+=dp[i-coin]
也就是dp[3]+=dp[2]=1,{1,1,1}
可以发现首先把一种硬币能组成的所有金额给计算出来

coin=2,i=2
dp[2]+=dp[i-coin]
也就是dp[2]+=dp[0]=2,原来{1,1},现在多了个{2}

coin=2,i=3
dp[3]+=dp[i-coin]
也就是dp[3]+=dp[1],原来{1,1,1},多了个{1,2}
所以不会重复  

*/
int change2(int amount, vector<int>& coins) {
    int n = coins.size();
    //dp[i]代表到i金额的方法数量,dp[amount]
    vector<int> dp(amount + 1);
    dp[0] = 1;

    for (int i = 1; i <= amount; ++i) {//枚举金额
        for (const int& coin : coins) {
            //枚举 金币
            if (i < coin) continue;
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}
/*
区分排列数和组合数
爬楼梯计算的是排列数
problem(k,i) = problem(k-1, i) + problem(k, i-k)
本题计算的是组合数
子问题:
前k个硬币凑成金额i的组合数=
    前k-1个硬币凑成金额i的组合数+前k个硬币凑成i-k的组合数
直白点:要从k个硬币里面凑金额i的组合数
一种是已经在k-1个硬币中凑成的组合数
一种前面已经凑成i-k了,就差k了就能凑成i了

状态数组dp[k][i]前k个硬币凑成金额i的组合数
组合问题,我们不关心硬币使用的顺序,关心硬币有没有被用到
是否使用第k个硬币受之前情况的影响
状态转移方程
 如果金额数大于硬币
    dp[k][i]=dp[k-1][i]+dp[k][i-k];
 否则:
    dp[k][i] = dp[k-1][i]






*/
int change3(int amount, vector<int>& coins) {
    int n = coins.size();
    //dp[m][n]代表前m个硬币,凑n金额的组合数
    vector<vector<int> > dp(n+1, vector<int>(amount + 1));
    //初始化基本状态
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;//前n个金币凑金额0,有且仅有1种组合
    }
    //遍历硬币
    for (int i = 1; i <= n; ++i) {
        //枚举金额
        for (int j = 1; j <= amount; ++j) {
            if (j >= coins[i - 1])//当前金额大于硬币数额
                //在前i个金币凑成了j-coins[i-1],加上coins[i-1]就是j
                //在前i-1个金币已经凑成j,两种组合数相加
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else//前i-1个金币凑成金额j的方法数,第i个金币不符合要求,所以当前的方法数
                //和之前i-1个金币的方法数是相同的
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount];
}
/*
降维:
我们观察下dp[i][*]只和dp[i-1][*]和dp[i][#]有关
  dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
  dp[i][j] = dp[i - 1][j];


  dp[i]代表我们必须使用第k个金币的时候,能凑成当前金额i的组合数
下`
  dp[i]=dp[i]+dp[i-k]

*/
void test01()
{

}
int main()
{
	test01();
}
#endif