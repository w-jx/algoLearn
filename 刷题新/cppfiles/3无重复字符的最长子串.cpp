#if 0
#include "../headers/wjxHeaders.h"


int lengthOfLongestSubstring(string s)
{
		int len = s.size();
		if (len <= 1)
			return len;
		unordered_set<char> myset;
		int j = 0,ans=0;
		for (int i = 0; i < len; i++) {
			if (i != 0) {
				myset.erase(s[i - 1]);
			}
			while (j < len && myset.count(s[j]) == 0) {
				myset.insert(s[j]);
				j++;
			}
			ans = max(ans, j - i );
		}
		return ans;
}
//用bitset 代替unordered_set，时间复杂度和空间复杂度显著下降，因为ASCII码一共128个
int lengthOfLongestSubstring2(string s)
{
	int len = s.size();
	if (len <= 1)
		return len;
	bitset<128> mybitset(0);
	
	int ans = 0,j=0;
	for (int i = 0; i < len; i++) {
		if (i != 0)
			mybitset.reset(s[i - 1]);
		while (j < len && mybitset[s[j]] == 0) {
			//mybitset[s[j]] = 1;
			mybitset.set(s[j]);
			j++;
		}
		ans = max(ans, j - i );
	}
	return ans;
}
//利用字符哈希,时间0MS执行,超过百分之百的时间复杂度
int lengthOfLongestSubstring(string s) {
	if (s.size() < 2)
		return s.size();
	int chset[128] = { 0 };
	int maxlen = 0, j = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (i != 0)
			chset[s[i - 1]] = 0;
		while (j < len && chset[s[j]] == 0) {
			chset[s[j]] = 1;
			++j;
		}//while
		maxlen = std::max(maxlen, j - i);

		}//for
	return maxlen;
	}
int main()
{
	system("pause");
	return 0;
}


#endif