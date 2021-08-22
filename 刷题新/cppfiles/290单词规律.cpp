#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
bool wordPattern(string pattern, string s) {
	std::map<string, char> word_map;//单词到pattern字符 的映射
	char used[128] = { 0 };//已被映射的字符

	string word;//临时保存拆分出的单词
	int pos = 0;//pattern 下标
	s.push_back(' ');//遇到空格就拆分单词，这样就不用对最后一个单词特殊处理

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {//遇到空格，拆分单词
			if (pos == pattern.size()) {//若分割出一个单词，但是没有pattern字符和
				//其对应
				return false;
			}
			//如果单词没有出现在哈希映射中
			if (word_map.find(word) == word_map.end()) {
				if (used[pattern[pos]] == 1)//如果当前pattern字符已经使用
					return false;
				word_map[word] = pattern[pos];
				used[pattern[pos]] = 1;
			}
			else {//单词是出现在哈希映射中的
				if (word_map[word] != pattern[pos])//当前已建立的映射 不能和当前pattern对应
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
		return false;//有多余的pattern字符
	return true;


}
//复习的拉跨解法 依然超过百分之百???
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
//尝试节约一个map,用128字节大小的字符数组替代
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