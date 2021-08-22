#if 0
#include "../headers/wjxHeaders.h"
/*
* 
首先要明确:在f层和比f层低的层落下,鸡蛋不会破
测试用例:k=1,n=2
-----------2

-----------1

------------0

测试的楼层必须大于1
从1测试,如果破了,说明f=0
如果没破,进一步从2测试,如果破了,代表f=1
如果没破f=2
所以需要2次

测试用例:k=2,n=6 结果是3
----------------6
----------------5
----------------4
----------------3
----------------2
----------------1
----------------0
先用第一个鸡蛋测试,第一次测试
----------------6
----------------5
----------------4
----------------3   o1
----------------2
----------------1
----------------0

	如果破了,说明f<3,f只能是2,1,0 下面用第二鸡蛋测试
		----------------2
		----------------1  o2 
		----------------0

		如果破了,说明f<1,只能f=0,如果没破,说明f>1,那么f只能是2,一共用了2次操作

	如果没有破,说明f>3,f只能是4,5,6,下面进行第二次操作
		----------------6
		----------------5 o1
		----------------4

		如果破了,说明f>5,f只能是6
		如果没破,f<5,f只能是4,



*/

/*
答案题解方法1:动态规划+二分

(k,n),k为鸡蛋数量,n为楼层数,从第x楼扔鸡蛋,两种情况
1.如果鸡蛋不碎,鸡蛋数量还是k,楼层数只能是上方的n-x层楼了
原问题变成了(k,n-x)子问题
2.如果鸡蛋碎了,鸡蛋数量变成k-1,楼层只能是第x楼的x-1层楼中了
原问题(k-1,x-1)

定义dp[k][n]为状态(k,n)最小需要的步数
dp[k][n] = 1+std::min(max(dp[k-1][x-1]),dp[k][n-x]),其中1<=x<=n

遍历x从1到n,求解当前的x值对应的
	dp[k-1][x-1]和dp[k][n-x]
我们并不知道真正的f值,必须保证
鸡蛋碎了之后接下来需要的步数     和
鸡蛋没碎知乎接下来需要的步数
	两者中的   最大值   最小
这样保证在最坏情况下(也就是无论f的值如何)
dp[k][n]的值最小



写的很乱,看不懂

*/



