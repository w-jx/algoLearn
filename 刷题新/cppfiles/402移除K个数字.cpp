#if 0
#include "../headers/wjxHeaders.h"




std::string removeKdigits(std::string num, int k)
{
	vector<int> s;//��vectorģ��ջ����Ϊ���Ա���

	std::string res = "";//���Ľ��

	for (int i = 0; i < num.size(); ++i) {
		int number = num[i] - '0';//���ַ�ת������
		//ջ����Ԫ�أ�ջ��Ԫ�ش��ڵ�ǰԪ�أ�K��Ȼ����0
		while (!s.empty() && s.back() > number && k > 0) {
			s.pop_back();//ɾ��ջ��Ԫ��
			--k;
		}
		if (number != 0 || !s.empty()) {//����0��ʱ�򣬿��Է��ļ��룬���������0��
			//Ҫ��֤0���������ֿ�ͷ������ջҪ��Ϊ�ղſ��Լ���
			s.push_back(number);
		}
	}
	//12345 k=3�������������һ����û��ɾ��  12��С��
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
//2021��5��16�ո�ϰ
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