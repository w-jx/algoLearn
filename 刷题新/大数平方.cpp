#if 1
#include "headers/wjxHeaders.h"


string getsquare(string _in)
{
	int n = _in.size();//�õ�����������ж���λ

	//�������ת����
	vector<int> in(n);
	for (int i = 0; i < n; ++i) {
		in[i] = _in[i] - '0';
	}
	vector<int> ret(2 * n);//�������

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			int num = in[i] * in[j];//�õ���Ӧλ�ĳ˻�
			ret[i + j + 1] += num % 10;
			if (ret[i + j + 1] > 9) {
				ret[i + j + 1] = ret[i + j + 1] % 10;//ȡ����
				ret[i + j] += 1;//��λ
			}
			ret[i + j] += num / 10;
			if (ret[i + j] > 9) {
				ret[i + j] = ret[i + j] % 10;
				ret[i + j - 1] += 1;
			}
		}
	}
	//ȥ��ǰ���0 
	int zeroidx = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (ret[i] == 0) {
			zeroidx++;
		}
		else {
			break;
		}
	}
	string res;
	for (int i = zeroidx; i < 2 * n; ++i) {
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

	for (int i = 1; i < 1000000; ++i) {
		double ret = stod(getsquare(to_string(i)));
		if (ret != pow(i, 2)) {
			cout << "error occured\n";
			break;
		}
	}
	system("pause");
	return 0;
}


#endif