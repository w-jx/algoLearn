#if false
#include "./headers/wjxHeaders.h"
//题解：https://leetcode-cn.com/problems/gas-station/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--30/
/*
1.暴力解法
考虑从第0个点出发，能否回到第0个点

暴力解法并没有超时
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	int remain = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;//从i开始往后遍历
		remain = gas[i];
		//看能否到达下一个点
		while (remain-cost[j]>=0) {
			//减去花费的
			remain -= cost[j];
			j = (j + 1) % n;
			if (j == i)//已经回到i了，说明成功了
				return i;
			remain += gas[j];//加上新点的补给
			
		}
	}
	return -1;
	
}

//改进版本
//就是记录每个点能到达的最远点，到达最远的剩下的汽油数也记下来
//其他点到达一个点，就不用重复算，就直接找能到哪儿，剩下多少汽油就彳亍了
int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	vector<int> farIndex(n,-1);
	vector<int> farremain(n, -1);

	for (int i = 0; i < n; ++i) {
		int j = i;//当前考虑第j个
		int remain = gas[i];
		while (remain - cost[j] >= 0) {
			remain -= cost[j];
			j = (j + 1) % n;
			if (farIndex[j] != -1) {
				//加上当时剩下的汽油
				remain += farremain[j];
				j = farIndex[j];
			}
			else {
				remain += gas[j];
			}
			if (j == i)
				return i;
		}
		farIndex[i] = j;
		farremain[i] = remain;
	}
	return -1;
}
/*
假设从i能最远到j ---》从i+1 到j 之间的节点不可能绕一圈
反证：
	假如i+1 的结点能绕一圈，意味着从i+1 一定能到j+1
	从i能到j，所以从i 一定也能到i+1，
	既然i能到i+1,那么i也就能到j+1,就和"i最远到j"矛盾了


所以如果i最远到j，从i+1到j之间的节点都不可能绕一圈，j也是不可以的
证明：
	加入j可以绕一圈，意味着j可以到j+1
	然后i可以最远到j，意味i也能到j+1====>矛盾
结论：如果i最远到j，那么我们下次直接从j+1考虑即可

*/
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int remain = 0, j = 0;
	for (int i = 0; i < n; ++i) {
		j = i;
		remain = gas[i];
		while (remain - cost[j] >= 0) {
			remain = remain - cost[j] + gas[(j + 1) % n];
			j = (j + 1) % n;
			if (j == i)
				return i;
		}
		if (j < i)//最远距离绕到了之前，i后面的都不可能绕一圈了
			return -1;
		i = j;//i到j，循环++i,相当于从j+1考虑
	}
	return -1;
}
void test01()
{

}
void main()
{
	test01();
}



#endif 