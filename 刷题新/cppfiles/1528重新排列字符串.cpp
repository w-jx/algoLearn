#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:
给你一个字符串 s 和一个 长度相同 的整数数组 indices 。

请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。

返回重新排列后的字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shuffle-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
string restoreString(string s, vector<int>& indices) {
	size_t size = indices.size();

	string sRet = "";
	sRet.resize(size, '-');
	for (int i = 0; i < size; i++) {
		sRet[indices[i]] = s[i];
	}
	return sRet;
}
void test01()
{
	string s = "codeleet";
	vector<int > v= { 4,5,6,7,0,2,1,3 };

	string sret = restoreString(s, v);
	for_each(sret.begin(), sret.end(), printChar);

}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif