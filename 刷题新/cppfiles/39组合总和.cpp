#if 0
#include "../headers/wjxHeaders.h"

//����ʹ���ظ�����,���ǽ�������ظ�
vector<vector<int>>res;
vector<int> item;
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	backtrace(candidates, 0, target);
    return res;
}
//idx����ǰ��candidates����ĵ�idxλ,��ʣ��targetҪ��,�Ѿ��պõĴ����item��
void backtrace(vector<int>& candidates, int idx, int target) {
	if (idx == candidates.size())
		return;
	//���յ���0,item�ĺ;����ʼ��Ŀ��target
	if (target == 0) {
		res.push_back(item);
		return;
	}
	//�����ǵݹ���ֹ����:���յ�Ԫ��<=0,����,���������Ԫ���Ѿ���������

	//����candidates[idx],����һ����
	backtrace(candidates, idx + 1, target);
	//������candidates[idx],������
	if (target - candidates[idx] >= 0) {
		item.emplace_back(candidates[idx]);//ʹ�õ�ǰcandidates[idx]
		//��Ϊ�����ظ�,���Ի��Ǵ�idx��ʼ,���յļ�ȥcandidates[idx]
		backtrace(candidates, idx, target-candidates[idx]);//ע��ϸ��,���Ǵ�idx��ʼ
		item.pop_back();
	}
}
void test01()
{

}
int main()
{
	system("pause");
	return 0;
}


#endif