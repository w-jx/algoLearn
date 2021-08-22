#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

vector<int> getLeastNumbers(vector<int>& arr, int k) {
	int n = arr.size();
	if (n == 0 || k == 0)
		return {};
	if (n == k)
		return arr;
	make_heap(arr.begin(), arr.end(), std::greater<int>());
	vector<int> vret;
	for (int i = 0; i < k; i++) {
		vret.push_back(arr.front());
		pop_heap(arr.begin(), arr.end() - i - 1, greater<int>());
	}
	return vret;
}
void test01()
{
	vector<int> vin{ 0,0,2,0,1,1,1,7,3,3,1,3,2,3,7,12,0,10,16,8,3,13,20,4,9,14,16,18,12,1,21,17,3,22,18,15,16,1,3,35,25,33,7,30,41,3,18,10,34,0,33,51,18,26,16,9,0,2,19,53,53,59,53,34,5,3,51,56,12,37,32,3,63,65,15,70,54,4,68,8,66,5,80,0,36,49,50,25,19,42,49,41,30,44,59,74,55,7,33,44 };
	vector<int> vret{ 0,0,0,0,0,0,0,1,1,1,1,1,1,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,5,5,7,7,7,7,8,8,9,9,10,10,12,12,12,13,14,15,15,16,16,16,16,17,18,18,18,18,19,19,20,21,22,25,25,26,30,30,32,33,33,33,34,34,35,36,37,41,41,42,44,44,49,49,50,51,51,53,53,53,54,55,56 };
	cout << vin.size() << endl;
	printVector(vret);
	printVector(getLeastNumbers(vin, 91));
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif