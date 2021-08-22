#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

�̳�:
https://www.jianshu.com/p/a66d5ce49df5

ԭ������:
https://www.acwing.com/problem/content/description/2/

*/

/// <summary>
/// ������Ķ�ά�ⷨ������װ
/// </summary>
/// <param name="goods">[weight,value]</param>
/// <param name="capa"></param>
/// <returns></returns>
int getmaxval(vector<vector<int>>& goods, int capa) {
	if (goods.empty() || capa<1)
		return 0;
	
	int n = goods.size();
	//dp[i][j]����������Ϊj�������,ǰi����Ʒ�ܹ�װ��������ֵ
	vector<vector<int> > dp(n , vector<int>(capa + 1));
	//�ӵ�һ����Ʒ���������һ����Ʒ
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= capa; ++j) {
			//����������С����Ʒ�����,û��װ��ǰ����Ʒ
			if (j < goods[i][0]) {
				if (i == 0) {//��ǰ���ǵ�һ����Ʒ,�ܹ���ɵ�����ֵ����0
					dp[i][j] = 0;
				}
				else {//��Ϊװ���µ�ǰ��Ʒ,��������ֵ��i-1����Ʒ�ڱ�������Ϊj�����
					dp[i][j] = dp[i - 1][j];
				}
			}
			else {//����������������Ʒ�����,����װ��ǰ��Ʒ
				if (i == 0) {
					dp[i][j] = goods[i][1];
				}
				else {
					//��ѡ��ǰ����Ʒ,����ѡ��ǰ��Ʒ,�����ܴ�СΪj,��ǰ��Ʒռ����goods[i][0]
					//��ʣ��j - goods[i][0],�ڵ�ǰ��Ʒ֮ǰ��i-1����Ʒ���ҵ�����ֵ,���
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - goods[i][0]] + goods[i][1]);
				}
			}
		}
	}//for

	return dp[n-1][capa];
}

#if 0
//getmaxval()��������
int main()
{
	vector<vector<int> > goods{
		{1,2},
		{2,4},
		{3,4},
		{4,5}
	};
	cout << getmaxval(goods, 5) << endl;
}
#endif 
#if false
//������Ķ�ά�ⷨ
int main()
{
	//n������Ʒ������,m���������ݻ�
	int n = 0, m = 0;
	cin >> n >> m;
	//dp[i][j]ǰi����Ʒ,��������Ϊj������ֵ
	/*
	if (j<vol[i]) ��ǰ������������,û��ѡ
	����ǰi����Ʒ�����Ž�����ǰi-1����Ʒ�����Ž�
	dp[i][j] =dp[i-1][j]


	if (j>=vol[j]) ��ǰ��������������,��Ҫ����ѡ��
	���ѡ��:dp[i][j] =dp[i-1][j-v[i]]+w[i]
	�����ѡ��:dp[i][j] = dp[i-1][j]
	
	*/
	vector<vector<int> > dp(n + 1, vector<int>(m + 1));
	vector<int> vol(n + 1);//�洢ÿ����Ʒ�������
	vector<int> val(n + 1);//�洢ÿ����Ʒ�ļ�ֵ��
	for (int i = 1; i <= n; ++i) {
		cin >> vol[i];
		cin >> val[i];
	}
	//�ӵ�һ����Ʒ���������һ����Ʒ
	for (int i = 1; i <= n; ++i) {
		//����������1��m
		for (int j = 1; j <= m; ++j) {
			if (j < vol[i]) {//��ǰ���������Ų��������Ʒ
				dp[i][j] = dp[i - 1][j];//ǰi-1����Ʒ�ڱ�������j����µ�����ֵ
			}
			else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - vol[i]] + val[i]);
			}
		}
	}
	cout << dp[n][m] << endl;	
}
#endif

#if true
//״̬ѹ��
int main()
{
	//n������Ʒ������,m���������ݻ�
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> vol(n + 1);//�洢ÿ����Ʒ�������
	vector<int> val(n + 1);//�洢ÿ����Ʒ�ļ�ֵ��
	for (int i = 1; i <= n; ++i) {
		cin >> vol[i];
		cin >> val[i];
	}
	//dp[i]�������n����Ʒ,��������Ϊi�����������ֵ

	vector<int> dp(n + 1);
	
	/*
	ö�ٱ������������m��ʼ��1
	��ά�����,dp[i][j] ����ǰi����Ʒ��������Ϊj������ֵ
	dp[i][j]  ���ܺ�dp[i-1][j]�й�,
	dp[i][j]��dp[i-1][j]���໥������

	һά�����,���dP[��С����]����dP[��С����],���ܱ���Ӧ����i-1��״̬,ȴʹ����i��״̬
	����:
	dp[7]���� n����Ʒ,��������Ϊ7����������ֵ
	dp[4]���� n����Ʒ,��������Ϊ4����������ֵ

	��ǰ��Ʒ�����Ϊ3
	dp[7]   ���Դ�dp[4]���¶���

	dp[4]��ȷ�ĺ���Ӧ����dp[i-1][4],����������Ϊ4,ǰi-1����Ʒ������ֵ
	��ǰ�ǵ�i����Ʒ



	
	*/

	
}
#endif


#endif