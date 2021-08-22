#if 0
#include <iostream>
#include <list>
using namespace std;
/*
leecodeÌâÄ¿½éÉÜ:


*/
int lastRemaining(int n, int m) {


    list<int> l;
    for (int i = 0; i < n; i++) {
        l.push_back(i);
    }
    auto iter = l.begin();
    int index = 0;
    for (int k = 0; k < n; k++) {
        index++;
        if (index == m) {
            iter = l.erase(iter);
            index = 0;
        }
        if (l.size() == 1)
            break;
    }
    return l.front();
}
void test01()
{
    cout << lastRemaining(5, 3);
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif