#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
bool wordPattern(string pattern, string s) {
	std::map<string, char> word_map;//���ʵ�pattern�ַ� ��ӳ��
	char used[128] = { 0 };//�ѱ�ӳ����ַ�

	string word;//��ʱ�����ֳ��ĵ���
	int pos = 0;//pattern �±�
	s.push_back(' ');//�����ո�Ͳ�ֵ��ʣ������Ͳ��ö����һ���������⴦��

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {//�����ո񣬲�ֵ���
			if (pos == pattern.size()) {//���ָ��һ�����ʣ�����û��pattern�ַ���
				//���Ӧ
				return false;
			}
			//�������û�г����ڹ�ϣӳ����
			if (word_map.find(word) == word_map.end()) {
				if (used[pattern[pos]] == 1)//�����ǰpattern�ַ��Ѿ�ʹ��
					return false;
				word_map[word] = pattern[pos];
				used[pattern[pos]] = 1;
			}
			else {//�����ǳ����ڹ�ϣӳ���е�
				if (word_map[word] != pattern[pos])//��ǰ�ѽ�����ӳ�� ���ܺ͵�ǰpattern��Ӧ
					return false;
			}
			word = "";
			pos++;
		}
		else {
			word += s[i];
		}
	}
	if (pos != pattern.size())
		return false;//�ж����pattern�ַ�
	return true;


}
//��ϰ������ⷨ ��Ȼ�����ٷ�֮��???
bool wordPattern2(string pattern, string s) {

	stringstream ss(s);
	unordered_map<string, char> pattern2s;
	unordered_map<char, string> s2pattern;
	vector<string> str_vec;
	while (getline(ss, s, ' '))
		str_vec.push_back(s);
	if (pattern.size() != str_vec.size())
		return false;
	int n = pattern.size();
	for (int i = 0; i < n; ++i) {
		if (s2pattern.find(pattern[i]) == s2pattern.end()) {
			s2pattern.insert({ pattern[i],str_vec[i] });
		}
		else {
			if (s2pattern[pattern[i]] != str_vec[i])
				return false;
		}
		if (pattern2s.find(str_vec[i]) == pattern2s.end()) {
			pattern2s.insert({ str_vec[i],pattern[i] });
		}
		else {
			if (pattern2s[str_vec[i]] != pattern[i])
				return false;
		}
	}
	return true;
}
//���Խ�Լһ��map,��128�ֽڴ�С���ַ��������
bool wordPattern3(string pattern, string s) {

	stringstream ss(s);
	unordered_map<string, char> pattern2s;
	char s2pattern[128] = { 0 };
	vector<string> str_vec;
	while (getline(ss, s, ' '))
		str_vec.push_back(s);
	if (pattern.size() != str_vec.size())
		return false;

	int n = pattern.size();

	for (int i = 0; i < n; ++i) {
		if (pattern2s.find(str_vec[i]) == pattern2s.end()) {
			if (s2pattern[pattern[i]] == 1)
				return false;
			pattern2s.insert({ str_vec[i],pattern[i] });
			s2pattern[pattern[i]] = 1;
		}
		else {

			if (pattern2s[str_vec[i]] != pattern[i])
				return false;

		}
	}
	return true;
}
void test01()
{
	string pattern("abba"), str("dog cat cat dog");
	cout << wordPattern2(pattern, str) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif