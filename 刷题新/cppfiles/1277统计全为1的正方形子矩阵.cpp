#if 0
#include "../headers/wjxHeaders.h"

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));
    int cnt = 0;

    //dp[i][j]���Ե�Ԫ��[i][j]Ϊ���½ǵõ������������α߳�
    //ͬʱ,Ҳ����[i][j]Ϊ���½ǵ�����С��������Ŀ֮��
    /*
    [
        1 1
        1 1
    ]
    dp[0][0]=1
    dp[0][1]=1
    dp[1][0]=1
    ������ǹ̶�[1][1],���Է�����ɵ���������α߳�Ϊ2
    ͬʱҲ˵�������2��С������,һ�������½ǵı߳�Ϊ1��,����
    �Ǳ߳�Ϊ2��,��Ϊ���ǹ̶����½�,�������е�dp[i][j]�������ظ�
    ����ۼӾ�����
    
    */
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (matrix[i - 1][j - 1] == 1) {
                dp[i][j] = std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1; 
            }
            cnt += dp[i][j];
        }
    }
    return  cnt;
}
void test01()
{
    vector<vector<int> > matrix
    {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    cout << countSquares(matrix) << endl;

}
int main()
{
	test01();
}
#endif