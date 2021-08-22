#if 0
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void getnum(int n)
{
	vector<int> v;
	while (n >= 10) {
		auto temp = n % 10;
		v.push_back(temp);
		n =n/10;
	}
	v.push_back(n);
	auto iter = v.end() - 1;
	for (auto iter = v.end() - 1; iter >= v.begin(); iter--) {
		cout << *iter << " ";
		if (iter == v.begin())
			break;
	}
		
	cout << endl;
}
int get_square_value(int n)
{
	int sum = 0;
	while (n >= 10) {
		auto temp = n % 10;
		sum += temp * temp;
		n = n / 10;
	}
	sum += n * n;
	return sum;
}

bool isHappy(int n)
{
	unordered_set<int> hashset;
	while (1) {
		int value = get_square_value(n);
		if (value == 1)
			return true;
		if (hashset.count(value) > 0)
			return false;
		hashset.insert(value);
		n = value;
		
	}
	return true;
}
void test01()
{
	
}
int main(void)
{
	test01();
	system("pause");
	return 0;
}
#endif