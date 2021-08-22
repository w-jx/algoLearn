#if 0
#include "../headers/wjxHeaders.h"

/*
s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
s1 = "aabcc"=aa +bc+ c
s2 = "dbbca" = db+bca
aa  db bc bca c
*/
//答案题解的方法
bool isInterleave(string s1, string s2, string s3) {
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if (n1 + n2 != n3)
		return false;
	//dp[i][j]代表s1[:i],s2[:j]能否交错表示s3[:i+j]
	vector<vector<bool> > dp(n1+1, vector<bool>(n2+1,false));
	dp[0][0] = true;//认为s1的前0个字符和s2的前0个字符，可以交替组成s3的前0个字符
	//因为i>0和j>0是包括了除f[0][0]所有的点，你如果直接写i=1,相当于直接到了第二行
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <=n2; ++j) {
			int p = i + j - 1;

			/*
			s1的i,s2的j,能否交错表示s3的i+j
			如果当前的s1[i]==s3[i+j-1],那么就看
			s1的i-1个元素,s2的j个元素是否能组成s3的i+j-1个元素

			如果当前的s2[j]==s3[i+j-1],那么就看
			s1的i个元素,s2的j-1个元素是否能组成s3的i+j-1个元素
			*/

			if (i > 0) {
				if (dp[i - 1][j] && s1[i - 1] == s3[p])
					dp[i][j] = true;
			}		
			if (j > 0) {
				if (dp[i][j-1] && s2[j - 1] == s3[p])
					dp[i][j] = true;
			}

		}
	}
	return dp[n1 ][n2];
}
//答案题解的方法,修改下表示方法
bool isInterleave2(string s1, string s2, string s3) {
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if (n1 + n2 != n3)
		return false;
	//dp[i][j]代表s1[:i],s2[:j]能否交错表示s3[:i+j]
	vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
	dp[0][0] = true;//认为s1的前0个字符和s2的前0个字符，可以交替组成s3的前0个字符
	//因为i>0和j>0是包括了除f[0][0]所有的点，你如果直接写i=1,相当于直接到了第二行
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <= n2; ++j) {
			int p = i + j - 1;

			/*
			s1的i,s2的j,能否交错表示s3的i+j
			如果当前的s1[i]==s3[i+j-1],那么就看
			s1的i-1个元素,s2的j个元素是否能组成s3的i+j-1个元素

			如果当前的s2[j]==s3[i+j-1],那么就看
			s1的i个元素,s2的j-1个元素是否能组成s3的i+j-1个元素
			*/

			if (i > 0) {
				dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[p]);
			}
			if (j > 0) {
				dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[p]);
			}
		}
	}
	return dp[n1][n2];
}
bool isInterleave(string s1, string s2, string s3) {
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if (n1 + n2 != n3)
		return false;
	/*
		if (i > 0) {
			dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[p]);
		}
		if (j > 0) {
			dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[p]);
		}
	可以发现dp[i]只和dp[i-1]相关,所以可以降低维度
	*/
	//dp[j]代表s2[:j]能和s1[:x]交错组成s3[:j+x] 
	vector<int> dp(n2 + 1,false);
	dp[0] = true;
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <= n2; ++j) {
			int p = i + j - 1;
			if (i > 0) {
				/*
					0&0->0,0&1->0,1&0->0,1&1->1

					dp[j]代表s2[:j]能和s1[:x]交错组成s3[:j+x]
					也就是dp[j]是已经确定可以的时候,只有当s[i-1]==s3[p]的时候
					dp[j]才继续能够交错组成s3,对应1&1->1

					而dp[j]确定无法组成的时候,即便s1[i - 1] == s3[p]
					也不行,或者s1[i-1]!=s3[p]
					对应:0&0->0,0&1->0,1&0->0
				*/
				dp[j] &= (s1[i - 1] == s3[p]);
			}
			if (j > 0) {
				if (s2[j - 1] == s3[p] && dp[j - 1] == 1)
					dp[j] = 1; 
			}
		}
	}
	return dp[n2];
}
void test01()
{
	string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
	isInterleave(s1, s2, s3);
}
int main()
{
	test01();
}
#endif