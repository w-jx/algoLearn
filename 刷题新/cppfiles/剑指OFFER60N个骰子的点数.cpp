#if 0
#include "../headers/wjxHeaders.h"




/*
�ҵ�˼·:׼��6*n��Ͱ,����ֱ���ù�ϣ��
,��¼ÿ���ͳ��ֵĴ���

*/
void dfs(int sum, int n, int target, map<int, int>& mymap) {
	if (n == target) {
		mymap[sum]++;
		return;
	}
	for (int i = 1; i <= 6; ++i) {
		sum += i;
		dfs(sum, n + 1, target, mymap);
		sum -= i;
	}
}
vector<double> dicesProbability(int n) {
	map<int, int> mymap;
	dfs(0, 0, n, mymap);
	double len = 0;
	cout << mymap.size() << endl;
	for (auto iter : mymap) {
		cout << iter.first <<", "<<iter.second<<endl;
		len += iter.second;
	}
	vector<double> res(mymap.size());
	int idx = 0;
	for (auto iter : mymap) {
		res[idx++] = static_cast<double>(iter.second) / len;
	}

	return res;
}

//��ʱ
void test01()
{
	auto res = dicesProbability(4);
	//for (auto iter : res)
	//	cout << iter << " ";
	//cout << endl;

	//auto res = dicesProbability2(3);
	//for (auto iter : res)
	//	cout << iter << " ";
	//cout << endl;
}

/// <summary>
/// ���Ľⷨ,��̬�滮���
/// </summary>
/// <returns></returns>
///
/*
dp[i][j]����Ͷi������,ֵj���ֵİ�����

���һ��,dp[n][j]�������һ��Ͷ����,j�ܹ����ֵĴ���
����Ͷ��һ��,���һ��Ҳ��һ����,���ֵĵ���ֻ������1,2,3,4,5,6
��n��,j���ֵ��ܴ���,���Դ�Ͷ�ݵ�n-1ö���ӵõ�,���ԴӶ�Ӧ��j-1,j-2,j-3,...j-6���ֵĴ���֮��ת������

for(��nö���ӵĵ��� i=1;i<=6;++i) {
	dp[n][j] +=dp[n-1][j-i];
}
///����Ҫ��ֵ20���ֵĴ���,���Դ���һ��Ͷ����19,18,17,16,15,14�Ĵ���ת������
20=19+1,20=18+2,20=17+3,20=16+4,20=15+5,20=14+6

//�߽紦��
Ͷ�ݵ�һö����,���ֵ�ֵ��1,2,3,4,5,6,��������1��
for(int i=1;i<=6;++i) {
	dp[1][i]=1;
}

*/

vector<double> dicesProbability2(int n) {
	vector<vector<int> > dp(n + 1, vector<int>(6 * n + 1));

	for (int i = 1; i <= 6; ++i) {
		dp[1][i] = 1;//Ͷ��1�ε�ʱ��,1-6��������һ��
	}
	for (int i = 2; i <= n; ++i) {//��2�����ӵ�n������
		for (int j = 2; j < 6 * n + 1; ++j) {//���ܳ��ֵ�ֵ��2��6*n
			for (int k = 1; k <= 6; ++k) {//���ֵ�ֵ���Դ���һ��Ͷ�����ת����
				if (j - k < 1)
					break;
				if (j-k>=1)
					dp[i][j] += dp[i - 1][j - k];
			}
		}
	}//for i=2;

	vector<double> res;//һ������ô���Ԫ�س���,�ֱ�������
	res.reserve(6 * n + 1);
	int all_cnt = 0;
	all_cnt = accumulate(dp[n].begin(), dp[n].end(), 0);
	int res_idx = 0;//res������±�
	for (int i = 1; i <= 6 * n; ++i) {
		if (dp[n][i] != 0) {
			res.push_back(dp[n][i] / static_cast<double>(all_cnt));
		}
	}
	return res;

}
void test02()
{
	auto res = dicesProbability2(2);
	for (auto iter : res)
		cout << iter << " ";
	cout << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#endif