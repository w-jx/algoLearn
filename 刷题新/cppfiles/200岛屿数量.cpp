#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

//在解决问题之前,先做搜索标记问题
/*
探索岛的全部土地,将探索到的位置在数组中标记为1 
分别用DFS 和BFS 来解决这个问题

*/

/// <summary>
/// grid小岛分配,mark 探索位置的标记,x,y是探索某坐标
/// </summary>
/// <param name="mark"></param>
/// <param name="grid"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void dfs(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y)
{
	mark[x][y] = 1;//标记已经搜索的位置
	static const int dx[] = { -1,1,0,0 };
	static const int dy[] = { 0,0,-1,1 };//方向数组,上下左右方向

	for (int i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		
		if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[0].size())
			continue;
		//继续深度优先搜索
		if (mark[newx][newy] == 0 && grid[newx][newy]=='1') {//新位置没有被搜索,而且是1
			dfs(mark, grid, newx, newy);
		}
	}

}

void bfs(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y)
{
	mark[x][y] = 1;//标记已经搜索的位置
	static const int dx[] = { -1,1,0,0 };
	static const int dy[] = { 0,0,-1,1 };//方向数组,上下左右方向

	queue<std::pair<int, int> > posque;//(x,y)坐标,宽度优先搜索队列
	posque.push({ x,y });

	while (!posque.empty()) {
		auto pos = posque.front();
		posque.pop();

		int x = pos.first;
		int y = pos.second;

		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];

			if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[0].size())
				continue;
			//新位置没有被搜索,并且是陆地
			if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
				posque.push({ newx,newy });//新位置入队
				mark[newx][newy] = 1;//标记位置
			}
		}

	}
}
/// <summary>
/// 正式解决问题,调用DFS和BFS进行搜索小岛
/// </summary>
/// <param name="grid"></param>
/// <returns></returns>
int numIslands(vector<vector<char>>& grid) {
	vector<vector<int>> mark(grid.size(), vector<int>(grid.front().size(), 0));
	int island_num = 0;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (mark[i][j] == 0 && grid[i][j] == '1') {
				dfs(mark, grid, i, j);
				//bfs(mark, grid, i, j);
				++island_num;
			}
		}
	}//for 循环

	return island_num;
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