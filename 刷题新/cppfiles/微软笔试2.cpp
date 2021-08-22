#if 0
#include "../headers/wjxHeaders.h"
#include <string>
/*
leecodeÌâÄ¿½éÉÜ:


*/
bool isSame(int first, int second)
{
	int x = first ^ second;
	int y = x;
	
	int count = 0;
	while (x != 0) {
		count += x & 1;
		x = x >> 1;
	}
	//cout << first << "," << second << "," << y <<","<<count<< endl;
	return count <= 1;
}
int getNum(string str) {
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		ans = (ans << 1) + str[i] - '0';
	}
	return ans;
}
vector<int> solution(vector<string>& cars) {
	// write your code in C++14 (g++ 6.2.0)
	vector<int> carsint(cars.size());
	int i = 0;
	for (auto iter : cars) {
		carsint[i++] = getNum(iter);
	}
	
	vector<int> ans(cars.size(), -1);
	for (int i = 0; i < cars.size(); i++) {
		for (int j = 0; j < cars.size(); j++) {
			ans[i] += isSame(carsint[i], carsint[j]);
		}
	}
	return ans;


}
void test01()
{
	vector<string> cars{ "100", "110", "010", "011", "100" };
	auto ret = solution(cars);
	for (auto iter : ret)
		cout << iter << " ";
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif