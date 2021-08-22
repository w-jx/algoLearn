#if 0
#include "../headers/wjxHeaders.h"

/*
闰年的判断:
能被4整除,且不能被100整除或者被400整除

*/
int dayOfYear(string date) {
	string str;
	vector<int> ymd;
	stringstream ss(date);

	while (getline(ss, str, '-')) {
		ymd.push_back(stoi(str));
	}
	std::array<int, 13> days;
	days.fill(30);
	
	days[1] = days[3] = days[5] = days[7] = days[8] = days[10] = days[12] = 31;
	//能被4整除且不能被100整除   或者被400整除
	if ((ymd[0] % 4 == 0 && ymd[0] % 100 != 0) || ymd[0] % 400 == 0)
		days[2] = 29;
	else
		days[2] = 28;
	int ret = 0;
	for (int i = 1; i < ymd[1]; ++i) {
		ret+= days[i];
	}
	ret += ymd[2];
	return ret;
}
void test01()
{
	string str = "2008-10-10";
	cout << dayOfYear(str) << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif