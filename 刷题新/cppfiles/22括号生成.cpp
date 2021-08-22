#if 0
#include "../headers/wjxHeaders.h"

/*  为了解决合法的括号问题，我们先解决生成所有括号的问题
例如给你数字2，让你生成2对括号的排列组合
*/
string item;
vector<string> res;
void dfs(int n)
{
	if (item.size() == 2*n) {
		res.push_back(item);
		return;
	}
	item.push_back('(');
	dfs(2);
	item.pop_back();

	item.push_back(')');
	dfs(2);
	item.pop_back();
	
	
}
//利用一对变量，控制
//首先左右括号都要放n个
//只有先放左括号，再放右括号才可能合法，也就是left<right时才放右括号
void dfs2(int n,int left,int right)
{
	if (left==0 && right==0) {//条件要改成这个，而不能是size()==2*n
		res.push_back(item);
		return;
	}
	if (left > 0) {
		item.push_back('(');
		dfs2(2,left-1,right);
		item.pop_back();
	}
	if (left < right) {//左括号放置的比右括号多了,所以应该放右括号了
		item.push_back(')');
		dfs2(2,left,right-1);
		item.pop_back();
	}
}
vector<string> generateParenthesis(int n) {
	dfs(2);
	return res;
}
vector<string> generateParenthesis2(int n) {
	dfs2(n,n,n);
	return res;
	
}
//生成括号，还没有检查是否合法
void test01()
{
	auto res = generateParenthesis(2);
	for (auto iter : res)
		cout << iter << endl;

}
void test02()
{
	auto res2 = generateParenthesis2(2);
	for (auto iter : res)
		cout << iter << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}


#endif