#if 0
#include "../headers/wjxHeaders.h"

/*
s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
s1 = "aabcc"=aa +bc+ c
s2 = "dbbca" = db+bca
aa  db bc bca c
*/
//�����ķ���
bool isInterleave(string s1, string s2, string s3) {
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if (n1 + n2 != n3)
		return false;
	//dp[i][j]����s1[:i],s2[:j]�ܷ񽻴��ʾs3[:i+j]
	vector<vector<bool> > dp(n1+1, vector<bool>(n2+1,false));
	dp[0][0] = true;//��Ϊs1��ǰ0���ַ���s2��ǰ0���ַ������Խ������s3��ǰ0���ַ�
	//��Ϊi>0��j>0�ǰ����˳�f[0][0]���еĵ㣬�����ֱ��дi=1,�൱��ֱ�ӵ��˵ڶ���
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <=n2; ++j) {
			int p = i + j - 1;

			/*
			s1��i,s2��j,�ܷ񽻴��ʾs3��i+j
			�����ǰ��s1[i]==s3[i+j-1],��ô�Ϳ�
			s1��i-1��Ԫ��,s2��j��Ԫ���Ƿ������s3��i+j-1��Ԫ��

			�����ǰ��s2[j]==s3[i+j-1],��ô�Ϳ�
			s1��i��Ԫ��,s2��j-1��Ԫ���Ƿ������s3��i+j-1��Ԫ��
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
//�����ķ���,�޸��±�ʾ����
bool isInterleave2(string s1, string s2, string s3) {
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if (n1 + n2 != n3)
		return false;
	//dp[i][j]����s1[:i],s2[:j]�ܷ񽻴��ʾs3[:i+j]
	vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
	dp[0][0] = true;//��Ϊs1��ǰ0���ַ���s2��ǰ0���ַ������Խ������s3��ǰ0���ַ�
	//��Ϊi>0��j>0�ǰ����˳�f[0][0]���еĵ㣬�����ֱ��дi=1,�൱��ֱ�ӵ��˵ڶ���
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <= n2; ++j) {
			int p = i + j - 1;

			/*
			s1��i,s2��j,�ܷ񽻴��ʾs3��i+j
			�����ǰ��s1[i]==s3[i+j-1],��ô�Ϳ�
			s1��i-1��Ԫ��,s2��j��Ԫ���Ƿ������s3��i+j-1��Ԫ��

			�����ǰ��s2[j]==s3[i+j-1],��ô�Ϳ�
			s1��i��Ԫ��,s2��j-1��Ԫ���Ƿ������s3��i+j-1��Ԫ��
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
	���Է���dp[i]ֻ��dp[i-1]���,���Կ��Խ���ά��
	*/
	//dp[j]����s2[:j]�ܺ�s1[:x]�������s3[:j+x] 
	vector<int> dp(n2 + 1,false);
	dp[0] = true;
	for (int i = 0; i <= n1; ++i) {
		for (int j = 0; j <= n2; ++j) {
			int p = i + j - 1;
			if (i > 0) {
				/*
					0&0->0,0&1->0,1&0->0,1&1->1

					dp[j]����s2[:j]�ܺ�s1[:x]�������s3[:j+x]
					Ҳ����dp[j]���Ѿ�ȷ�����Ե�ʱ��,ֻ�е�s[i-1]==s3[p]��ʱ��
					dp[j]�ż����ܹ��������s3,��Ӧ1&1->1

					��dp[j]ȷ���޷���ɵ�ʱ��,����s1[i - 1] == s3[p]
					Ҳ����,����s1[i-1]!=s3[p]
					��Ӧ:0&0->0,0&1->0,1&0->0
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