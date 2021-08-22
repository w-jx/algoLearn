#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
方法4最好理解
*/
bool isPalindrome(string s) {
	int begin = 0;
	int end = s.size() - 1;

	while (begin < end) {
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}
string longestPalindrome(string s) { //这个速度太慢了

	if (s.empty()) return {};
	string str = "";
	str.resize(1);
	str[0] = s[0];
	int len = s.size();
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 2; j <= len - i; j++) {
			string temp = s.substr(i, j);
			if (temp.front() != temp.back())continue;
			if (isPalindrome(temp)) {
				if (temp.size() > str.size()) {
					str.clear();
					str.append(temp);
				}
			}
		}
	}
	return str;
}

//暴力解法 2021/2/12

bool isPalindrome2(string s, int begin, int end) {

	while (begin < end) {
		if (s[begin] != s[end])
			return false;
		begin++;
		end--;
	}
	return true;
}
//暴力解法，时间800多ms
string longestPalindrome2(string s) {

	int len = s.size();
	int size = 1, left = 0;
	for (size_t i = 0; i < len - 1; i++) {
		for (size_t j = i + 1; j < len; j++) {
			if (s[i] == s[j] && j - i + 1 > size && isPalindrome2(s, i, j)) {
				size = j - i + 1;
				left = i;
			}

		}
	}
	return s.substr(left, size);
}
/*
边界条件是：表达式 [i + 1, j - 1] 不构成区间，即长度严格小于 2，即 j - 1 - (i + 1) + 1 < 2 ，整理得 j - i < 3。

这个结论很显然：j - i < 3 等价于 j - i + 1 < 4，即当子串 s[i..j] 的长度等于 2 或者等于 3 的时候，
其实只需要判断一下头尾两个字符是否相等就可以直接下结论了。

如果子串 s[i + 1..j - 1] 只有 1 个字符，即去掉两头，剩下中间部分只有 1 个字符，显然是回文；
如果子串 s[i + 1..j - 1] 为空串，那么子串 s[i, j] 一定是回文子串。
因此，在 s[i] == s[j] 成立和 j - i < 3 的前提下，直接可以下结论，dp[i][j] = true，否则才执行状态转移。




*/
//尝试用动态规划做
string longestPalindrome3(string s) {
	if (s.empty())
		return s;
	int n = s.size();
	vector<vector<int> > dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		dp[i][i] = 1;
	
	int left = 0, max = 1;
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < j; ++i) {
			if (s[i] != s[j])
				dp[i][j] = 0;
			else {
				if (j - i < 3)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i + 1][j - 1];
			}
			if (dp[i][j] == 1 && j - i + 1 > max) {
				max = j - i + 1;
				left = i;
			}

		}
	}

	return s.substr(left, max);
}
string longestPalindrome4(string s) {
	if (s.size() < 2)
		return s;
	int n = s.size();
	vector<vector<bool> > dp(n, vector<bool>(n));
	for (int i = 0; i < n; ++i)
		dp[i][i] = 1;
	/*
	假如数组长度为5
	00,11,22,33,44已经确定
	01可以确定
	
	02 可以从11确定,12可以确定

	03 可以从12确定,13可以从11确定,23可以确定

	04 可以从13确定,14可以从23确定,24可以从33确定,34可以确定

	05 可以从14确定,15可以从24确定,25可以从34确定,35可以从44确定,45可以直接确定

	所以采取先固定j=1,在固定i=0,i<j
	
	*/
	int maxlen = 1, start = 0;
	for (int j = 1; j< n ; ++j) {
		for (int i= 0; i < j; ++i) {
			if (s[i] != s[j])
				dp[i][j] = false;
			else {
				if (j - i == 1) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = dp[i + 1][j - 1] ;
				}
			}
		
			if (dp[i][j] && j-i+1 > maxlen) {
				start = i;
				maxlen = j - i + 1;
			}
		}
	}

	return s.substr(start, maxlen);
}
void test01()
{
	string str = "abcdbbfcba";
	cout << longestPalindrome(str) << endl;
	//cout<<isPalindrome(str) << endl;
}
void test02()//substr
{
	string str = "azwdzwmwcqzgcobeeiphemqbjtxzwkhiqpbrprocbppbxrnsxnwgikiaqutwpftbiinlnpyqstkiqzbggcsdzzjbrkfmhgtnbujzszxsycmvipjtktpebaafycngqasbbhxaeawwmkjcziybxowkaibqnndcjbsoehtamhspnidjylyisiaewmypfyiqtwlmejkpzlieolfdjnxntonnzfgcqlcfpoxcwqctalwrgwhvqvtrpwemxhirpgizjffqgntsmvzldpjfijdncexbwtxnmbnoykxshkqbounzrewkpqjxocvaufnhunsmsazgibxedtopnccriwcfzeomsrrangufkjfzipkmwfbmkarnyyrgdsooosgqlkzvorrrsaveuoxjeajvbdpgxlcrtqomliphnlehgrzgwujogxteyulphhuhwyoyvcxqatfkboahfqhjgujcaapoyqtsdqfwnijlkknuralezqmcryvkankszmzpgqutojoyzsnyfwsyeqqzrlhzbc";
	/*string strtemp = str.substr(4, 2);

	cout << strtemp << endl;*/
	//string str2 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	//string str= "abcdbbdcba";
	string str3 = "cbbd";

	//cout << longestPalindrome2(str2) << endl;

	string  str4 =
		"ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
	//cout << longestPalindrome2(str3) << endl;
	cout << longestPalindrome2(str4) << endl;
}
//动态规划
void test03()
{
	string str ="aaaa";
	cout << longestPalindrome4(str) << endl;
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