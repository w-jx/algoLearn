#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
int numLens(int val) {
	int lens = 0;
	while (val / 10 >= 1) {
		lens++;
		val /= 10;
	}
	lens++;
	return lens;

	/*while (val >= 0) {

		if (val / 10 >= 1) {
			lens++;
			val /= 10;
		}
		else {
			lens++;
			break;
		}

	}
	return lens;*/

}
int findNumbers(vector<int>& nums) {
	int times = 0;
	for (auto iter : nums) {
		if (iter < 10)
			continue;
		if (numLens(iter) % 2 == 0)
			times++;
	}

	return times;
}
void test01()
{
	vector<int> v = { 12,345,2,6,7896 };
	cout << findNumbers(v) << endl;




}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif