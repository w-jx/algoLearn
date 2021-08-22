#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
1.˼·1 ��������
ÿ10�����뵽hash�У����Ѵ�������2�������
�����ܼ�

2.����2
00 01 10 11 �ֱ������������A C G T ���԰�key�ĳ� �������������ַ���

2^20  һ������2λ��һ��10������ ������20�� 1048576


*/
//���� 1
vector<string> findRepeatedDnaSequences(string s) {
	if (s.size() < 10)
		return {};
	map<string, int> strmap;
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		j = i + 10;
		if (j > s.size())
			break;
		string str;
		for (int k = i; k < j; k++)
			str.push_back(s[k]);
		if (strmap.find(str) == strmap.end())
			strmap.insert({ str,1 });
		else
			strmap[str]++;
	}
	vector<string> ret;
	for (auto iter : strmap) {
		if (iter.second > 1)
			ret.push_back(iter.first);
	}
	return ret;
}
int g_hash_map[1048576] = { 0 };
vector<int> g_hash_map_v(1048576, 0);
int len = 1048576;

string int_to_string(int DNA)
{
	static const char DNA_CHAR[] = { 'A','C','G','T' };
	std::string str;
	for (int i = 0; i < 10; i++) {
		str += DNA_CHAR[DNA & 3];//
		//DNA = DNA / 10;
		DNA = DNA >> 2;//�൱��/4
	}
	return str;
}
//����2 
vector<string> findRepeatedDnaSequences2(string s) {
	if (s.size() < 10)
		return {};
	vector<string> ret;//����
	g_hash_map_v.clear();
	g_hash_map_v.resize(len);
	//ÿ�ε��õ�ʱ�����ȫ������
	int char_map[128] = { 0 };
	char_map['A'] = 0;
	char_map['C'] = 1;
	char_map['G'] = 2;
	char_map['T'] = 3;//�ַ���������ת������

	int key = 0;
	//�������������λ
	for (int i = 9; i >= 0; i--) {
		//key = key * 10 + char_map[s[i]];//����൱����4����,���Բ���*10,����*4
		key = (key << 2) + char_map[s[i]];//����Ϊ���û��<<2 ,�ͳ�����
	}//��DNA �ַ�����ǰ10��10�ַ� ת��
	g_hash_map_v[key] = 1;

	for (int i = 10; i < s.size(); i++) {
		key = key >> 2;//ɾ�����λ
		//key = key*10+ char_map[s[i]];
		key = key | (char_map[s[i]] << 18);//��ֵ�����λ
		g_hash_map_v[key]++;
	}
	for (int i = 0; i < 1048576; i++) {
		if (g_hash_map_v[i] > 1) {
			ret.push_back(int_to_string(i));
		}
	}

	return ret;
}
void test01()
{
	string s("AAAAAAAAAAA");
	auto ret = findRepeatedDnaSequences(s);

	for (auto iter : ret)
		cout << iter << endl;

}
//key ����
void test02()
{
	//int a = 5232;//0001 0100 0111 0000
	//a = a >> 2;
	//cout << a << endl;//1308  0101 0001 1100

	string str("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	auto ret = findRepeatedDnaSequences2(str);
	for (auto iter : ret)
		cout << iter << endl;
}
//2021��5��14�ո�ϰ
vector<string> findRepeatedDnaSequences3(string s) {
	if (s.size() < 10)
		return {};
	int n = s.size();

	unordered_map<string,int> mymap;
	vector<string> res;
	int j = 0;
	for (int i = 0; i <n-10+1; i++) {
		string temp(s.begin() + i, s.begin() + i + 10);
		if (mymap.find(temp) == mymap.end())
			mymap.insert({ temp,1 });
		else
			mymap[temp]++;
		
	}
	for (auto str : mymap) {
		if (str.second > 1)
			res.push_back(str.first);
	}
	
	return res;
}
void test03()
{
	//int a = 5232;//0001 0100 0111 0000
	//a = a >> 2;
	//cout << a << endl;//1308  0101 0001 1100

	string str("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	auto ret = findRepeatedDnaSequences3(str);
	for (auto iter : ret)
		cout << iter << endl;
}
int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}
#endif