#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	if (dungeon.empty())
		return 0;
	//dp[i][j]������dungeon[i][j]λ��,������Ҫ����Ѫ��
	vector<vector<int> > dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
	int row = dungeon.size();
	int col = dungeon[0].size();
	/*
	����������ڵ�λ��:
	1.�Ǹ�����,������-5 ��ômax(1,1-(-5)) =6,����������Ҫ6��Ѫ��
	2.��0,��ômax[1,1-0]=1,����������Ҫ1��Ѫ��
	3.������,����3,��ômax(1,1-3)=max(1,-2)=1,�������λ�ÿ��Լ�Ѫ,����������Ҫ1��Ѫ��
	*/
	dp[row - 1][col - 1] = std::max(1, 1 - dungeon[row - 1][col - 1]);

	//��������һ�к����һ�е�ֵ��ȷ����
	//��ȷ�����һ��

	/*
	�������ǵ��������[3,2,-5]
	��ȷ��dp[row-1][col-1]=6,������Ҫ6��Ѫ,Ȼ��ȷ��ǰ������
	��Ϊ��������λ����Ҫ6,�ڵڶ���λ�û�����2��Ѫ,���Ե��ڶ���λ��������Ҫ4
	��Ϊ���ڶ���λ����Ҫ4,�ڵ�һ��λ�û�����3��Ѫ,���Ե���һ��λ��������Ҫ1

	Ҳ����dp[i][j]��dp[i][j+1]�й�ϵ
	std::max(1, dp[row-1][i+1] - dungeon[row - 1][i]);
	����dp[row-1][i+1]��6,���dungeon[row - 1][i] ������2,
	��ô��Ӧ�ü�ȥ 6-2=4,����ǰλ��������ҪѪ��4

	���dungeon[row - 1][i] �Ǹ��� -3
	��ôӦ�ü�ȥ 6-(-3)=9,������Ҫ9,�����λ�ÿ���3��Ѫ,�����һ��λ�û�ʣ��6��

	���dp[row-1][i+1]��0,
	����Ӧ�ü�ȥ,6-0=0,������Ҫ6,���������λ�ò��仯,�����һ��λ�û�ʣ��6��

	����������ô����,������ĳ��λ��������ҪѪ��1,Ҳ�������Ѫ����1

	����������ĳһʱ�̽��� 0 �����£�������������
	
	*/
	for (int i = col - 2; i >= 0; i--) {
		dp[row - 1][i] = std::max(1, dp[row-1][i+1] - dungeon[row - 1][i]);
	}
	for (int i = row - 2; i >= 0; i--) {
		dp[i][col - 1] = std::max(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);
	}
	int dp_min = 0;//Ϊ�˼�¼dp[i][j] ����dp[i+1][j]���ұ�dp[i][j+1]�ĸ���С
	//ͬ�����Ǽ�ȥһ����,3-5=-2,10-5=5,С�Ľ����С
	//���� ����λ��
	for (int i = row - 2; i >= 0; --i) {
		for (int j = col - 2; j >= 0; --j) {
			dp_min = std::min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = std::max(1 ,dp_min - dungeon[i][j]);
		}
	}
	return dp[0][0];
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