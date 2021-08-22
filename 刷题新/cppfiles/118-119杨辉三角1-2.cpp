#if 0
#include "../headers/wjxHeaders.h"



//������ǣ����ݸ����Ĳ����������������
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
//�������2������һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�
//���ֵݹ鷽�� ��ʱ�ˣ����Կ�������11ʱ���Ѿ�����1������
vector<int> getRow(int rowIndex) {
	if (rowIndex == 0)
		return { 1 };
	else {
		int left = 0, right = rowIndex;//�Ǹ����� �ڶ��е�����±�Ϊ1
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
	//Ϊʲôprintvectorvector(generate(5))����
}
void test02()
{
	int row = 11;
	printVector(getRow(row));
}

int main()
{
	test01();//�������1
	//test02();//�������2
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