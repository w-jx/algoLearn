#if 0
#include "../headers/wjxHeaders.h"

/*
��������:
���������¥��-- - 70��д
��¥��:ÿ����1������2��,�����ж���n̨�׵ķ���
����:ÿ�ο�����coins�еķ���,�����ж���amount�ķ�����


�����������������
��¥�ݼ������������
���������������
������:
ǰk��Ӳ�Ҵճɽ��i�������=
    ǰk-1��Ӳ�Ҵճɽ��i�������+ǰk��Ӳ�Ҵճ�i-k�������
ֱ�׵�:Ҫ��k��Ӳ������ս��i�������
һ�����Ѿ���k-1��Ӳ���дճɵ������
һ��ǰ���Ѿ��ճ�i-k��,�Ͳ�k�˾��ܴճ�i��

״̬����dp[k][i]ǰk��Ӳ�Ҵճɽ��i�������
�������,���ǲ�����Ӳ��ʹ�õ�˳��,����Ӳ����û�б��õ�
�Ƿ�ʹ�õ�k��Ӳ����֮ǰ�����Ӱ��
״̬ת�Ʒ���
 ������������Ӳ��
    dp[k][i]=dp[k-1][i]+dp[k][i-k];
 ����:
    dp[k][i] = dp[k-1][i]

problem(k,i) = problem(k-1, i) + problem(k, i-k)
*/


//2021��7��5�ղ���д,�ٷ����,ͨ��
int change(int amount, vector<int>& coins) {
    //dp[i]������i�������
	vector<int> dp(amount + 1);
    dp[0] = 1;//���0,����Ӳ��,ֻ��һ�����
	//������coin
	for (const int& coin : coins) {
		for (int i = coin; i <= amount; ++i)
			dp[i] += dp[i - coin];
	}
	return dp[amount];
}
//��������ַ���Ϊʲô����ͨ��
/*
amount =3
coins = {1,2}

i=1,coin=1
dp[1] +=dp[1-coin]=1
i=1,coin=2,�ų�

i=2,coin=1
dp[2]+=dp[i-coin]
Ҳ����dp[2]+=dp[1] =1 ,Ŀǰ��1,1

i=2,coin=2
dp[2]+=dp[2-coin]
Ҳ����dp[2]+=dp[0]=2,{1,1},{2}

i=3,coin=1
dp[3]+=dp[i-coin]
Ҳ����dp[3]+=dp[2],dp[3]=2 ,{1,1,1},{2,1}

i=3,coin=2
dp[3]+=dp[i-coin]
Ҳ����dp[3]+=dp[1],dp[3]=3,{1,2}���Է����ظ��ĳ���

Ϊʲô�ٷ���ⲻ������ظ�:
dp[2]����1,2
dp[1]����1
��dp[3]��ʱ��,�õ���dp[2],����Ӳ��1,2
���õ���dp[1],����Ӳ��2,1

�ٷ����˼·�����µ�,coin�ǹ̶���,ÿ�α���һ��coin 
coin=1,i=1
dp[1]+=dp[i-coin]=1,{1}
coin=1,i=2
dp[2]+=dp[i-coin]
Ҳ����dp[2]+=dp[1]=1,{1,1}
dp[3]+=dp[i-coin]
Ҳ����dp[3]+=dp[2]=1,{1,1,1}
���Է������Ȱ�һ��Ӳ������ɵ����н����������

coin=2,i=2
dp[2]+=dp[i-coin]
Ҳ����dp[2]+=dp[0]=2,ԭ��{1,1},���ڶ��˸�{2}

coin=2,i=3
dp[3]+=dp[i-coin]
Ҳ����dp[3]+=dp[1],ԭ��{1,1,1},���˸�{1,2}
���Բ����ظ�  

*/
int change2(int amount, vector<int>& coins) {
    int n = coins.size();
    //dp[i]����i���ķ�������,dp[amount]
    vector<int> dp(amount + 1);
    dp[0] = 1;

    for (int i = 1; i <= amount; ++i) {//ö�ٽ��
        for (const int& coin : coins) {
            //ö�� ���
            if (i < coin) continue;
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}
/*
�����������������
��¥�ݼ������������
problem(k,i) = problem(k-1, i) + problem(k, i-k)
���������������
������:
ǰk��Ӳ�Ҵճɽ��i�������=
    ǰk-1��Ӳ�Ҵճɽ��i�������+ǰk��Ӳ�Ҵճ�i-k�������
ֱ�׵�:Ҫ��k��Ӳ������ս��i�������
һ�����Ѿ���k-1��Ӳ���дճɵ������
һ��ǰ���Ѿ��ճ�i-k��,�Ͳ�k�˾��ܴճ�i��

״̬����dp[k][i]ǰk��Ӳ�Ҵճɽ��i�������
�������,���ǲ�����Ӳ��ʹ�õ�˳��,����Ӳ����û�б��õ�
�Ƿ�ʹ�õ�k��Ӳ����֮ǰ�����Ӱ��
״̬ת�Ʒ���
 ������������Ӳ��
    dp[k][i]=dp[k-1][i]+dp[k][i-k];
 ����:
    dp[k][i] = dp[k-1][i]






*/
int change3(int amount, vector<int>& coins) {
    int n = coins.size();
    //dp[m][n]����ǰm��Ӳ��,��n���������
    vector<vector<int> > dp(n+1, vector<int>(amount + 1));
    //��ʼ������״̬
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;//ǰn����Ҵս��0,���ҽ���1�����
    }
    //����Ӳ��
    for (int i = 1; i <= n; ++i) {
        //ö�ٽ��
        for (int j = 1; j <= amount; ++j) {
            if (j >= coins[i - 1])//��ǰ������Ӳ������
                //��ǰi����Ҵճ���j-coins[i-1],����coins[i-1]����j
                //��ǰi-1������Ѿ��ճ�j,������������
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else//ǰi-1����Ҵճɽ��j�ķ�����,��i����Ҳ�����Ҫ��,���Ե�ǰ�ķ�����
                //��֮ǰi-1����ҵķ���������ͬ��
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][amount];
}
/*
��ά:
���ǹ۲���dp[i][*]ֻ��dp[i-1][*]��dp[i][#]�й�
  dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
  dp[i][j] = dp[i - 1][j];


  dp[i]�������Ǳ���ʹ�õ�k����ҵ�ʱ��,�ܴճɵ�ǰ���i�������
��`
  dp[i]=dp[i]+dp[i-k]

*/
void test01()
{

}
int main()
{
	test01();
}
#endif