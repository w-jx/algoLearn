#if 0
#include "../headers/wjxHeaders.h"
/*
"bb"
["a","b","bbb","bbbb"]
�����ȷ�Ľ����True


"aaaaaaa"
["aaaa","aaa"]
�����ȷ�Ľ����True
�����ҵĽ��,�һ�õ� 'aaa','aaa',�ڶ���Ӧ����'aaaa'�Ŷ�
*/
bool wordBreak(string s, vector<string>& wordDict) {
	unordered_map<string,int> word_hash;
	int idx = 0;
	//�ѵ��ʱ��еĵ���,�����ϣ��,ֵ�ǵ����ڵ��ʱ��е��±�
	for (const string& word : wordDict) {
		word_hash.insert({word,idx++});
	}
	int n = wordDict.size();
	vector<int> used(n);
	int len = s.size();
	string temp_str;//��ʱ��ȡ���ַ�������
	idx = 0;
	int length = 1;
	string retstr;
	bool lastFind = false;
	string sub_str;
	int subidx, sublen;//��¼����Ҫ��ĵ��ʽ�ȡλ�úͳ���
	for (int i = 0; i < len; ++i) {
		temp_str = s.substr(idx, length++);
		//���ֳ����������
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
//�����,��̬�滮
bool wordBreak2(string s, vector<string>& wordDict) {
	//dp[i]����s[0:i-1]�ܷ񱻿ո��ֳ����ɸ��ֵ��г��ֵĵ���
	//��ǰ�������ת�Ʒ���,ÿ��ת�Ƶ�ʱ����Ҫö�ٰ���λ��i-1�����һ������
	/*
	* ö��s[0:i-1]�ķָ��j
	s[0:j-1]��ɵ��ַ���s1,��s[j:i-1]��ɵ��ַ���s2
	�Ƿ񶼺Ϸ�,������Ϸ�,��ôs1+s2ƴ�ӳɵ��ַ���Ҳ�ǺϷ���

	����dp[i],�Ѿ��������dp[0,1,2,,i-1]��ֵ
	�ַ���s1�Ƿ�Ϸ����Դ�dp[j]�õ�
	����������ֻ��Ҫȥ���s2�Ƿ�Ϸ�����
	dp[i] = dp[j] && check(s[j:i-1])
	�����ʾ�Ӵ��Ƿ�������ֵ���

	�����ù�ϣ�������,Ҳ��������֦
	��j��i-1�ĳ����Ѿ������ֵ��е���󳤶�,�ͽ���ö��

	�߽�:dp[0]=true
	*/
	int n = s.size();

	vector<int> dp(n + 1);//dp[i]����s[0:i-1]�Ƿ�ɲ��
	dp[0] = 1;
	unordered_map<string, int> word_hash;
	int idx = 0;
	size_t wordmaxlen = 0;
	//�ѵ��ʱ��еĵ���,�����ϣ��,ֵ�ǵ����ڵ��ʱ��е��±�
	for (const string& word : wordDict) {
		word_hash.insert({ word,idx++ });
		wordmaxlen = std::max(wordmaxlen, word.size());
	}
	string temp_str;
	for (int i = 1; i <= n; ++i) {

		//dp[i],dp[j]��[0:j-1],j��ʼ��i-1,����i-1-j+1=i-j
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
//���������Ż�,ֻ��Ҫ�����ʵ��ڵĵ��ʳ���,�����Ĳ�����,���Դﵽ�Ż�
bool wordBreak3(string s, vector<string>& wordDict) {

	int n = s.size();

	vector<int> dp(n + 1);//dp[i]����s[0:i-1]�Ƿ�ɲ��
	dp[0] = 1;
	unordered_set<string> word_hash;
	int idx = 0;
	size_t minSize = INT_MAX, maxSize = 0;
	//�ѵ��ʱ��еĵ���,�����ϣ��
	for (const string& word : wordDict) {
		word_hash.insert( word);
		minSize = std::min(minSize, word.size());
		maxSize = std::max(maxSize, word.size());
	}
	string temp_str;
	for (int i = 1; i <= n; ++i) {
		//dp[i],dp[j]��[0:j-1],j��ʼ��i-1,����i-1-j+1=i-j
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