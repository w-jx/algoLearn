#if 0
#include "../headers/wjxHeaders.h"

/*
ԭ�����һ�α�������,��
1.��ǰ��С������۸�
2.����ά���������

*/
int maxProfit(vector<int>& prices) {
	int profit = 0;
	int minprice = prices[0];//��ʼ��ʱ����ͼ�����Ϊ��0���
	int n = prices.size();
	for (int i = 1; i < n; ++i) {
		//���ϸ����������۸�
		minprice = std::min(prices[i], minprice);
		//���ϸ�������
		profit = std::max(prices[i] - minprice, profit);
	}
	return profit;
}
void test01()
{

}
int main()
{
	test01();
}
#endif