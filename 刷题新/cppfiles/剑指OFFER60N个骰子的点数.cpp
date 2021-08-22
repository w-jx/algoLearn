#if 0
#include "../headers/wjxHeaders.h"




/*
我的思路:准备6*n个桶,或者直接用哈希表
,记录每个和出现的次数

*/
void dfs(int sum, int n, int target, map<int, int>& mymap) {
	if (n == target) {
		mymap[sum]++;
		return;
	}
	for (int i = 1; i <= 6; ++i) {
		sum += i;
		dfs(sum, n + 1, target, mymap);
		sum -= i;
	}
}
vector<double> dicesProbability(int n) {
	map<int, int> mymap;
	dfs(0, 0, n, mymap);
	double len = 0;
	cout << mymap.size() << endl;
	for (auto iter : mymap) {
		cout << iter.first <<", "<<iter.second<<endl;
		len += iter.second;
	}
	vector<double> res(mymap.size());
	int idx = 0;
	for (auto iter : mymap) {
		res[idx++] = static_cast<double>(iter.second) / len;
	}

	return res;
}

//超时
void test01()
{
	auto res = dicesProbability(4);
	//for (auto iter : res)
	//	cout << iter << " ";
	//cout << endl;

	//auto res = dicesProbability2(3);
	//for (auto iter : res)
	//	cout << iter << " ";
	//cout << endl;
}

/// <summary>
/// 题解的解法,动态规划解决
/// </summary>
/// <returns></returns>
///
/*
dp[i][j]代表投i个骰子,值j出现的阿次数

最后一次,dp[n][j]代表最后一次投完了,j总共出现的次数
不管投哪一次,最后一次也是一样的,出现的点数只可能是1,2,3,4,5,6
第n次,j出现的总次数,可以从投递第n-1枚骰子得到,可以从对应的j-1,j-2,j-3,...j-6出现的次数之和转换过来

for(第n枚骰子的点数 i=1;i<=6;++i) {
	dp[n][j] +=dp[n-1][j-i];
}
///例如要求值20出现的次数,可以从上一次投骰子19,18,17,16,15,14的次数转换而来
20=19+1,20=18+2,20=17+3,20=16+4,20=15+5,20=14+6

//边界处理
投递第一枚骰子,出现的值是1,2,3,4,5,6,都出现了1次
for(int i=1;i<=6;++i) {
	dp[1][i]=1;
}

*/

vector<double> dicesProbability2(int n) {
	vector<vector<int> > dp(n + 1, vector<int>(6 * n + 1));

	for (int i = 1; i <= 6; ++i) {
		dp[1][i] = 1;//投递1次的时候,1-6各出现了一次
	}
	for (int i = 2; i <= n; ++i) {//从2个骰子到n个骰子
		for (int j = 2; j < 6 * n + 1; ++j) {//可能出现的值从2到6*n
			for (int k = 1; k <= 6; ++k) {//出现的值可以从上一次投的情况转换来
				if (j - k < 1)
					break;
				if (j-k>=1)
					dp[i][j] += dp[i - 1][j - k];
			}
		}
	}//for i=2;

	vector<double> res;//一共有这么多个元素出现,分别计算概率
	res.reserve(6 * n + 1);
	int all_cnt = 0;
	all_cnt = accumulate(dp[n].begin(), dp[n].end(), 0);
	int res_idx = 0;//res数组的下标
	for (int i = 1; i <= 6 * n; ++i) {
		if (dp[n][i] != 0) {
			res.push_back(dp[n][i] / static_cast<double>(all_cnt));
		}
	}
	return res;

}
void test02()
{
	auto res = dicesProbability2(2);
	for (auto iter : res)
		cout << iter << " ";
	cout << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#endif