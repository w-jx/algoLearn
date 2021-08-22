#if 0
#include "../headers/wjxHeaders.h"




std::string removeKdigits(std::string num, int k)
{
	vector<int> s;//用vector模拟栈，因为可以遍历

	std::string res = "";//最后的结果

	for (int i = 0; i < num.size(); ++i) {
		int number = num[i] - '0';//将字符转成数字
		//栈里有元素，栈顶元素大于当前元素，K仍然大于0
		while (!s.empty() && s.back() > number && k > 0) {
			s.pop_back();//删除栈顶元素
			--k;
		}
		if (number != 0 || !s.empty()) {//不是0的时候，可以放心加入，但是如果是0，
			//要保证0不能做数字开头，所以栈要不为空才可以加入
			s.push_back(number);
		}
	}
	//12345 k=3这种情况，发现一个都没有删除  12最小的
	while (!s.empty() && k > 0) {
		s.pop_back();
		--k;
	}

	for (int i = 0; i < s.size(); ++i) {
		res.push_back(s[i] + '0');
	}
	if (res == "")
		res = "0";
	return res;
}
//2021年5月16日复习
string removeKdigits2(string nums, int k) {
	if (k <= 0)
		return nums;
	vector<int> mystack;
	mystack.push_back(nums[0] - '0');
	for (int i = 1; i < nums.size(); ++i) {
		int number = nums[i] - '0';
		if (!mystack.empty() && number >= mystack.back())
			mystack.push_back(number);
		else {

			while (k > 0 && !mystack.empty() && mystack.back() > number) {
				mystack.pop_back();
				--k;
			}
			if (!mystack.empty() || number != 0)
				mystack.push_back(number);
		}
	}//for
	while (k > 0 && !mystack.empty()) {
		mystack.pop_back();
		--k;
	}
	if (mystack.empty())
		return "0";
	string res;
	for (int i = 0; i < mystack.size(); ++i)
		res += mystack[i] + '0';
	return res;

}
void test01()
{
	string num("10");

	cout << removeKdigits2(num, 2) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif