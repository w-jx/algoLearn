#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

//�ڽ������֮ǰ,���������������
/*
̽������ȫ������,��̽������λ���������б��Ϊ1 
�ֱ���DFS ��BFS ������������

*/

/// <summary>
/// gridС������,mark ̽��λ�õı��,x,y��̽��ĳ����
/// </summary>
/// <param name="mark"></param>
/// <param name="grid"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void dfs(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y)
{
	mark[x][y] = 1;//����Ѿ�������λ��
	static const int dx[] = { -1,1,0,0 };
	static const int dy[] = { 0,0,-1,1 };//��������,�������ҷ���

	for (int i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		
		if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[0].size())
			continue;
		//���������������
		if (mark[newx][newy] == 0 && grid[newx][newy]=='1') {//��λ��û�б�����,������1
			dfs(mark, grid, newx, newy);
		}
	}

}

void bfs(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y)
{
	mark[x][y] = 1;//����Ѿ�������λ��
	static const int dx[] = { -1,1,0,0 };
	static const int dy[] = { 0,0,-1,1 };//��������,�������ҷ���

	queue<std::pair<int, int> > posque;//(x,y)����,���������������
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
			//��λ��û�б�����,������½��
			if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
				posque.push({ newx,newy });//��λ�����
				mark[newx][newy] = 1;//���λ��
			}
		}

	}
}
/// <summary>
/// ��ʽ�������,����DFS��BFS��������С��
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
	}//for ѭ��

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