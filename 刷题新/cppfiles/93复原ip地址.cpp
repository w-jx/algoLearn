#if 0
#include "../headers/wjxHeaders.h"
vector<string> res;
//start�����ַ���s���±�,idx����ڼ���,temp����һ�κϷ���ip
void dfs(string& s, int start, int idx, string temp) {
	if (idx > 4)//�Ϸ���ip��4��
		return;
	if (idx == 4 && s.size()==start) {
		temp.pop_back();//�����ĵ�ȥ��
		res.push_back(temp);
		return;
	}
	//��������һ���У��г�һ���Ϸ��ĶΣ���ʣ�µ��ַ��������²㣬��������ͬ���߼��� ��һ���Ρ�
	for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
		auto num = s.substr(start, i);
		if (num[0] == '0' && i != 1)break;
		if (stoi(num) > 255) continue;
		//��һ�δ�start��ʼ,��ȡ��i��,���Եڶ��ε�����start+i��ʼ��ȡ
		dfs(s, start + i, idx + 1, temp + num + '.');
	}

}
bool check(string& str) {
	if (stoi(str) <= 255) {
		if (str[0] != '0' || (str.size() == 1 && str[0] == '0'))
			return true;
	}
	return false;
}
//����1:�Ĳ�forѭ��,0ms
vector<string> restoreIpAddresses(string s) {

	for (int a = 1; a < 4; ++a) {
		for (int b = 1; b < 4; ++b) {
			for (int c = 1; c < 4; ++c) {
				for (int d = 1; d < 4; ++d) {
					if (a + b + c + d == s.size()) {
						string s1 = s.substr(0, a);
						string s2 = s.substr(a+0, b);
						string s3 = s.substr(a + b, c);
						string s4 = s.substr(a + b + c, d);

						if (check(s1) && check(s2) && check(s3) && check(s4)) {
							string ip = s1 + '.' + s2 + '.' + s3 + '.' + s4;
							res.push_back(ip);
						}
					}
				}
			}
		}
	}
	return res;
}

vector<string> restoreIpAddresses2(string s) {
	if (s.size() < 4 || s.size() > 12)
		return {};
	string temp;//temp�Ǳ����м�����,����Ҫ���temp�ᱻ����res
	dfs(s, 0, 0, temp);
	return res;
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