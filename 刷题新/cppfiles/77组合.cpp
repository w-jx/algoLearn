#if 0
#include "../headers/wjxHeaders.h"
/*�����㷨
leecode��Ŀ����:
������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�




*/
void dfs(int n, int k, int start, vector<int>& temp);
vector<vector<int>> res;
/// <summary>
/// ��������n,��k,����1....n������k���������
/// </summary>
/// <param name="n">n�Ǹ����������ޣ�1-n</param>
/// <param name="k">k���������</param>
/// <returns>�������</returns>
vector<vector<int>> combine(int n, int k) {
    if (k <= 0 || n <= 0) return res;
    vector<int> temp;
    dfs(n, k, 1,temp);
    return res;
}
void dfs(int n, int k, int start,vector<int>& temp) {
    
    if (k == temp.size()) {
        res.push_back(temp);
        return;
    }
    //��start ��ʼ���������Ǵ�0���Ǵ�1
    for (int i = start; i <= n; i++) {
        //��ѡ��
        temp.push_back(i);
        dfs(n, k, i + 1, temp);
        temp.pop_back();
    }
 
}
void test01()
{

}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif