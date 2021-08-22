#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

*/
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	vector<int> nums;
	int m = matrix.size();//行
	int n = matrix.front().size();//列
	int i = 0, j = 0;
	bool upwards = true;
	while (true) {

		nums.push_back(matrix[i][j]);
		if (i == m-1 && j == n-1)
			break;
		if (upwards && (i == 0||j==n-1)) {
			upwards = !upwards;
			j++;
			continue;
		}
		if (!upwards && (j == 0||i==m-1)) {
			upwards = !upwards;
			j++;
			continue;
		}
		if (upwards) {
			i--;
			j++;
		}
		else {
			i++;
			j--;
		}
	}
	return nums;
	
	
}

//题解 学习
vector<int> foreachMatrix(vector<vector<int>>& matrix)
{
	vector<int> nums;
	int m = matrix.size();
	int n = matrix[0].size();

	int i = 0;	// i 是 x + y 的和
/*
1  2  3 
4  5  6 
7  8  9
10 11 12
matrix[x][y] 这个 x 指的是4行中的哪一行，y指的是3列中的哪一列
而从位置上说x应该是横坐标，y是纵坐标。  相反了理解不能错了
*/
	while (i < m + n) 
	{
		// 第 1 3 5 ... 趟  从下往上面走    
		int x1 = (i < m) ? i : m - 1;	// 确定 x y 的初始值 x尽量大
		int y1 = i - x1;//x+y==i 
				//初始值超过x的上限，多余的加到y上
		while (x1 >= 0 && y1 < n)
		{
			nums.push_back(matrix[x1][y1]); //第三次：7(2,0)--->5(1,1)---->3(0,2) 
			x1--;
			y1++; //x减到0或者y加到上限 就停止
		}
		i++;

		if (i >= m + n) break;
		// 第 2 4 6 ... 趟  从上往下面走
		//第二次： 2(0,1)--->4(1,0)  x增加，y减小 x+y=1
		//第四次: 6(1,2)----->8(2,1) ,x增加，y减小，x+y=3
		int y2 = (i < n) ? i : n - 1;	// 确定 x y 的初始值，y尽量大
		//初始值超过y的上限，多余的加到x上
		int x2 = i - y2;
		while (y2 >= 0 && x2 < m)
		{
			nums.push_back(matrix[x2][y2]);
			x2++;
			y2--;
		}
		i++;
	}//while  i <m+n
	return nums;

}

void test01()
{
	vector<vector<int>> matrix = {
   {1,2,3} ,
   {4,5,6},
   {7,8,9}	
};


	vector<vector<int>> matrix2 = {
		{0,1,2,3},
		{4,5,6,7}
	};
	//printVector(findDiagonalOrder(matrix2));
	printVector(foreachMatrix(matrix));

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif