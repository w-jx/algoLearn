#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

��ȻҲ������74��ķ��������볢�����·���

*/

/// <summary>
/// �����Ͻ���
/// </summary>
/// <param name="matrix"></param>
/// <param name="target"></param>
/// <returns></returns>
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size(), n = matrix[0].size();
	int col = n - 1;
	int row = 0;//�����Ͻ�����
	while (col >= 0 && row < m) {
		if (target == matrix[row][col])
			return true;
		else if (target > matrix[row][col])//��ǰλ�ò�����������
			row++;
		else if (target < matrix[row][col])//��ǰλ�ô��ˣ��������
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