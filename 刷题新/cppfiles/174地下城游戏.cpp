#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	if (dungeon.empty())
		return 0;
	//dp[i][j]代表到达dungeon[i][j]位置,至少需要多少血量
	vector<vector<int> > dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
	int row = dungeon.size();
	int col = dungeon[0].size();
	/*
	如果公主所在的位置:
	1.是个负数,例如是-5 那么max(1,1-(-5)) =6,代表至少需要6点血量
	2.是0,那么max[1,1-0]=1,代表至少需要1点血量
	3.是正数,例如3,那么max(1,1-3)=max(1,-2)=1,代表这个位置可以加血,还是至少需要1点血量
	*/
	dp[row - 1][col - 1] = std::max(1, 1 - dungeon[row - 1][col - 1]);

	//下面把最后一列和最后一行的值给确定了
	//先确定最后一行

	/*
	例如我们的数组就是[3,2,-5]
	先确定dp[row-1][col-1]=6,至少需要6点血,然后确定前面两个
	因为到第三个位置需要6,在第二个位置还加了2点血,所以到第二个位置至少需要4
	因为到第二个位置需要4,在第一个位置还加了3点血,所以到第一个位置至少需要1

	也就是dp[i][j]和dp[i][j+1]有关系
	std::max(1, dp[row-1][i+1] - dungeon[row - 1][i]);
	例如dp[row-1][i+1]是6,如果dungeon[row - 1][i] 是整数2,
	那么就应该减去 6-2=4,代表当前位置至少需要血量4

	如果dungeon[row - 1][i] 是负数 -3
	那么应该减去 6-(-3)=9,至少需要9,在这个位置扣了3点血,到最后一个位置还剩下6点

	如果dp[row-1][i+1]是0,
	还是应该减去,6-0=0,至少需要6,这样在这个位置不变化,在最后一个位置还剩下6点

	但是无论怎么处理,我们在某个位置至少需要血量1,也就是最低血量是1

	健康点数在某一时刻降至 0 或以下，他会立即死亡
	
	*/
	for (int i = col - 2; i >= 0; i--) {
		dp[row - 1][i] = std::max(1, dp[row-1][i+1] - dungeon[row - 1][i]);
	}
	for (int i = row - 2; i >= 0; i--) {
		dp[i][col - 1] = std::max(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);
	}
	int dp_min = 0;//为了记录dp[i][j] 下面dp[i+1][j]和右边dp[i][j+1]哪个更小
	//同样都是减去一个数,3-5=-2,10-5=5,小的结果更小
	//计算 其他位置
	for (int i = row - 2; i >= 0; --i) {
		for (int j = col - 2; j >= 0; --j) {
			dp_min = std::min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = std::max(1 ,dp_min - dungeon[i][j]);
		}
	}
	return dp[0][0];
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