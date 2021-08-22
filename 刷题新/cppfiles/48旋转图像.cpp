#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。


*/
void rotate(vector<vector<int>>& matrix) { //题目要求不能用另一个矩阵,用新矩阵试试
	vector<vector<int>> temp = matrix;
	int len = matrix.size()-1;
	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = 0; j < matrix[i].size(); j++) {
			temp[i][j] = matrix[len - j][i];
		}
	}

	printvectorvector(temp);
}

void rotate2(vector<vector<int>>& matrix) { //原地修改,不用新矩阵
	
	int len = matrix.size() - 1;
	for (size_t i = 0; i < matrix.size(); i++) {
		for (size_t j = i; j < matrix[i].size(); j++) {
			if (i == j) continue;
			swap(matrix[i][j], matrix[j][i]);		
		}
	}
	for (size_t k = 0; k < matrix.size(); k++) {
		for (size_t m = 0; m < matrix.size(); m++) {
			swap(matrix[k][m], matrix[k][len - m]);
		}
	}
	printvectorvector(matrix);


}
void rotate3(vector<vector<int>>& matrix) {
	int n = matrix.size();

	vector< vector<int> > vret(n);
	for (int i = 0; i < n; i++) {
		vret[i].resize(n);
	}
	
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			vret[j][n - i - 1] = matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = vret[i][j];
		}
	}


}
//原地修改尝试 3.9
/*
(i,j)-->(j,n-i+1)
(j,n-i+1)---->(n-i-1,n-j-1)
(n-i-1,n-j-1)------>(n-j-1,i)
(n-j-1,i)----->(i,j)

vret[j][n - i - 1] = matrix[i][j];
//反过来matrix[i][j]要被matrix[n-j-1][i]替代
*/
void rotate4(vector<vector<int>>& matrix) {
	int n = matrix.size(), temp = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < (n + 1) / 2; j++) {
			temp = matrix[i][j];
			matrix[i][j] = matrix[n-j-1][i];
			matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
			matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
			matrix[j][n - i - 1] = temp;
		}
	}

}
//先水平翻转,再主对角线反转
void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < n; ++j) {
			swap(matrix[i][j], matrix[n - 1 - i][j]);
		}
	}//第一步:进行水平反转

	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}
void test01()
{
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	//rotate2(matrix);
	rotate4(matrix);
	printvectorvector(matrix);
}
//vector 内存分配复习
void test02()
{
	vector< int> v;
	//v[0]=10;//肯定报错,越界

	vector<int> v1(2);//不会越界  构造拥有个 count 默认插入的 T 实例的容器。不进行复制。
	//constexpr explicit vector(size_type count,const Allocator & alloc = Allocator());

	vector< vector<int> > vret(3);
	vret.front().resize(3);
	

	
	
}
int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}
#endif