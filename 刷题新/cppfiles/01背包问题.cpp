#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

教程:
https://www.jianshu.com/p/a66d5ce49df5

原题链接:
https://www.acwing.com/problem/content/description/2/

*/

/// <summary>
/// 最基本的二维解法函数封装
/// </summary>
/// <param name="goods">[weight,value]</param>
/// <param name="capa"></param>
/// <returns></returns>
int getmaxval(vector<vector<int>>& goods, int capa) {
	if (goods.empty() || capa<1)
		return 0;
	
	int n = goods.size();
	//dp[i][j]代表背包容量为j的情况下,前i个商品能够装出的最大价值
	vector<vector<int> > dp(n , vector<int>(capa + 1));
	//从第一个商品遍历到最后一个商品
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= capa; ++j) {
			//背包的容量小于商品的体积,没法装当前的商品
			if (j < goods[i][0]) {
				if (i == 0) {//当前就是第一个商品,能够组成的最大价值就是0
					dp[i][j] = 0;
				}
				else {//因为装不下当前商品,所以最大价值是i-1个商品在背包容量为j的情况
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {//背包的容量大于商品的体积,可以装当前商品
				if (i == 0) {
					dp[i][j] = goods[i][1];
				}
				else {
					//不选择当前的商品,或者选择当前商品,背包总大小为j,当前商品占据了goods[i][0]
					//还剩下j - goods[i][0],在当前商品之前的i-1个商品中找到最大价值,相加
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - goods[i][0]] + goods[i][1]);
				}
			}
		}
	}//for

	return dp[n-1][capa];
}

#if 0
//getmaxval()函数测试
int main()
{
	vector<vector<int> > goods{
		{1,2},
		{2,4},
		{3,4},
		{4,5}
	};
	cout << getmaxval(goods, 5) << endl;
}
#endif 
#if false
//最基本的二维解法
int main()
{
	//n代表商品的数量,m代表最大的容积
	int n = 0, m = 0;
	cin >> n >> m;
	//dp[i][j]前i个商品,背包容量为j的最大价值
	/*
	if (j<vol[i]) 当前背包容量不够,没法选
	所以前i个物品的最优解答就是前i-1个商品的最优解
	dp[i][j] =dp[i-1][j]


	if (j>=vol[j]) 当前背包的容量够的,需要进行选择
	如果选择:dp[i][j] =dp[i-1][j-v[i]]+w[i]
	如果不选择:dp[i][j] = dp[i-1][j]
	
	*/
	vector<vector<int> > dp(n + 1, vector<int>(m + 1));
	vector<int> vol(n + 1);//存储每个商品的体积的
	vector<int> val(n + 1);//存储每个商品的价值的
	for (int i = 1; i <= n; ++i) {
		cin >> vol[i];
		cin >> val[i];
	}
	//从第一个商品遍历到最后一个商品
	for (int i = 1; i <= n; ++i) {
		//背包容量从1到m
		for (int j = 1; j <= m; ++j) {
			if (j < vol[i]) {//当前背包容量放不下这个商品
				dp[i][j] = dp[i - 1][j];//前i-1个商品在背包容量j情况下的最大价值
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i]);
			}
		}
	}
	cout << dp[n][m] << endl;	
}
#endif

#if true
//状态压缩
int main()
{
	//n代表商品的数量,m代表最大的容积
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> vol(n + 1);//存储每个商品的体积的
	vector<int> val(n + 1);//存储每个商品的价值的
	for (int i = 1; i <= n; ++i) {
		cin >> vol[i];
		cin >> val[i];
	}
	//dp[i]代表代表n件商品,背包容量为i的情况下最大价值

	vector<int> dp(n + 1);
	
	/*
	枚举背包容量必须从m开始到1
	二维情况下,dp[i][j] 代表前i个商品背包容量为j的最大价值
	dp[i][j]  可能和dp[i-1][j]有关,
	dp[i][j]和dp[i-1][j]是相互独立的

	一维情况下,如果dP[较小容量]更新dP[较小容量],可能本来应该用i-1的状态,却使用了i的状态
	距离:
	dp[7]代表 n件商品,背包容量为7的情况下最大值
	dp[4]代表 n件商品,背包容量为4的情况下最大值

	当前商品的体积为3
	dp[7]   可以从dp[4]更新而来

	dp[4]正确的含义应该是dp[i-1][4],即背包容量为4,前i-1个商品的最大价值
	当前是第i个商品



	
	*/

	
}
#endif


#endif