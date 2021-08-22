#if 0
#include "../headers/wjxHeaders.h"



//杨辉三角，根据给定的层数，生成杨辉三角
vector<vector<int>> generate(int numRows) {
	if (numRows == 0)
		return { {} };
	vector<vector<int>> vret;
	vector<int> vtemp;
	for (int i = 0; i < numRows; i++) {
		int len = i + 1;
		int left = 0, right = i;
		vtemp.resize(i + 1);
		while (left <= right) {
			if (i == 0) {
				vtemp[left]=1;
			}
			else {
				if (left == 0)
					vtemp[left] = vtemp[right] = 1;
				else {
					vtemp[left] = vret[i - 1][left - 1]+vret[i-1][left];
					vtemp[right] = vtemp[left];
				}
			}
			left++;
			right--;
		}
		vret.push_back(vtemp);
		vtemp.clear();
	}
	return vret;

}
//杨辉三角2：给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
//这种递归方法 超时了，可以看到参数11时，已经超过1分钟了
vector<int> getRow(int rowIndex) {
	if (rowIndex == 0)
		return { 1 };
	else {
		int left = 0, right = rowIndex;//非负索引 第二行的最大下标为1
		vector<int> vtemp;
		vtemp.resize(rowIndex+1);
		while (left <= right) {
			if (left == 0)
				vtemp[left] = vtemp[right] = 1;
			else {
				vtemp[left] = getRow(rowIndex - 1)[left - 1] + getRow(rowIndex - 1)[left];
				vtemp[right] = vtemp[left];
			}
			left++;
			right--;
		}
		return vtemp;
	}
		
}
void test01()
{
	int nRows = 11;
	auto ret = generate(nRows);
	printvectorvector<int>(ret);
	//为什么printvectorvector(generate(5))出错？
}
void test02()
{
	int row = 11;
	printVector(getRow(row));
}

int main()
{
	test01();//杨辉三角1
	//test02();//杨辉三角2
	cout << INT_MAX << endl;
	double int_max = INT_MAX;
	cout << "int_max=" << int_max << endl;
	if ((int_max - 1e9 + 7) > 0.0)
		cout << ">\n";
	else
		cout << "<\n";
	
	system("pause");
	return 0;
}


#endif