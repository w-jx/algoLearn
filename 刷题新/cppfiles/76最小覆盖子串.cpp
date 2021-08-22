#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。


*/
//预备知识:字符哈希 来检查字符串s是否全部覆盖t

bool is_window_ok(vector<int>& map_s, vector<int>& map_t, vector<int>& vec_t)
{
	for (int i = 0; i < vec_t.size(); i++) {
		if (map_s[vec_t[i]] < map_t[vec_t[i]])
			return false;
	}
	return true;
}
/// <summary>
/// 检查字符串s 是否全部覆盖t,或者t里面的字符是否都在s中出现
/// </summary>
/// <param name="s"></param>
/// <param name="t"></param>
bool t_is_in_s(string s, string t)
{
	const int MAX_ARRAY_LEN = 128;//利用数组下标记录6
	vector<int> map_s(MAX_ARRAY_LEN, 0);//记录s和t字符串中
	vector<int> map_t(MAX_ARRAY_LEN, 0);//各个字符的个数

	vector<int> vec_t;//记录t 字符串中有哪些字符

	for (int i = 0; i < s.size(); i++) {
		map_s[s[i]]++;
	}
	for (int i = 0; i < t.size(); i++) {
		map_t[t[i]]++;
	}
	for (int i = 0; i < MAX_ARRAY_LEN; i++) {
		if (map_t[i] > 0) {
			vec_t.push_back(i);
		}
	}
	return is_window_ok(map_s, map_t, vec_t);
}
/// <summary>
/// 
/// </summary>
/// <param name="s"></param>
/// <param name="t"></param>
/// <returns>最小覆盖子串,否则返回""</returns>
string minWindow(string s, string t) {
	const int MAX_ARRAY_LEN = 128;//利用数组下标记录6
	vector<int> map_s(MAX_ARRAY_LEN, 0);//记录s和t字符串中
	vector<int> map_t(MAX_ARRAY_LEN, 0);//各个字符的个数
	vector<int> vec_t;//记录t 字符串中有哪些字符

	for (int i = 0; i < t.size(); i++) {
		map_t[t[i]]++;
	}
	for (int i = 0; i < MAX_ARRAY_LEN; i++) {
		if (map_t[i] > 0)
			vec_t.push_back(i);
	}

	//上面都是预备知识的内容
	int window_begin = 0;//最小窗口起始指针
	string res;//最小窗口对应的字符串
	for (int i = 0; i < s.size(); i++) {//i代表窗口的尾指针
		map_s[s[i]]++;//将尾指针指向的字符 添加到表示窗口的map中
		//窗口的 头指针不能超过 尾指针
		while (window_begin < i) {
			char begin_ch = s[window_begin];
			//如果当前头指针 指向的字符没有在字符串t中出现
			if (map_t[begin_ch] == 0) {
				++window_begin;
			}//头指针指向的字符出现在T中,窗口内有超过T中该字符个数的字符
			else if (map_s[begin_ch] > map_t[begin_ch]) {
				map_s[begin_ch]--;//头指针前移,因此指向的字符减少1个
				window_begin++;
			}
			else {
				break;
			}
		}//while
		//检查此时的窗口 是否包含字符串t 
		if (is_window_ok(map_s, map_t, vec_t)) {
			int new_window_len = i - window_begin + 1;
			if (res==""|| res.size() > new_window_len) {//替换窗口所对应的字符串
				res = s.substr(window_begin, new_window_len);
			}
		}
	}
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}
#endif