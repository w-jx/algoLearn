#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//����Ӳ�� ��û����ȫ���Ĵ���
vector<vector<int> > res;//�������յĽ��
vector<int> item;//����������м�ĳһ�����еĽ��
void dfs(vector<int>& nums, int idx, int len) {
    if (idx == len) {
        res.push_back(nums);
    }
    set<int> myset;
    for (int i = idx; i < len; ++i) {
        if (myset.find(nums[i]) != myset.end())
            continue;
        myset.insert(nums[i]);
        swap(nums[i], nums[idx]);
        dfs(nums, idx + 1, len);
        swap(nums[i], nums[idx]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    dfs(nums, 0, nums.size());
    return res;
}
/// <summary>
///  item һ�����н��,res���ս��
/// </summary>
/// <param name="nums">ԭ����</param>
/// <param name="visit">����Ƿ��Ѿ�ѡ���</param>
/// <param name="len">nums�ĳ���</param>
void backtrace(vector<int>& nums, vector<int>& visit,int &len ) {
    if (item.size() == len) {
        res.push_back(item);
        return;
    }
    /*
    * �������,����ΪʲôҪ��visit[i-1]==0
    https://leetcode-cn.com/problems/permutations-ii/solution/47hui-su-jian-zhi-zhong-fu-shu-by-bu-zhi-h7dm/
    */
    for (int i = 0; i < len; ++i) {
//�������Ҫ���46ȫ���б�����������,��һ�α��[1,0,0]��
//�ڶ��ΰѵڶ������ֵ��ɵ�һ�����ֵ�ʱ��,����Ѿ�����,���[0,1,0]��,
// �����ʱ��һ�����ֺ͵ڶ�������,��ͬ,���ҵ�һ�����ֻ�û�з���,˵����ͬһ��,��Ҫ��֦
// 
//��֦������ͬһ����������ٶ��ѡ���������ѡ��֮��ľ�����һ�£���ô�ͼ���һ�����ص������Ƿ���ͬһ��
        if (visit[i] == 1 || (i > 0 && nums[i] == nums[i - 1] && visit[i - 1] == 0))
            continue;////��֦,visit[i-1]==0 ��֤ȷʵ����ͬһ�㷢�����ظ���ѡ��
        //visit[i]�Ѿ�ѡ�����,����visit[i]��visti[i-1]��û�з��ʹ�
        item.push_back(nums[i]);
        visit[i] = 1;
        backtrace(nums, visit, len);
        item.pop_back();//����ѡ��
        visit[i] = 0;
    }
}
vector<vector<int>> permuteUnique2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> visit(n);
    backtrace(nums, visit,n);
    return res;
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