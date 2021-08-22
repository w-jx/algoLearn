#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    if (len <= 1) return {};

    vector<int> vret(len, 1);
    int temp = 1;
    for (int i = 1; i < len; i++) {
        vret[i] = vret[i - 1] * a[i-1];
    }
   
    for (int i = len - 2; i >= 0; i--) {
        temp *= a[i + 1];
        vret[i] *= temp;
    }
    return vret;
}
void test01()
{
    vector<int> v{ 1,2,3,4,5 };
    printVector(constructArr(v));
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif