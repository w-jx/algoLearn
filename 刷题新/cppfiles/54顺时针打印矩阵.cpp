#if 0
#include "../headers/wjxHeaders.h"


//˳ʱ���ӡ����
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) return {};
    int left = 0, 
    right = matrix.front().size()-1, 
    top = 0, 
    bottom = row-1;
    vector<int> vret;
    while (true) { //���߽��Ƿ����������˳���ӡ������
        //left---->right
        for (int i = left; i <= right; i++)  vret.push_back(matrix[top][i]);//��ӡ�ϱ߽�
        if (++top > bottom) break;//�����趨�ϱ߽磬���ϱ߽�����±߽磬�����������ɣ���ͬ
        //top--->bottom
        for (int i = top; i <= bottom; i++) vret.push_back(matrix[i][right]);//��ӡ�ұ߽�
        if (left > --right) break;//�����趨�ұ߽�
        //right--->left
        for (int i = right; i >= left; i--) vret.push_back(matrix[bottom][i]);//��ӡ�±߽�
        if (top > --bottom) break;//�����趨�±߽�
        //bottom--->top
        for (int i = bottom; i >= top; i--) vret.push_back(matrix[i][left]);//��ӡ��߽�
        if (++left > right) break;//�����趨��߽�
    }
    return vret;
}
//2021��6��29��,֮ǰд���е������
//����дһ������ķ���
vector<int> spiralOrder2(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 0 || n == 0)
        return {};
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    
    vector<int> ret(m*n);
    int i = 0,j=0;
    while (true) {
        //��������ұ�ǰ��
        while (i <= right)
            ret[j++]=matrix[top][i++];
        //��һ����Ҫ������,�����ǰ��top�Ѿ������һ��,˵���Ѿ�����������
        if (top == bottom)//����������,�����¾�Խ����߱������Ѿ���������Ԫ����
            break;
        i = ++top;//��ǰ�б�����,������һ�п�ʼ����
        while (i <= bottom)
            ret[j++]=matrix[i++][right];
        if (right == left)//���������������
            break;
        i = --right;
        while (i >= left)
            ret[j++] = matrix[bottom][i--];
        if (bottom == top)
            break;
        i = --bottom;
        while (i >= top)
            ret[j++] = matrix[i--][left];
        if (left == right)
            break;
        i = ++left;
    }
    return ret;
}
void test01()
{
    vector<vector<int> > vret{ {1,2,3},{4,5,6},{7,8,9} };
    printVector(spiralOrder(vret));
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif