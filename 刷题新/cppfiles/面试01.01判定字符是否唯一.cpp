#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
bool isUnique(string astr) {
	

	size_t i = astr.size();
	for (auto index = 0; index < i; index++) {
		if (i - index - 1 == 0)
			break;
		int result = astr.substr(index+1 , i - index - 1).find(astr[index]);
		if (result != -1)
			return false;
	}
	return true;

}
void test01()
{
	string s = "abcdevia";
	cout << isUnique(s) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif