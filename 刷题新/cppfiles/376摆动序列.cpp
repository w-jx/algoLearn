#if 0
#include "../headers/wjxHeaders.h"

int wiggleMaxLength(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();//因为题目说了，少于2个元素的序列也是摇摆序列

	static const int BEGIN = 0;
	static const int DOWN = 1;
	static const int UP = 2;//定义三种状态
	//只有状态 出现转换才会增加摇摆序列

	int STATE = BEGIN;
	int max_len = 1;//摇摆序列的长度 最小是1
	//从第二个元素开始扫描
	for (int i = 1; i < nums.size(); ++i) {
		switch (STATE)
		{
		case BEGIN:
			if (nums[i - 1] < nums[i]) {
				STATE = UP;
				++max_len;
			}
			else if (nums[i - 1] > nums[i]) {
				STATE = DOWN;
				++max_len;
			}
			break;
		case UP:
			if (nums[i - 1] > nums[i]) {
				STATE = DOWN;
				++max_len;
			}
			break;
		case DOWN:
			if (nums[i - 1] < nums[i]) {
				STATE = UP;
				++max_len;
			}
			break;
		}//switch
	}//for 
	return max_len;
}
//方法2:动态规划
int wiggleMaxLength2(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();
	/*
	up[i]表示nums[0]到nums[i],nums[i]>nums[i-1]的摆动序列
	down[i]表示nums[0]到nums[i],nums[i]<nums[i-1]的摆动序列

	nums[i]>nums[i-1]时，up[i]=down[i-1]+1，down[i]=down[i-1]
	nums[i]<nums[i-1]时，up[i]=up[i-1]，down[i]=up[i-1]+1
	nums[i]=nums[i-1]时，up[i]=up[i-1]+1，down[i]=down[i-1]

	up[0]=1
	down[0]=1
	第一个元素形成的摆动序列可以是上升的也可以是下降的

	*/
	int n = nums.size();
	vector<int> up(n);
	vector<int> down(n);

	up[0] = 1;
	down[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (nums[i] > nums[i - 1]) {
			up[i] = down[i - 1] + 1;
			down[i] = down[i - 1];
		}
		else if (nums[i] < nums[i - 1]) {
			down[i] = up[i - 1] + 1;
			up[i] = up[i - 1];
		}
		else if (nums[i] == nums[i - 1]) {
			up[i] = up[i - 1];
			down[i] = down[i - 1];
		}
	}
	return std::max(up[n - 1], down[n - 1]);
}

void test01()
{
	vector<int> v{ 2,2,3,4,3,3,2,2,1,1,2,5 };
	cout << wiggleMaxLength(v) << endl;;
}
void test02()
{
	//vector<int> v{ 1,7,4,9,2,5 };
	vector<int> v{ 1,17,5,10,13,15,10,5,16,8 };
	cout << wiggleMaxLength2(v) << endl;;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
#endif