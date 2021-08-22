#if 0
#include "../headers/wjxHeaders.h"
/*
微软面试题,面经


*/

vector<vector<int> > res;//可能的出栈序列结果
vector<int> seq;//某一个出栈序列
int resnum;
/*
当所有的入栈序列已经全部入栈后，则只能出栈
当栈为空时，只能进栈
当仍有入栈元素且栈不为空时，可以入栈，也可以出栈

入栈 -> 递归处理下一个入栈元素 -> 恢复未入栈状态
出栈 -> 将出栈元素添加到出栈序列 -> 递归处理当前入栈元素 -> 恢复栈和出栈序列上一个的状态
*/

/// <summary>
/// 
/// </summary>
/// <param name="in">入栈序列</param>
/// <param name="i">当前是入栈序列的第几个元素</param>
/// <param name="stk">栈</param>
void generate(vector<int>& in, int i, stack<int>& stk)
{
	if (i > in.size())
		return;
	else if (i == in.size()) {
	//输入序列已经全部入栈了,只能出栈了,将栈里面的元素都添加到seq的后面
	//保存seq
		if (!stk.empty()) {
			int topelem = stk.top();
			seq.push_back(topelem);
			stk.pop();
			//保持i==数组大小,递归地将元素复制到seq中
			generate(in, i, stk);//递归执行,每次栈进行pop,输入到序列中,直到栈为空
			stk.push(topelem);//回溯
			seq.pop_back();
		}
		else {
			res.push_back(seq);//保存结果
			++resnum;
		}
		
	}
	else {
		//对于一个输入元素,可以入栈,可以不入,弹出栈中已经有的元素
		
		//入栈的情况
		stk.push(in[i]);
		generate(in, i + 1, stk);
		stk.pop();//回溯,恢复栈之前的状态

		//如果栈为空,只能入栈,下面的程序不执行

		//有入栈元素,栈也不为空,可以入栈,也可以出栈
		//出栈
		if (!stk.empty()) {
			int topelem = stk.top();
			stk.pop();
			seq.push_back(topelem);
			generate(in, i, stk);
			seq.pop_back();//回溯,恢复栈和序列之前的情况
			stk.push(topelem);
		}
	}
}
/// <summary>
/// 
/// </summary>
/// <param name="in">入栈序列</param>
/// <returns>生成可能的出栈序列结果</returns>
int getNums(vector<int>& in)
{
	stack<int> mystack;
	generate(in, 0, mystack);
	return resnum;
}
void test01()
{
	vector<int> nums{ 1,2,3 };
	cout << getNums(nums) << endl;
	for (auto arr : res) {
		for (auto elem : arr)
			cout << elem << " ";
		cout << endl;
	}
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif