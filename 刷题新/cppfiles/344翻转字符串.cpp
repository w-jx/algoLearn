#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
void reverseString(vector<char>& s) {
	auto begin = s.begin();
	auto end = s.end() - 1;

	while (begin != end) {
		swap(*begin, *end);
		begin++;
		end--;
	}
}
void test01()
{

	
}
int main()
{
	system("pause");
	return 0;
}
#endif