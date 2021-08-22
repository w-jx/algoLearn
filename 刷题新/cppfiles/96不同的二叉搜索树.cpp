
#if 0
#include "../headers/wjxHeaders.h"

/*
G(n)����n������ܹ���Ķ���������������
F(i,n)������iΪ������ܹ���Ķ��������������� 

��ôG(n)=F(1,n)+F(2,n)+...+F(n,n)

F(i,n)��iΪ��,[1,i-1]Ϊ������,[i+1,n]������
�ֱ�ȷ�����������ܹ�������ֶ���������
F(i,n)=Fleft*Fright=G(i-1)*G(n-i)

G(n) =1-n::G(i-1)*G(n-i)= G(0)*G(n-1)+G(1)*G(n-2)+...G(n-1)*G(0)

*/
//�����
int numTrees(int n) {
    vector<int> dp(n + 1);//�����ܹ���Ķ���������������
    dp[0] = 0;
    dp[1] = 1;
    //i������ڼ������ֹ���Ķ���������������
    for (int i = 2; i <= n; ++i) {
        for (int k = 1; k <= i; ++k) {
            dp[i] += dp[k - 1] * dp[n - k];
        }
    }
    return dp[n];

}
//leetcode д��
int numTrees2(int n) {
    vector<int> dp(n + 1);
    /*
    dp[n]����n������ܹ���ɵĲ�ͬ����������
    dp[n]�ĸ������Դ�1-n
    dp[n]=f(1,n)+f(2,n)+..f(n,n);
    ��iΪ��,��������1,i-1,��i-1��,�����dp[i-1]��
    ������i+1,n,һ��n-i��,�����dp[n-i]��

    dp[n]=dp[1-1]*dp[n-1]+dp[2-1]*dp[n-2]+...dp[n-1]*dp[n-n];
    */
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
void test01()
{
    cout << numTrees2(3) << endl;

}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif