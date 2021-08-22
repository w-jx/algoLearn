#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/
//"Let's take LeetCode contest"
string reverseWords(string s) {
	
	string stemp="";
	
	size_t size = s.size();
	stemp.resize(size);
	auto iter = 0;
	int num = 0;
	for (size_t i = 0; i < size; i++) {
		if (s[i] != ' ') {
			
			stemp.insert(iter, 1,s[i]);
			num++;
		}
		
		else {
			stemp.insert(num++,1,' ');
			iter = num;
		}
			
			
	}
	return stemp;
}
void test01()
{
	string s = "Let's take LeetCode contest";
	//"s'teL ekat edoCteeL tsetnoc"
	cout << reverseWords(s) << endl;
	
	/*string stemp = "";
	stemp.insert(0,  1,'l');
	cout << stemp << endl;*/
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif