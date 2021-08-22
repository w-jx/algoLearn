#if false
#include "./headers/wjxHeaders.h"
//��⣺https://leetcode-cn.com/problems/gas-station/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--30/
/*
1.�����ⷨ
���Ǵӵ�0����������ܷ�ص���0����

�����ⷨ��û�г�ʱ
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	int remain = 0;
	for (int i = 0; i < n; ++i) {
		int j = i;//��i��ʼ�������
		remain = gas[i];
		//���ܷ񵽴���һ����
		while (remain-cost[j]>=0) {
			//��ȥ���ѵ�
			remain -= cost[j];
			j = (j + 1) % n;
			if (j == i)//�Ѿ��ص�i�ˣ�˵���ɹ���
				return i;
			remain += gas[j];//�����µ�Ĳ���
			
		}
	}
	return -1;
	
}

//�Ľ��汾
//���Ǽ�¼ÿ�����ܵ������Զ�㣬������Զ��ʣ�µ�������Ҳ������
//�����㵽��һ���㣬�Ͳ����ظ��㣬��ֱ�����ܵ��Ķ���ʣ�¶������;���ء��
int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	vector<int> farIndex(n,-1);
	vector<int> farremain(n, -1);

	for (int i = 0; i < n; ++i) {
		int j = i;//��ǰ���ǵ�j��
		int remain = gas[i];
		while (remain - cost[j] >= 0) {
			remain -= cost[j];
			j = (j + 1) % n;
			if (farIndex[j] != -1) {
				//���ϵ�ʱʣ�µ�����
				remain += farremain[j];
				j = farIndex[j];
			}
			else {
				remain += gas[j];
			}
			if (j == i)
				return i;
		}
		farIndex[i] = j;
		farremain[i] = remain;
	}
	return -1;
}
/*
�����i����Զ��j ---����i+1 ��j ֮��Ľڵ㲻������һȦ
��֤��
	����i+1 �Ľ������һȦ����ζ�Ŵ�i+1 һ���ܵ�j+1
	��i�ܵ�j�����Դ�i һ��Ҳ�ܵ�i+1��
	��Ȼi�ܵ�i+1,��ôiҲ���ܵ�j+1,�ͺ�"i��Զ��j"ì����


�������i��Զ��j����i+1��j֮��Ľڵ㶼��������һȦ��jҲ�ǲ����Ե�
֤����
	����j������һȦ����ζ��j���Ե�j+1
	Ȼ��i������Զ��j����ζiҲ�ܵ�j+1====>ì��
���ۣ����i��Զ��j����ô�����´�ֱ�Ӵ�j+1���Ǽ���

*/
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost)
{
	int n = gas.size();
	int remain = 0, j = 0;
	for (int i = 0; i < n; ++i) {
		j = i;
		remain = gas[i];
		while (remain - cost[j] >= 0) {
			remain = remain - cost[j] + gas[(j + 1) % n];
			j = (j + 1) % n;
			if (j == i)
				return i;
		}
		if (j < i)//��Զ�����Ƶ���֮ǰ��i����Ķ���������һȦ��
			return -1;
		i = j;//i��j��ѭ��++i,�൱�ڴ�j+1����
	}
	return -1;
}
void test01()
{

}
void main()
{
	test01();
}



#endif 