#if 0
#include "../headers/wjxHeaders.h"

/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。



*/
bool isValidSudoku(vector<vector<char>>& board) {
	
	int row = board.size();//9
	int col = board.front().size();//9

	unordered_map<char, int> hashtable;
	//检查每一个元素

	int i = 0;
	int j = 0;
	for (; i < row; i++) {
		for (; j < col; j++) {//每一个元素的遍历
			
			if (board[i][j] == '.')
				continue;
			//首先检查列上有没有相同的
			for (int m = 0; m < col; m++) {
				if (m == j)
					continue;
				if (board[i][m] == '.')
					continue;
				//cout << "current =" << board[i][j] << ",foreached=" << board[i][m] << endl;
				if (hashtable.count(board[i][m]) > 0)
					return false;
				else
					hashtable.insert(make_pair(board[i][m], m));
				//if (board[i][m] == board[i][j])
				//	return false;
			}

			hashtable.clear();
			//再检查行上的有没有相同的 
			for (int n = 0; n < row; n++) {
				if (n == i)
					continue;
				if (board[n][j] == '.')
					continue;
				if (hashtable.count( board[n][j] ) > 0)
					return false;
				else
					hashtable.insert(make_pair(board[n][j], n));
				if (board[n][j] == board[i][j])
					return false;
			}
			hashtable.clear();

			//在检查小格子有没有相同的
			int k = i / 3 * 3;
			int p = j / 3 * 3;
			int time = 0;

			int k3 = k + 3;
			int p3 = p + 3;

			for (; k < k3; k++) {
				for (; p < p3; p++) {
					if (k == i && p == j)
						continue;
					if (board[k][p] == '.')
						continue;
					//if (board[k][p] == board[i][j])
					//	return false;
					if (hashtable.count(board[k][p]) > 0)
						return false;
					else
						hashtable.insert(make_pair(board[k][p], k));
				}
			}

			j++;
		}
		i++;
	}
	return true;
}

void test01()
{
	vector<vector<char>> str =
		{   
			{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
			{'5', '.', '.', '.', '.', '.', '.', '9', '.'}, 
			{'.', '.', '.', '5', '6', '.', '.', '.', '.'}, 
			{'4', '.', '3', '.', '.', '.', '.', '.', '1'}, 
			{'.', '.', '.', '7', '.', '.', '.', '.', '.'}, 
			{'.', '.', '.', '5', '.', '.', '.', '.', '.'},
			{'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
			{'.', '.', '.', '.', '.', '.', '.', '.', '.'}
		
		};

	cout << isValidSudoku(str) << endl;;
}
bool isValidSudoku2(vector<vector<char>>& board) {
	unordered_set<char> rowset;
	unordered_set<char> colset;
	for (int i = 0; i < 9; ++i) {//检查每一行
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] == '.')
				continue;
			if (rowset.find(board[i][j]) == rowset.end())
				rowset.insert(board[i][j]);
			else
				return false;
		}
		rowset.clear();
	}
	for (int i = 0; i < 9; ++i) {//一共9行
		for (int j = 0; j < 9; ++j) {

			if (board[j][i] == '.')
				continue;
			if (colset.find(board[j][i]) == colset.end())
				colset.insert(board[j][i]);
			else
				return false;
		}
		colset.clear();
	}
	//在每个格子内部,检查是否有重复的
	int rowlimit = 3, collimit = 3;
	int row = 0, col = 0;

	while (rowlimit < 12) {
		while (collimit < 12) {
			for (int i = row; i < rowlimit; ++i) {
				for (int j = col; j < collimit; ++j) {
					if (board[i][j] == '.')
						continue;
					if (rowset.find(board[i][j]) == rowset.end())
						rowset.insert(board[i][j]);
					else
						return false;
				}//内层for
			}//外层for
			col = collimit;
			collimit += 3;
			rowset.clear();
		}//内while 
		col = 0;
		collimit = 3;
		row = rowlimit;
		rowlimit += 3;

	}

	return true;
}
void test02()
{
	
	for (int i = 0; i < 9; i++)
	{
		auto p = i / 3 * 3;
		cout << "i=" << i << ",p=" << p << endl;
	}
}
/*

[[".",".","4",".",".",".","6","3","."],
[".",".",".",".",".",".",".",".","."],
["5",".",".",".",".",".",".","9","."],
[".",".",".","5","6",".",".",".","."],
["4",".","3",".",".",".",".",".","1"],
[".",".",".","7",".",".",".",".","."],
[".",".",".","5",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."]]

[[".",".",".",".",".",".","5",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".",".",".",".",".",".","."],
["9","3",".",".","2",".","4",".","."],
[".",".","7",".",".",".","3",".","."],
[".",".",".",".",".",".",".",".","."],
[".",".",".","3","4",".",".",".","."],
[".",".",".",".",".","3",".",".","."],
[".",".",".",".",".","5","2",".","."]]
*/
int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}


#endif