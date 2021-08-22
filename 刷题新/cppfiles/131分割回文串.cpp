#if 0
#include "../headers/wjxHeaders.h"

vector<vector<string>>res;
vector<string > item;
string str;
vector<vector<int>> ispart;
/*
�жϻ����Ӵ�,���ö�̬�滮Ԥ����,�����Ͳ���˫ָ���ж���
��Լʱ��
dp[i][j]����s[i]��s[j]�Ƿ��ǻ��Ĵ�
			1.true i>=j
dp[i][j]=
			2.dp[i+1][j-1] && s[i]==s[j]

���統ǰ�������ַ����ĵ�idx��,,[0,idx-1]�������ַ��Ѿ���
�ָ�ɻ��Ĵ����浽Item��,������Ҫö����һ�����Ĵ����б߽�j
ʹ��s[idx,j]�ǻ��Ĵ�
���Դ�idx��ʼ,��С����ö��j,�ж�s[idx,,j]�Ƿ��ǻ��Ĵ�
����ǵĻ�,��s[idx,,j]��������,j+1�����µ�idx(���)
ͬʱ����s[idx,,j]�ӽ�����Ƴ�

ֱ��idx=s.size(),�����Ѿ��ҵ�һ�ֽ��

*/

void helper(string s, int idx,int const &len) {
	if (idx ==len) {
		res.emplace_back(item);
		return;
	}
	for (int i = idx; i < len; ++i) {
		if (ispart[idx][i] == 1) {
			item.push_back(s.substr(idx,i-idx+1));
			helper(s, i + 1, len);
			item.pop_back();
		}
	}
}
vector<vector<string>> partition(string s) {
	int n = s.size();
	ispart.assign(n, vector<int>(n,0));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			ispart[i][j] = 1;
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (ispart[i + 1][j - 1] == 1 && s[i] == s[j]) {
				ispart[i][j] = 1;
			}
		}
	}




	/*
1 1 0
1 1 0
1 1 1
	*/
	printvectorvector(ispart);
	helper(s, 0, s.size());
	return res;
}
void test01()
{
	string s("aab");
	auto strvec = partition(s);
	for (auto vec : strvec) {
		for (auto str : vec) {
			cout << str << " ";
		}
		cout << endl;
	}
}
int main()
{
	test01();
}
#endif