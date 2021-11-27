#if 1
#include "../headers/wjxHeaders.h"


string getsquare(string _in)
{
	int n = _in.size();//得到输入的数字有多少位

	//把输入的每一位数字 存放在数组中
	vector<int> in(n);
	for (int i = 0; i < n; ++i) {
		in[i] = _in[i] - '0';
	}
	vector<int> ret(2 * n+1);//结果数组

	for (int i = n; i >= 1; --i) {
		for (int j = n; j >= 1; --j) {
			int num = in[i-1] * in[j-1];//得到对应位的乘积
			ret[i + j] += num % 10;
			if (ret[i + j ] > 9) {
				ret[i + j -1] += ret[i + j] / 10;//进位
				ret[i + j]%=10;//取余
			}
			ret[i + j-1] += num / 10;//加进位
			if (ret[i + j-1] > 9) {
				ret[i + j-2] += ret[i + j-1] / 10;
				ret[i + j - 1]%=10;
			}
		}
	}
	//去除前面的0 
	int zeroidx = 0;
	for (int i = 0; i < 2 * n+1; ++i) {
		if (ret[i] == 0) {
			zeroidx++;
		}
		else {
			break;
		}
	}
	string res;
	for (int i = zeroidx; i < 2 * n+1; ++i) {
		res += ret[i] + '0';
	}
	return res;
}

void test01()
{

}
int main()
{
	//cout << "square:" << pow(100, 2) << endl;
	//cout << "square:" << getsquare(to_string(100)) << endl;

	for (int i = 1; i < 19; ++i) {
		double ret = stod(getsquare(to_string(i)));
		if (ret != pow(i, 2)) {
			cout << "error occured\n";
			break;
		}
	}
	
	return 0;
}


#endif