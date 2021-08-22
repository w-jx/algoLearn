#if 0
#include "../headers/wjxHeaders.h"

//����Ľ������
//[0,0,0,1,1,1,0] �����6
//Ӧ������һ��0,��Ӧ����һ��1��Ӧ
enum STATE {

	ZERO,
	ONE,
	NONE,
};
int findMaxLength(vector<int>& nums) {
	int n = nums.size();
	int state = STATE::NONE;
	int len = 0;
	int maxlen = 0;
	for (const auto& num : nums) {
		switch (state) {
		case ZERO:
			if (num == 1) {
				state = ONE;
				++len;
			}
			else if (num == 0) {
				maxlen = std::max(maxlen, len);
				len = 1;
			
			}
			else {
				state = NONE;
				maxlen = std::max(maxlen, len);
				len = 0;
			}
			break;
		case ONE:
			if (num == 0) {
				state = ZERO;
				++len;
			}
			else if (num == 1) {
				maxlen = std::max(maxlen, len);
				len = 1;
			}
			else {
				state = NONE;
				maxlen = std::max(maxlen, len);
				len = 0;
			}
			break;

		case NONE:
			maxlen = std::max(len, maxlen);
			if (num == 0) {
				state = ZERO;
				++len;
			}
			else if (num == 1) {
				state = ONE;
				++len;
			}
			break;
		}
	}
	maxlen = std::max(maxlen, len);
	if (maxlen%2==0)
		return maxlen;
	return maxlen - 1;
}
//����Ǵ����
void test01()
{
	vector<int> nums{ 1,0,2,0,1,0,1,3,4,5,0,1,0,1,0,1,2,3 };
	cout << std::format("maxlen:{}\n", findMaxLength(nums));
}
/*

 1 1 1 1 1 0 0 0 1
 �����:
 0����Ŀ��1����Ŀ��ͬ,�ȼ���0����Ŀ��ȥ1������Ϊ0

 �������е�0����-1,��������0�ĺ�
 ԭ����ת��:���������������,Ԫ�غ�Ϊ0

 1.������ת����������(0�ĳ�-1)
 2.��ǰ׺������

 p_sum[k]-p_sum[j]==0

 1 1 1  [2]
 1 1 1 1 1[4]
 ���Գ���Ϊj-k,�ҵ����ļ���

 ���������ⷨ�ᳬʱ


 ʵ����,����Ҫ����������,Ҳ��Ҫ����ǰ׺������
 ֻ��Ҫһ������counter �洢�������ǰ׺�;�����
 ���ù�ϣ��洢ÿ��ǰ׺�͵�һ�γ��ֵ��±�
 �涨�յ� �����±�-1,Ԫ�غ�Ϊ0
 ��ϣ���ȴ洢{0,-1}

 ����ÿ���±�i:
 ���counter�Ѿ�����,��ȡ��֮ǰ���±�preIdx
 ��preIdx+1���±�i������������ͬ������0,1
 ����Ϊi-preIdx

 ���counter������,��counter��i�����ϣ

*/
//�����ⷨд������˵
int findMaxLength2(vector<int>& nums) {
	unordered_map<int, int> mp;
	int counter = 0;
	mp[counter] = -1;
	int n = nums.size();
	int maxlength = 0;
	for (int i = 0; i < n; ++i) {
		int num = nums[i];
		if (num == 1)
			++counter;
		else
			--counter;
		if (mp.count(counter)) {
			int preIdx = mp[counter];
			maxlength = std::max(maxlength, i - preIdx);
		}
		else
			mp[counter] = i;
	}
	return maxlength;
}
int main()
{
	test01();
}


#endif