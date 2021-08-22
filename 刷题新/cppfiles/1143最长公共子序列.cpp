#if 0
#include "../headers/wjxHeaders.h"

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    //dp[i][j] 到text1[i],到text2[j]组成的最长公共子序列的长度
    vector<vector<int> > dp(n1+1, vector<int>(n2+1));

    /*
    dp[i][j]为[0,i]的text1,[0,j]的最长公共子序列的长度
    边界:
    i=0,不管text2到哪个字母,都有dp[0][j]=0;
    j=0,不管text1到哪个字母,都有dp[i][0]=0;

    当text1[i-1]==text2[j-1]:
    在没有公共字符的最长公共子序列的长度+公共字符长度1
        dp[i][j]=dp[i-1][j-1]+1

    当text1[i-1]!=text2[j-1],
    考虑dp[i-1][j],dp[i][j-1]的最大值
    dp[i][j]=std::max(dp[i][j-1],dp[i-1][j]);
    */
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n1-1][n2-1];
}
void test01()
{
    string str1 = "oxcpqrsvwf";
    string str2 = "shmtulqrypy";

    cout << longestCommonSubsequence(str1, str2) << endl;
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif