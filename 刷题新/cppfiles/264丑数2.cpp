#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

//这个方法超时了
int nthUglyNumber(int n) {
	if (n < 7)
		return n;
	int cnt = 6, num = 8;
	while (true) {
		int tempnum = num;
		while (num % 2 == 0)
			num /= 2;
		while (num % 3 == 0)
			num /= 3;
		while (num % 5 == 0)
			num /= 5;
		if (num == 1) {
			cout << tempnum << endl;
			++cnt;
		}

		num = tempnum;
		if (cnt == n) {
			break;
		}
		++num;
	}
	return num;
}

bool isugly(int& num, set<int>& myset) {
	if (num % 2 == 0)
		return myset.find(num / 2) != myset.end();
	else if (num % 3 == 0)
		return myset.find(num / 3) != myset.end();
	else if (num % 5 == 0)
		return myset.find(num / 5) != myset.end();
	return false;
}
//仍然超时
int nthUglyNumber2(int n) {
	if (n < 7)
		return n;
	set<int> myset;
	for (int i = 1; i < 7; ++i)
		myset.insert(i);//1,2,3,4,5,6都是丑数

	int cnt = 6, num = 7, retnum = 0;
	while (cnt <= n) {
		++num;
		if (isugly(num, myset)) {
			cout << num << endl;
			retnum = num;
			++cnt;
			myset.insert(num);
		}
	}
	return retnum;

}
void test01()
{
	cout << nthUglyNumber2(20) << endl;
}
//官方题解 最小堆的方法
int nthUglyNumber3(int n) {
	priority_queue<long, vector<long>, greater<long>> que;
	que.push(1);
	//第n个丑数,例如第10个,如果是数组num[11],n是从1开始计数的
	//我们从下标0想到得到下标11,所以idx<n+2
	int idx = 1;
	long num = que.top();
	unordered_set<long> myset;//因为可能有重复的,所以去重
	myset.insert(1);
	while (idx < n) {
		num = que.top();
		if (myset.find(num * 2) == myset.end()) {
			que.push(num * 2);
			myset.insert(num * 2);

		}

		if (myset.find(num * 3) == myset.end()) {
			que.push(num * 3);
			myset.insert(num * 3);
		}

		if (myset.find(num * 5) == myset.end()) {
			que.push(num * 5);
			myset.insert(num * 5);
		}

		que.pop();

		++idx;
	}

	return que.top();
}
int nthUglyNumber4(int n) {
	vector<int> dp(n + 1);
	dp[1] = 1;
	/*p2,p3,p5实际上本质是数组下标
	* 当前数组只有下标1为1,代表第一个丑数是1,
	* dp[i] = dp[j]*2,dp[j]*3,dp[j]*5,j<i
	*
	*
	*/
	int p2 = 1, p3 = 1, p5 = 1;
	for (int i = 2; i <= n; ++i) {
		int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
		dp[i] = std::min({ num2, num3, num5 });
		//找到当前的这个丑数,是哪一个丑数得到的
		//也就是✖2,✖3,✖5的哪一个,是num2,num3,num5
		//如果是✖2的,那么dp[p2]下一个丑数不应该再✖2了,否则就重复了,所以p2前进
		// 换句话说,下一次求num2=dp[p2]*2,当前num2已经被取了,因此下面再求
		// num2,dp[p2]*2,就会出现重复,因此p2应该前进一位
		// 
		// 同理
		//如果是✖3的,也就是当前的dp[i]=num3,下次再求num3=dp[p3]*3,出现重复了
		//因此应该p3前进一个
		if (dp[i] == num2)
			++p2;
		if (dp[i] == num3)
			++p3;
		if (dp[i] == num5)
			++p5;
	}
	return dp[n];
}
//2021年5月20日复习,不会写
int nthUglyNumber5(int n) {
	if (n < 7)
		return n;
	vector<int> dp(n + 1, -1);
	for (int i = 0; i < 7; ++i)
		dp[i] = i;
	for (int i = 7; i <= n; ++i) {
		int start = dp[i - 1] + 1;
		while (dp[i] == -1) {
			if (start % 2 == 0 && dp[start / 2] != -1)
				dp[i] = start;
			else if (start % 5 == 0 && dp[start / 5] != -1)
				dp[i] = start;
			else if (start % 3 == 0 && dp[start / 3] != -1)
				dp[i] = start;

			++start;
		}
	}
	return dp[n];
}
//2021年6月9日复习,不会写
int nthUglyNumber6(int n) {
	vector<int>dp(n);
	dp[0] = 1;
	int p2 = 0, p3 = 0, p5 = 0;
	
	for (int i = 1; i < n; ++i) {
		int num2 = dp[p2] * 2;
		int num3 = dp[p3] * 3;
		int num5 = dp[p5] * 5;
		dp[i] = std::min({ num2,num3,num5 });
		//下面不能改成If,elseif,因为要去重复的
		if (dp[i] == num2)
			++p2;
		if (dp[i] == num3)
			++p3;
		if (dp[i] == num5)
			++p5;
	}
	return dp[n - 1];
}

void test03()
{
	//cout << nthUglyNumber5(10) << endl;

	//int x = std::min({ 1,2,3,4,5 });//无限个最小值比较
	//cout << x << endl;

	//vector<int> nums{};
	//auto iter= min_element(nums.begin(), nums.end());
	//cout << *iter << endl;

	//auto iter = std::min(nums.begin(), nums.end());
	//if (iter == nums.end())
	//	cout << "empty\n";


}
int main()

{
	//test01();
	test03();
	system("pause");
	return 0;
}
#endif