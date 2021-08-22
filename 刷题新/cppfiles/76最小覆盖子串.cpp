#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��

ע�⣺��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�


*/
//Ԥ��֪ʶ:�ַ���ϣ ������ַ���s�Ƿ�ȫ������t

bool is_window_ok(vector<int>& map_s, vector<int>& map_t, vector<int>& vec_t)
{
	for (int i = 0; i < vec_t.size(); i++) {
		if (map_s[vec_t[i]] < map_t[vec_t[i]])
			return false;
	}
	return true;
}
/// <summary>
/// ����ַ���s �Ƿ�ȫ������t,����t������ַ��Ƿ���s�г���
/// </summary>
/// <param name="s"></param>
/// <param name="t"></param>
bool t_is_in_s(string s, string t)
{
	const int MAX_ARRAY_LEN = 128;//���������±��¼6
	vector<int> map_s(MAX_ARRAY_LEN, 0);//��¼s��t�ַ�����
	vector<int> map_t(MAX_ARRAY_LEN, 0);//�����ַ��ĸ���

	vector<int> vec_t;//��¼t �ַ���������Щ�ַ�

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
/// <returns>��С�����Ӵ�,���򷵻�""</returns>
string minWindow(string s, string t) {
	const int MAX_ARRAY_LEN = 128;//���������±��¼6
	vector<int> map_s(MAX_ARRAY_LEN, 0);//��¼s��t�ַ�����
	vector<int> map_t(MAX_ARRAY_LEN, 0);//�����ַ��ĸ���
	vector<int> vec_t;//��¼t �ַ���������Щ�ַ�

	for (int i = 0; i < t.size(); i++) {
		map_t[t[i]]++;
	}
	for (int i = 0; i < MAX_ARRAY_LEN; i++) {
		if (map_t[i] > 0)
			vec_t.push_back(i);
	}

	//���涼��Ԥ��֪ʶ������
	int window_begin = 0;//��С������ʼָ��
	string res;//��С���ڶ�Ӧ���ַ���
	for (int i = 0; i < s.size(); i++) {//i�����ڵ�βָ��
		map_s[s[i]]++;//��βָ��ָ����ַ� ��ӵ���ʾ���ڵ�map��
		//���ڵ� ͷָ�벻�ܳ��� βָ��
		while (window_begin < i) {
			char begin_ch = s[window_begin];
			//�����ǰͷָ�� ָ����ַ�û�����ַ���t�г���
			if (map_t[begin_ch] == 0) {
				++window_begin;
			}//ͷָ��ָ����ַ�������T��,�������г���T�и��ַ��������ַ�
			else if (map_s[begin_ch] > map_t[begin_ch]) {
				map_s[begin_ch]--;//ͷָ��ǰ��,���ָ����ַ�����1��
				window_begin++;
			}
			else {
				break;
			}
		}//while
		//����ʱ�Ĵ��� �Ƿ�����ַ���t 
		if (is_window_ok(map_s, map_t, vec_t)) {
			int new_window_len = i - window_begin + 1;
			if (res==""|| res.size() > new_window_len) {//�滻��������Ӧ���ַ���
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