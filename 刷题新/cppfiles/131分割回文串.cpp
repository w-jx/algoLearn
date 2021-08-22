#if 0
#include "../headers/wjxHeaders.h"

vector<vector<string>>res;
vector<string > item;
string str;
vector<vector<int>> ispart;
/*
判断回文子串,利用动态规划预处理,这样就不用双指针判断了
节约时间
dp[i][j]代表s[i]到s[j]是否是回文串
			1.true i>=j
dp[i][j]=
			2.dp[i+1][j-1] && s[i]==s[j]

假如当前搜索到字符串的第idx个,,[0,idx-1]的所有字符已经被
分割成回文串保存到Item中,我们需要枚举下一个回文串的有边界j
使得s[idx,j]是回文串
可以从idx开始,从小到大枚举j,判断s[idx,,j]是否是回文串
如果是的话,把s[idx,,j]加入结果中,j+1当成新的idx(起点)
同时回溯s[idx,,j]从结果中移除

直到idx=s.size(),代表已经找到一种结果

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