#if 0
#include "../headers/wjxHeaders.h"
vector<string> res;
//start代表字符串s的下标,idx代表第几段,temp代表一次合法的ip
void dfs(string& s, int start, int idx, string temp) {
	if (idx > 4)//合法的ip是4段
		return;
	if (idx == 4 && s.size()==start) {
		temp.pop_back();//把最后的点去除
		res.push_back(temp);
		return;
	}
	//当我们在一层中，切出一个合法的段，把剩下的字符串传到下层，继续以相同的逻辑找 另一个段。
	for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
		auto num = s.substr(start, i);
		if (num[0] == '0' && i != 1)break;
		if (stoi(num) > 255) continue;
		//第一段从start开始,截取了i个,所以第二段的起点从start+i开始截取
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
//方法1:四层for循环,0ms
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
	string temp;//temp是保存中间结果的,满足要求的temp会被加入res
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