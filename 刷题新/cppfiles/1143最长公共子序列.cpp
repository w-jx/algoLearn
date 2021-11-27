#if 1
#include "../headers/wjxHeaders.h"

/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。


*/
int longestCommonSubsequence(string text1, string text2){
    int n1 = text1.size();
    int n2 = text2.size();
    //dp[i][j] ��text1[i],��text2[j]��ɵ�����������еĳ���
    vector<vector<int> > dp(n1+1, vector<int>(n2+1));

    /*
    dp[i][j]Ϊ[0,i]��text1,[0,j]������������еĳ���
    �߽�:
    i=0,����text2���ĸ���ĸ,����dp[0][j]=0;
    j=0,����text1���ĸ���ĸ,����dp[i][0]=0;

    ��text1[i-1]==text2[j-1]:
    ��û�й����ַ�������������еĳ���+�����ַ�����1
        dp[i][j]=dp[i-1][j-1]+1

    ��text1[i-1]!=text2[j-1],
    ����dp[i-1][j],dp[i][j-1]�����ֵ
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