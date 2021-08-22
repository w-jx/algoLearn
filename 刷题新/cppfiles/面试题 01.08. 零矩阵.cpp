#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零

*/
void setZeroes(vector<vector<int>>& matrix) {

	vector<pair<int, int>>m;
	int len = matrix.size();
	int len2 = matrix[0].size();
	for (size_t i = 0; i < len; i++) { //找到所有0的位置
		for (size_t j = 0; j < len2; j++) {
			if (matrix[i][j] == 0)
				m.push_back(make_pair(i, j));
		}
	}

	
	for (size_t i = 0; i < m.size(); i++) {
		auto p = m.at(i);
		for (size_t j = 0; j < len; j++) {
			matrix[j][p.second] = 0;
		}
		for (size_t j = 0; j < len2; j++) {
			matrix[p.first][j] = 0;

		}
		
	}

	printvectorvector(matrix);
	


}
void test01()
{
	//vector<vector<int>> matrix = {
	//	{1,1,1} ,
 // {1,0,1},
 // {1,1,1}
	//};
//	vector<vector<int>> matrix = {
//	{0,1,2,0} ,
//{3,4,5,2},
//{1,3,1,5}
//	};
	vector<vector<int>> matrix = {
{0,1}
	};
	setZeroes(matrix);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif