#if 0
#include "../headers/wjxHeaders.h"

int wiggleMaxLength(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();//��Ϊ��Ŀ˵�ˣ�����2��Ԫ�ص�����Ҳ��ҡ������

	static const int BEGIN = 0;
	static const int DOWN = 1;
	static const int UP = 2;//��������״̬
	//ֻ��״̬ ����ת���Ż�����ҡ������

	int STATE = BEGIN;
	int max_len = 1;//ҡ�����еĳ��� ��С��1
	//�ӵڶ���Ԫ�ؿ�ʼɨ��
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
//����2:��̬�滮
int wiggleMaxLength2(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();
	/*
	up[i]��ʾnums[0]��nums[i],nums[i]>nums[i-1]�İڶ�����
	down[i]��ʾnums[0]��nums[i],nums[i]<nums[i-1]�İڶ�����

	nums[i]>nums[i-1]ʱ��up[i]=down[i-1]+1��down[i]=down[i-1]
	nums[i]<nums[i-1]ʱ��up[i]=up[i-1]��down[i]=up[i-1]+1
	nums[i]=nums[i-1]ʱ��up[i]=up[i-1]+1��down[i]=down[i-1]

	up[0]=1
	down[0]=1
	��һ��Ԫ���γɵİڶ����п�����������Ҳ�������½���

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