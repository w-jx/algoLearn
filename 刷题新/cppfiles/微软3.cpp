#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/


int solution(vector< vector<int> >& A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<vector<int>> two(A.size(), vector<int>(A[0].size(), 0));
    vector<vector<int>> five(A.size(), vector<int>(A[0].size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            int x = A[i][j];
            while (x % 2 == 0)
            {
                two[i][j]++;
                x /= 2;
            }
            while (x % 5 == 0)
            {
                five[i][j]++;
                x /= 5;
            }
        }
    }
    vector<vector<vector<int>>>twos(A.size(), vector<vector<int>>(A[0].size(),vector<int>(4,0)));
    //0代表上边,1代表下边,2代表左面,3代表右面
    vector<vector<vector<int>>>fives(A.size(), vector<vector<int>>(A[0].size(), vector<int>(4, 0)));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            twos[i][j][0] += two[i][j];
            twos[i][j][2] += two[i][j];
            if (i > 0)twos[i][j][0] += twos[i - 1][j][0];
            if (j>0)twos[i][j][2] += twos[i][j-1][2];


            fives[i][j][0] += five[i][j];
            fives[i][j][2] += five[i][j];
            if (i > 0)fives[i][j][0] += fives[i - 1][j][0];
            if (j > 0)fives[i][j][2] += fives[i][j - 1][2];


        }
    }

    //从下往上,从右往左
    for (int i = A.size()-1; i >=0; i--)
    {
        for (int j = A[0].size()-1; j >=0; j--)
        {
            twos[i][j][1] += two[i][j];
            twos[i][j][3] += two[i][j];
            if (i < A.size() - 1)twos[i][j][1] += twos[i + 1][j][1];
            if (j < A[0].size() - 1)twos[i][j][3] += twos[i][j + 1][3];

            fives[i][j][1] += five[i][j];
            fives[i][j][3] += five[i][j];
            if (i < A.size() - 1)fives[i][j][1] += fives[i + 1][j][1];
            if (j < A[0].size() - 1)fives[i][j][3] += fives[i][j + 1][3];


        }
    }
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            int x;
            x = min(twos[i][j][0] + twos[i][j][2] - two[i][j], fives[i][j][0] + fives[i][j][2] - five[i][j]);
            ans = ans > x ? ans : x;
            x = min(twos[i][j][0] + twos[i][j][3] - two[i][j], fives[i][j][0] + fives[i][j][3] - five[i][j]);
            ans = ans > x ? ans : x;
            x = min(twos[i][j][1] + twos[i][j][3] - two[i][j], fives[i][j][1] + fives[i][j][3] - five[i][j]);
            ans = ans > x ? ans : x;
            x = min(twos[i][j][1] + twos[i][j][2] - two[i][j], fives[i][j][1] + fives[i][j][2] - five[i][j]);
            ans = ans > x ? ans : x;
        }
    }
    return ans;

}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif