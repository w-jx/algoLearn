#if 0
#include "../headers/wjxHeaders.h"

//贪心算法
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
    dp[i][0] 表示第i天交易完手里没有股票,的最大利润
    dp[i][1] 表示第i天交易完手里持有一只股票,的最大利润


     dp[i][0]:第i天没有股票,那么第i-1天,可能没有股票dp[i-1][0]
        也可能有股票,dp[i-1][1],然后i天卖出

     dp[i][0]=std::max(dp[i-1][0],dp[i-1][1]+prices[i]

     dp[i][1],第i天持有股票,第i-1天,可能没有股票dp[i-1][0],所以我们要在
     第i天买入;也可能有股票,dp[i-1][1]
     dp[i][1] = std::max(dp[i-1][1],dp[i-1][0]-prices[i])

     初始状态:
     第0天交易结束,dp[0][0]=0,如果不持有股票,利润为0
     dp[0][1]=-prices[0],如果持有股票,买入股票
    
    */
    int n = prices.size();
    int hold = -prices[0];//持有股票
    int nohold = 0;//没有持有股票

    int curhold = -prices[0];//当前持有股票
    int curnohold = 0;//当前没有持有股票
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