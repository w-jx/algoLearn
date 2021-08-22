#if 0
#include "../headers/wjxHeaders.h"

//int jump(vector<int>& nums) {
//
//    int jumptime = 0, maxIndex = 0, nextPos = 0, curPos = 0;
//    while (curPos < nums.size()) {
//        for (int temp = curPos; temp < curPos + nums[curPos]; ++temp) {
//            if (nums[temp] + temp > maxIndex) {
//                maxIndex = nums[temp] + temp;
//                nextPos = temp;
//            }
//        }
//        curPos = maxIndex;
//        ++jumptime;
//    }
//    return jumptime;
//}
//��Ծ��Ϸ2 
int jump(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;//���鳤��С��2������Ծ
	int current_max_index = nums[0];//��ǰ�ɴﵽ����Զλ��
	int pre_max_max_index = nums[0];//��������λ�ã����Դﵽ����Զλ��

	int jump_min = 1;
	/*
	idx		0 1 2 3 4
	nums	2 3 1 1 4
cur_idx		2 4 3 4 8
		�����ʼ��Ծ����Ϊ1,��Ϊ��������Ԫ��2�����ϵ�ʱ��,����Ҫ��һ��
		����ҲҪ�ӵ�2��Ԫ�ؿ�ʼ��������

		�����ʼ���Ե����λ��Ϊ2,�����±�j���������ʱ��,��j<=2��ʱ��
		����Ҫ������Ծ����,�ⶼ��Ŀǰ��һ����Ծ�ܵ��ķ�Χ

		��j==3��ʱ��,1����Ծ���ֻ�ܵ�2,����ֻ����Ծ��,������Ծ����
		ͬʱ����ȥ����Զ��λ�ø�����,���Կ����ڵ�һ����Ծ������,��ȥ��Զ���±�Ϊ
		4

		���ű���,���ǿ��Է�������j<=4ʼ�ճ���,���� ��Ծ��������2

	*/
	for (int j = 1; j < nums.size(); ++j) {
		if (j > current_max_index) {//�޷�����ǰ�ƶ��ˣ��Ž�����Ծ
			jump_min++;//���µ�ǰ�ɵ������Զλ��
			current_max_index = pre_max_max_index;
		}
		if (pre_max_max_index < nums[j] + j)
			pre_max_max_index = nums[j] + j;
	}
	return jump_min;
}
//2021��5��16�� ��ϰ����
int jump2(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;//���鳤��С��2������Ծ
	int times = 1;
	int cur_idx = 1, pre_max_idx = nums[0], max_max_idx = nums[0];
	while (cur_idx < nums.size()) {
		if (cur_idx == pre_max_idx) {
			++times;
			pre_max_idx = max_max_idx;
		}
	
		max_max_idx = std::max(max_max_idx, cur_idx + nums[cur_idx]);
		++cur_idx;
	}
	return times;
}
void test01()
{
	vector<int> nums{ 0 };
	cout << jump2(nums) << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif