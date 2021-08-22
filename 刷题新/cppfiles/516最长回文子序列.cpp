#if 0
#include "../headers/wjxHeaders.h"

int longestPalindromeSubseq(string s) {
    int n = s.size();
    
    //dp[i][j]代表从i,j的最长回文子序列的长度 
    vector<vector<int> > dp(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
    
       
}
void test01()
{
    cout << longestPalindromeSubseq("bbbab") << endl;
}
int main()
{
	test01();
}
#endif