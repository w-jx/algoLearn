#if 0
#include "../headers/wjxHeaders.h"
/*
"bb"
["a","b","bbb","bbbb"]
这个正确的结果是True


"aaaaaaa"
["aaaa","aaa"]
这个正确的结果是True
按照我的结果,我会得到 'aaa','aaa',第二个应该是'aaaa'才对
*/
bool wordBreak(string s, vector<string>& wordDict) {
	unordered_map<string,int> word_hash;
	int idx = 0;
	//把单词表中的单词,加入哈希表,值是单词在单词表中的下标
	for (const string& word : wordDict) {
		word_hash.insert({word,idx++});
	}
	int n = wordDict.size();
	vector<int> used(n);
	int len = s.size();
	string temp_str;//临时截取的字符串变量
	idx = 0;
	int length = 1;
	string retstr;
	bool lastFind = false;
	string sub_str;
	int subidx, sublen;//记录符合要求的单词截取位置和长度
	for (int i = 0; i < len; ++i) {
		temp_str = s.substr(idx, length++);
		//发现出现在里面的
		if (word_hash.find(temp_str) != word_hash.end()) {
			sub_str = temp_str;
			lastFind = true;
		}
		else {
			if (lastFind) {
				lastFind = false;
				retstr += sub_str;
				idx = i;
				length = 1;
				used[word_hash[sub_str]] = 1;
			}
			
		}
	}
	printVector(used);

	return retstr == s;
}
//答案题解,动态规划
bool wordBreak2(string s, vector<string>& wordDict) {
	//dp[i]代表s[0:i-1]能否被空格拆分成若干个字典中出现的单词
	//从前往后计算转移方程,每次转移的时候需要枚举包含位置i-1的最后一个单词
	/*
	* 枚举s[0:i-1]的分割点j
	s[0:j-1]组成的字符串s1,和s[j:i-1]组成的字符串s2
	是否都合法,如果都合法,那么s1+s2拼接成的字符串也是合法的

	计算dp[i],已经计算出了dp[0,1,2,,i-1]的值
	字符串s1是否合法可以从dp[j]得到
	接下来我们只需要去检查s2是否合法即可
	dp[i] = dp[j] && check(s[j:i-1])
	后面表示子串是否出现在字典中

	可以用哈希表来检查,也可以做剪枝
	从j到i-1的长度已经大于字典中的最大长度,就结束枚举

	边界:dp[0]=true
	*/
	int n = s.size();

	vector<int> dp(n + 1);//dp[i]代表s[0:i-1]是否可拆分
	dp[0] = 1;
	unordered_map<string, int> word_hash;
	int idx = 0;
	size_t wordmaxlen = 0;
	//把单词表中的单词,加入哈希表,值是单词在单词表中的下标
	for (const string& word : wordDict) {
		word_hash.insert({ word,idx++ });
		wordmaxlen = std::max(wordmaxlen, word.size());
	}
	string temp_str;
	for (int i = 1; i <= n; ++i) {

		//dp[i],dp[j]到[0:j-1],j开始到i-1,所以i-1-j+1=i-j
		for (int j = 0; j < i; ++j) {
			temp_str = s.substr(j, i - j);
			if (dp[j] == 1 && word_hash.find(temp_str) != word_hash.end()) {
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n];
}
//别人题解的优化,只需要遍历词典内的单词长度,其他的不遍历,可以达到优化
bool wordBreak3(string s, vector<string>& wordDict) {

	int n = s.size();

	vector<int> dp(n + 1);//dp[i]代表s[0:i-1]是否可拆分
	dp[0] = 1;
	unordered_set<string> word_hash;
	int idx = 0;
	size_t minSize = INT_MAX, maxSize = 0;
	//把单词表中的单词,加入哈希表
	for (const string& word : wordDict) {
		word_hash.insert( word);
		minSize = std::min(minSize, word.size());
		maxSize = std::max(maxSize, word.size());
	}
	string temp_str;
	for (int i = 1; i <= n; ++i) {
		//dp[i],dp[j]到[0:j-1],j开始到i-1,所以i-1-j+1=i-j
		for (int j = std::max((int)(i - maxSize), 0); i - j >= minSize; ++j) {
			if (dp[j] == 1 && word_hash.find(s.substr(j, i - j)) != word_hash.end()) {
				dp[i] = 1;
				break;
			}
		}
	}
	return dp[n];
}
void test01()
{
	string s = "aaaaaaa";
	vector<string> wordDict{ "aaaa", "aaa" };
	cout << wordBreak(s, wordDict) << endl;


}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif