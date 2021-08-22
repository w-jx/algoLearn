#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
深度优先搜索

*/

/// <summary>
/// 从(x,y)出发,能搜索到 word以k开头到结尾的字符串
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="k"></param>
/// <param name="board"></param>
/// <param name="word"></param>
/// <param name="visit"></param>
/// <param name="m"></param>
/// <param name="n"></param>
/// <returns></returns>
bool dfs(int x, int y, int k, vector<vector<char>>& board, string& word, vector<vector<int>>& visit, int& m, int& n) {
	if (board[x][y] != word[k])
		return false;
	else if (k == (word.size() - 1))
		return true;

	visit[x][y] = 1;
	static const int dx[] = { -1,1,0,0 };
	static const int dy[] = { 0,0,-1,1 };
	bool res = false;
	for (int i = 0; i < 4; ++i) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx >= 0 && newx < m && newy >= 0 && newy < n && visit[newx][newy] == 0) {
			bool flag = dfs(newx, newy, k + 1, board, word, visit, m, n);
			if (flag) {
				res = true;
				break;
			}
		}
	}
	visit[x][y] = 0;
	return res;
}
bool exist(vector<vector<char>>& board, string word) {
	if (board.empty())
		return false;
	int m = board.size();
	int n = board[0].size();
	vector<vector<int>> visit(m, vector<int>(n));

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visit[i][j] == 0) {
				if (dfs(i, j, 0, board, word, visit, m, n)) {
					return true;
				}
			}
		}
	}
	return false;
}
void test01()
{
	vector<vector<char>> board{ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
	cout << exist(board, "ABCCED") << endl;;
}
int main()
{
	test01();
	return 0;
}
#endif