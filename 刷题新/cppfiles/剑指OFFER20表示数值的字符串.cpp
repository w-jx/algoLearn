#if 0
#include "../headers/wjxHeaders.h"
#include <sstream>
/*
leecode��Ŀ����:


*/
//�ҵĽⷨͨ����һЩ��������,���ǻ����б߽����û�п��ǵ�
/*
".1"  true

*/
bool isNumber(string str) {

	int n = str.size(), i = 0;
	for (; i < n; ++i) {
		if (str[i] != ' ')
			break;
	}
	if (i == n)
		return false;
	if (str[i] == '+' || str[i] == '-')
		++i;
	bool hasdot = false;//�Ƿ��Ѿ�����С��
	bool hasnum = false;
	bool hase = false;
	bool hasoperator = false;
	for (; i < n; ++i) {
		if (str[i] >= '0' && str[i] <= '9')
			hasnum = true;
		else if (str[i] == '.') {
			if (hasdot || hase || !hasnum)//�Ѿ�����С����,������С��������
				return false;//ǰ����e�����,������С����
			hasdot = true;
			hasnum = false;

		}
		else if (str[i] == 'e' || str[i] == 'E') {
			if (!hasnum || hase)//eǰ��Ҫ������,����e����������e
				return false;
			hase = true;
		}
		else if (str[i] == '+') {
			if (!hase || hasoperator)
				return false;
			hasoperator = true;
		}
		else if (str[i] == '-' || str[i] == '.') {
			if (!hase || hasoperator || hasdot)
				return false;
			hasoperator = true;
		}

	}
	return hasnum;
}
/*
���ȶ������ĸ�flag����Ӧ�����ַ�
�Ƿ������֣�hasNum
�Ƿ���e��hasE
�Ƿ����������ţ�hasSign
�Ƿ��е㣺hasDot
���໹�������ַ�������n�Լ��ַ�������index
�ȴ���һ�¿�ͷ�Ŀո�index��Ӧ�ĺ���
Ȼ�����ѭ���������ַ���
�����ǰ�ַ�c�����֣���hasNum��Ϊtrue��index�����ƶ�һֱ�������ֻ������ĩβλ�ã�����ѱ�����ĩβ(index == n)������ѭ��

�����ǰ�ַ�c��'e'��'E'�����e�Ѿ����ֻ��ߵ�ǰe֮ǰû�г��ֹ����֣�����fasle��
������hasE = true�����ҽ�����3��flagȫ����Ϊfalse����ΪҪ��ʼ����e�������������

�����ǰ�ַ�c��+��-������Ѿ����ֹ�+��-�����Ѿ����ֹ����ֻ����Ѿ����ֹ�'.'������flase��������hasSign = true

�����ǰ�ַ�c��'.'������Ѿ����ֹ�'.'�����Ѿ����ֹ�'e'��'E'������false��������hasDot = true

�����ǰ�ַ�c��' '������ѭ������Ϊ������ĩβ�Ŀո��ˣ���Ҳ�п������ַ����м�Ŀո���ѭ�����������

�����ǰ�ַ�c�ǳ�������5���������������ַ���ֱ�ӷ���false

����ո�index��Ӧ�ĺ���

�����ǰ����index���ַ���������ȣ�˵����������ĩβ�����ǻ�Ҫ����hasNumΪtrue�ſ������շ���true��
��Ϊ����ַ�����ȫ�Ƿ���û�����ֵĻ��ǲ��еģ�����e����û������Ҳ�ǲ��еģ�����û�з����ǿ��Եģ�
����4��flag��ֻҪ�ж�һ��hasNum���У�������󷵻ص���hasNum && index == n

����ַ����м��пո񣬰�����˼·���޷�������ĩβ�ģ�index������n��ȣ����صľ���false

*/
bool isNumber2(string str) {
	int idx = 0;
	int n = str.size();
	while (str[idx] == ' ')++idx;
	if (idx == n)
		return false;
	bool hasNum = false;
	bool hasE = false;
	bool hasOperator = false;
	bool hasDot = false;

	while (idx < n) {
		while (idx < n && isdigit(str[idx]) != 0) {
			hasNum = true;
			++idx;
		}
		if (idx == n)
			break;
		if (str[idx] == 'e' || str[idx] == 'E') {
			if (hasE || !hasNum)//�Ѿ���e,����ǰ��û������
				return false;
			hasE = true;
			hasNum = false;//��ΪҪ��ʼ����e�������������
			hasOperator = false;
			hasDot = false;
		}
		else if (str[idx] == '.') {
			//�Ѿ�����e,�Ѿ�����С����
			if (hasE || hasDot)
				return false;
			hasDot = true;
		}
		else if (str[idx] == '+' || str[idx] == '-') {
			//�Ѿ���������,�Ѿ�����С����,�Ѿ����������
			if (hasDot || hasOperator||hasNum)
				return false;
			hasOperator = true;
		}
		else if (str[idx] == ' ') {
			break;//������ĩβ�ո�,Ҳ�������м�ո�,��ѭ�����洦��
		}
		else//��������,ֱ�ӷ���false
			return false;
		++idx;
	}
	while (idx < n && str[idx] == ' ')
		++idx;
	return idx == n && hasNum;
}
void test01()
{
	//cout << isNumber(".1") << endl;

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif