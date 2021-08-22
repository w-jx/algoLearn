#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

虽然也可以用74题的方法，我想尝试下新方法

*/

/// <summary>
/// 从右上角找
/// </summary>
/// <param name="matrix"></param>
/// <param name="target"></param>
/// <returns></returns>
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int col = n - 1;
	int row = 0;//从右上角来找
	while (col >= 0 && row < m) {
		if (target == matrix[row][col])
			return true;
		else if (target > matrix[row][col])//当前位置不够大，向下找
			row++;
		else if (target < matrix[row][col])//当前位置大了，往左边找
			col--;
	}
	return false;

}
void test01()
{
	vector<vector<int> > v{
		 {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}
	};
	cout << searchMatrix(v,11) << endl;
}
int main()
{
	test01();
	
	return 0;
}
#endif