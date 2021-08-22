#if 0
#include "../headers/wjxHeaders.h"
//dfs
//剑指offer 38 字符串的排列

// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

/* 是否可以在 board[row][col] 放置皇后？ */
bool isValid(vector<string>& board, int row, int col) {
    int n = board.size();
    // 检查列是否有皇后互相冲突
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // 检查右上方是否有皇后互相冲突
    for (int i = row - 1, j = col + 1;
        i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    // 检查左上方是否有皇后互相冲突
    for (int i = row - 1, j = col - 1;
        i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
void dfs(vector<string>& board, int row);
vector<vector<string> > res;//作为返回值
/// <summary>
/// 输入棋盘边长，返回合法的放置
/// </summary>
/// <param name="n">棋盘边长</param>
/// <returns>合法的放置数组</returns>
vector<vector<string>> solveNQueens(int n) {

    vector<string> board(n, string(n, '.'));
	dfs(board, 0);
	return res;
}
/// <summary>
/// 路径：board中小于row的那些行都成功放置了皇后
/// 选择列表：第row行的所有列都是放置皇后的选择
/// 结束条件：row超过board最后一行
/// </summary>
/// <param name="board"></param>
/// <param name="row"></param>
void dfs(vector<string> & board, int row) {

	if (row == board.size()) {//触发结束条件
		res.push_back(board);
		return;
	}
	int n = board[row].size();
	for (int col = 0; col < n; col++) {
        //排除不合法选择
        if (!isValid(board, row, col))
            continue;
        //做选择
        board[row][col] = 'Q';
        //进入下一行决策
        dfs(board, row + 1);
        //撤销选择
        board[row][col] = '.';
        
	}

}

//上面的代码都是以前抄的，现在重新学习一个教程
//1.为了解决问题，我们先解决描述将皇后放到棋盘的过程
void put_down_queens(int x,int y,vector<vector<int> >&mark)
{
    static const  int dx[] = { -1,1,0,0,-1,-1,1,1};
    static const  int dy[] = { 0,0,-1,1,-1,1,-1,1 };//方向数组
    //上 下 左 右 左上 右上 左下 右下
    mark[x][y] = 1;//放了皇后，肯定是1

    for (int i = 1; i < mark.size(); ++i) {
        for (int j = 0; j < 8; ++j) {
            int nex_x = x+dx[j]*i;//新的位置 像外面延申
            int new_y =y+dy[j]*i ;//每个方向延申N-1
            if (nex_x>=0 && nex_x<mark.size() && new_y>=0 && new_y<mark.size()) {//判断是否还在棋盘上
                mark[nex_x][new_y] = 1;
            }
        }
    }

}
//测试将某个皇后放到棋盘后，棋盘布局的变化
void test01()
{
    //vector<vector<int> > mark{
    //    {0,0,0,0,0,0,0,0},
    //     {0,0,0,0,0,0,0,0},
    //      {0,0,0,0,0,0,0,0},
    //       {0,0,0,0,0,0,0,0},
    //        {0,0,0,0,0,0,0,0},
    //         {0,0,0,0,0,0,0,0},
    //          {0,0,0,0,0,0,0,0},
    //           {0,0,0,0,0,0,0,0}
    //};
    //for (int i = 0; i < mark.size(); ++i) {
    //    for (int j = 0; j < mark[i].size(); ++j) {
    //        cout << mark[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << "after put queens:\n";
    //put_down_queens(3, 4, mark);//测试在3，4位置放置皇后
    //for (int i = 0; i < mark.size(); ++i) {
    //    for (int j = 0; j < mark[i].size(); ++j) {
    //        cout << mark[i][j] << " ";
    //    }
    //    cout << endl;
    //}


}
/// <summary>
/// 
/// </summary>
/// <param name="k">k代表完成了几个皇后，正在放置第K行的皇后</param>
/// <param name="n">N皇后</param>
/// <param name="location">某一次的摆放结果</param>
/// <param name="mark">棋盘的标记数组</param>
void dfs2(int k,int n, vector<string>&location,vector<vector<int>> mark)
{
    if (k == n) {
        res.push_back(location);
        return;
    }
    for (int i = 0; i < n; i++) {//尝试第0-n-1列
        if (mark[k][i]==0) {//放置  皇后的条件
            auto temp_mark = mark;//记录回溯前的mark镜像
            
            location[k][i] = 'Q';//记录当前皇后的位置
            put_down_queens(k, i, mark);//放置皇后
            dfs2(k + 1, n, location, mark);//放置下一行的皇后放置
            mark = temp_mark;//回溯以后 恢复mark 和 摆放结果location
            location[k][i] = '.';
        }
    }
}
//具体解决 
vector<vector<string>> solveNQueens2(int n) {
    vector<vector<int>> mark(n, vector<int>(n, 0));
    vector<string>location (n, string(n, '.'));//存储某个摆放的结果
    dfs2(0, n, location, mark);
    
    return res;
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif