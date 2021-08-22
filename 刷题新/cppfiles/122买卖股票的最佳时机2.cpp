#if 0
#include "../headers/wjxHeaders.h"

//̰���㷨
int maxProfit(vector<int>& prices) {
    enum STATE {
        BEGIN,
        UP,
        DOWN,
    };
    int state = STATE::BEGIN;
    int n = prices.size();
    int profit = 0;
    int min_prices = prices[0];
    for (int i = 1; i < n; ++i) {
        switch (state) {
        case BEGIN:
            if (prices[i] > prices[i - 1])
                state = UP;
            else if (prices[i] < prices[i - 1]) {
                state = DOWN;
                min_prices = prices[i];
            }
            break;
        case UP:
            if (prices[i] >= prices[i - 1])
                state = UP;
            else {
                state = DOWN;
                profit += prices[i - 1] - min_prices;
                min_prices = prices[i];
            }
            break;
        case DOWN:
            if (prices[i] > prices[i - 1])
                state = UP;
            else {
                min_prices = prices[i];
            }
            break;
        }
    }
    if (state == UP)
        profit += prices.back() - min_prices;
    return profit;
}

int maxProfit2(vector<int>& prices) {
    /*
    dp[i][0] ��ʾ��i�콻��������û�й�Ʊ,���������
    dp[i][1] ��ʾ��i�콻�����������һֻ��Ʊ,���������


     dp[i][0]:��i��û�й�Ʊ,��ô��i-1��,����û�й�Ʊdp[i-1][0]
        Ҳ�����й�Ʊ,dp[i-1][1],Ȼ��i������

     dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]+prices[i]

     dp[i][1],��i����й�Ʊ,��i-1��,����û�й�Ʊdp[i-1][0],��������Ҫ��
     ��i������;Ҳ�����й�Ʊ,dp[i-1][1]
     dp[i][1] = std::max(dp[i-1][1],dp[i-1][0]-prices[i])

     ��ʼ״̬:
     ��0�콻�׽���,dp[0][0]=0,��������й�Ʊ,����Ϊ0
     dp[0][1]=-prices[0],������й�Ʊ,�����Ʊ
    
    */
    int n = prices.size();
    int hold = -prices[0];//���й�Ʊ
    int nohold = 0;//û�г��й�Ʊ

    int curhold = -prices[0];//��ǰ���й�Ʊ
    int curnohold = 0;//��ǰû�г��й�Ʊ
    for (int i = 1; i < n; ++i) {
        curhold = std::max(hold, nohold - prices[i]);
        curnohold = std::max(hold + prices[i], nohold);
        hold = curhold;
        nohold = curnohold;
    }
    return std::max(hold, nohold);
}
void test01()
{

}
int main()
{
	test01();
}
#endif