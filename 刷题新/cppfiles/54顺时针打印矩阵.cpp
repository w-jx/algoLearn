#if 0
#include "../headers/wjxHeaders.h"


//顺时针打印矩阵
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) return {};
    int left = 0, 
    right = matrix.front().size()-1, 
    top = 0, 
    bottom = row-1;
    vector<int> vret;
    while (true) { //（边界是否相遇）是退出打印的条件
        //left---->right
        for (int i = left; i <= right; i++)  vret.push_back(matrix[top][i]);//打印上边界
        if (++top > bottom) break;//重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
        //top--->bottom
        for (int i = top; i <= bottom; i++) vret.push_back(matrix[i][right]);//打印右边界
        if (left > --right) break;//重新设定右边界
        //right--->left
        for (int i = right; i >= left; i--) vret.push_back(matrix[bottom][i]);//打印下边界
        if (top > --bottom) break;//重新设定下边界
        //bottom--->top
        for (int i = bottom; i >= top; i--) vret.push_back(matrix[i][left]);//打印左边界
        if (++left > right) break;//重新设定左边界
    }
    return vret;
}
//2021年6月29日,之前写的有点难理解
//重新写一个好想的方法
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
        //从左边往右边前进
        while (i <= right)
            ret[j++]=matrix[top][i++];
        //下一步就要往下了,如果当前的top已经是最后一行,说明已经遍历结束了
        if (top == bottom)//不能往下了,再往下就越界或者遍历到已经遍历过的元素了
            break;
        i = ++top;//当前行遍历了,从下面一行开始遍历
        while (i <= bottom)
            ret[j++]=matrix[i++][right];
        if (right == left)//不能再往左边走了
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