/*
* 别人的题解
* 问题解析:
	如果有7层楼,如果去找鸡蛋恰好摔碎的那层楼
	最原始的方法:
	先从1楼扔下,没有碎
	再从2楼扔下,没有碎
	再去3楼扔下,没有碎
	...
	最坏情况到7层也没有碎(F=7),也就是需要扔7次,

	什么叫"至少",同样不考虑鸡蛋个数限制,同样是7层,用二分的思想
	先去(1+7)/2 =4扔下
		如果碎了,说明F<4,就去(1+3)/2 = 2尝试
		如果没有碎,说明F>=4,去(5+7)/2 = 6层尝试
	这种策略,最坏情况是第7层没有碎(F=7),或者直接碎到第一层(F=0)
	不论哪种,log7向上取整=3,比线性方法尝试7次少

	如果不限制鸡蛋个数的话,二分思路可以得到最少的次数
	现在给了鸡蛋个数限制k,直接使用二分思想是不行的

	例如:1个鸡蛋,7层楼,用二分的思想
	在4层测试,碎了,没有鸡蛋继续测试了,无法确定
	这种情况只能用线性扫描的方法,从最底层往高层测试

	也不能先用二分查找,在鸡蛋只剩下1个的时候,进行线性扫描
	反例:2个鸡蛋,100层
	先在50层扔下,碎了,只能线性扫描49次,最坏情况要扔50次

	进行10分法,能够减少最坏情况下的次数
	第一个鸡蛋每隔10层扔,在哪儿碎了,第二个鸡蛋进行线性扫描
	最坏情况:到90层没有碎,到100层碎了,从91到99进行线性扫描9次,一共19次
	但是实际上:
	最优解是14次,最优策略很多,而且没有规律可言
*思路分析:
	状态:当前拥有的鸡蛋数量和需要测试的楼层数
	随着测试进行,鸡蛋个数减少,楼层搜索范围(个数)减少,这就是状态的变化
	选择:在哪层楼扔鸡蛋,线性扫描选择一层一层向上测试,二分选择楼层中间测试
	不同的选择会造成状态的转移

	动态规划:二维dp,或者带有两个状态参数的dp参数表示状态转移,for循环遍历所有选择,选择最优的状态
int dp(int k,int n) {
	int res;
	for (int i=1;i<=n;++i)
		res = min(在第i层楼扔鸡蛋)
	return res;
}
选择在第i层扔鸡蛋:可能鸡蛋碎了,也可能鸡蛋没有碎
1.鸡蛋碎了,鸡蛋的个数k减1,搜索楼层区间从[1,n]变成[1,i-1],一共i-1层楼
2.鸡蛋没有碎,鸡蛋的个数k不变,搜索楼层区间[1,n]变成[i+1,n],共n-i层楼
****ps:在第i层鸡蛋没有碎,搜索区间缩减,是否应该包含i,答案是不需要
* 因为F是可以等于0的?区间缩减成[i+1,n],第i层就相当于第0层,可以被取到
* 
int dp(int k,int n) {
	for (int i=1;i<=n;++i) {
		res = min(
				res,
				max(
					dp(k-1,i-1) ,//碎了
					dp(k,n-i)
				}+1
		)
	}
	return res;
}
边界条件:
int dp(int k,int n) {
	if (n==0)//楼层数n=0,不需要仍鸡蛋
		return 0;
	if (k==1)//鸡蛋数为1,只能线性扫描
		return n;
}
添加"备忘录"消除重叠子问题,用数组来存,最终编码
vector<vector<int> > memo(k,vector<int>(n));
int dp(int k,int n) {
	if (n==0)//楼层数n=0,不需要仍鸡蛋
		return 0;
	if (k==1)//鸡蛋数为1,只能线性扫描
		return n;
	int res = INT_MAX;
	for(int i=1;i<=n;++i) {
		res = std::min(res,std::max(dp(k,n-i),dp(k-1,i-1))+1);
	}
	memo[k][n]=res;
	return res;
}
暴力解法是超时的
二分的解法并非上面的二分扔鸡蛋的思路,仅仅是因为状态转移方程的图像具有单调性,可以快速找到最值
res = std::min(res, std::max(dp(k, n - i), dp(k - 1, i - 1)) + 1);
dp(k,n)一定是关于k的递增函数,k固定的情况,楼层数n越多,需要的步数一定不会变少

F2 = dp(k,n-i),随着i增加(n-i减少)而单调递减的函数
F1 = dp(k-1,i-1)是一个随着i增加而单调递增的函数

当i增加的时候,F1单调递增,F2单调递减
可以想象在直接坐标系中,横坐标为i,纵坐标为F2(i)和F1(i)
如何找到一个位置,使得它们的最大值是最小的呢?

如果这两个函数都是连续的,只要找到它们的交点,就交点处可以保证两者中的最大值
最小的
但是题目中的函数是离散函数,i只能取1,2,3这样的整数

我们找到最大的T1(i)<T2(i)的i0
最小的T1(i)>=T2(i)的i1

只需要比较i0,i1这两个地方函数的最大值,取一个最小的作为i即可


*/
//暴力解法,能通过64/121个测试用例,会超时
unordered_map<int, int> memo;//这个用来存储,防止重复计算
int dp(int k, int n) {
	if (n == 0)//楼层数n=0,不需要仍鸡蛋
		return 0;
	if (k == 1)//鸡蛋数为1,只能线性扫描
		return n;
	if (memo.find(n * 100 + k) != memo.end())
		return memo[n * 100 + k];
	int res = INT_MAX;
	for (int i = 1; i <= n; ++i) {
		res = std::min(res, std::max(dp(k, n - i), dp(k - 1, i - 1)) + 1);
	}
	memo[n*100+k] = res;
	return res;
}
//二分查找的解法
int dp2(int k, int n) {
	if (n == 0)//楼层数n=0,不需要仍鸡蛋
		return 0;
	if (k == 1)//鸡蛋数为1,只能线性扫描
		return n;
	if (memo.find(n * 100 + k) != memo.end())
		return memo[n * 100 + k];
	int res = INT_MAX;
	//下面进行二分查找
	int left = 1, right = n,mid= 0 ; 
	while (left < right) {
		mid = left + (right - left) / 2;
		int broken = dp(k - 1, mid - 1);//碎了  单调递增的
		int unbroken = dp(k, n - mid);//没有碎   单调递减的
		//要结合两个函数的图像来看
		if (broken > unbroken) {
			right = mid - 1;//往左边逼近交点
			res = std::min(res, broken + 1);
		}
		else {//broken<=unbroken
			left = mid + 1;//往右边逼近交点
			res = std::min(res, unbroken + 1);
		}

	}
	memo[n * 100 + k] = res;
	return res;
}
int superEggDrop(int const k, int const n) {
	
	return	dp(k, n);

}

//leetcode 重新提交的版本
int dp3(int k, int n) {
	if (k == 1)//1个鸡蛋的情况,只能线性扫描
		return n;
	if (n == 0)//待扫描楼层数为0,无需扫描
		return 0;
	if (memo.find(n * 100 + k) != memo.end())
		return memo[n * 100 + k];
	long res = INT_MAX;
	int left = 1, right = n, mid = 0;
	long broken = 0, unbroken = 0;
	while (left <= right) {
		mid = left + (right - left) / 2;
		broken = dp(k - 1, mid - 1);
		unbroken = dp(k, n - mid);
		if (broken > unbroken) {
			right = mid - 1;
			res = std::min(res, broken + 1);
		}
		else {
			left = mid + 1;
			res = std::min(res, unbroken + 1);
		}
	}
	//这个散列函数的设计很巧妙
	memo[n * 100 + k] = res;
	return res;
}
int superEggDrop3(int k, int n) {
	return dp(k, n);
}
//github解法  https://github.com/Shellbye/Shellbye.github.io/issues/42
int superEggDrop2(int const k, int const n) {
	vector<int> dp(k + 1);
	int m = 0;
	for (; dp[k] < n; ++m) {
		for (int i = k; i > 0; --i) {
			dp[i] += dp[i - 1] + 1;
		}
	}
	return m;
}
void test01()
{

}
int main()
{
	test01();
}
#endif