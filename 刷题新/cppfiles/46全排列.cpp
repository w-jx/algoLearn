#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:
����һ���ɰ����ظ����ֵ����� nums ��������˳�� �������в��ظ���ȫ���С�



*/
vector<vector<int>> res;
vector<int> item;
void dfs(vector<int>& nums, int idx, int len);
vector<vector<int>> permute(vector<int>& nums) {
    int len = nums.size();
    dfs(nums, 0, len);
    return res;
}
/*
[1,2,3]
idx ����ǰҪ��ڼ���λ��,��ʼ�ӵ�0��λ�ÿ�ʼ��,idx=0
ÿ��λ�ö��ǿ��Էֱ���ÿ��Ԫ������

�����õ�0��Ԫ�����0��λ��[1...],ʣ�µ�����λ��ֻ����[2,3]����
Ȼ��ʼ���1��λ��,idx=1,�����±�int i = idx=1��ʼ,��Ϊֻ�ܴ�[2,3]��ѡ,
��Ȼ��һ��λ�� �õ�1��Ԫ������[1,2..],ʣ�µ�һ��λ��ֻ����[3]����


Ȼ��ʼ���2��λ��,idx=2,�±�int i=idx=2,��Ϊֻ�ܴ�[3]��ѡ��
[1,2,3]��������3��λ��

idx=3

���Ƿ���3==len,�����һ�����֮1,

dfs(nums,3,len)ִ�н���
swap(nums[i],nums[idx]),��ʱidx=2,i=2,�൱�ڲ�����
������һ��forѭ��,i=3
swap(nums[3],nums[2]),Ҳ������Ԫ��3����1��λ��,[1,3..]
dfs(nums,3,len),J�����Ժ����Ƿ���

*/
void dfs(vector<int>& nums, int idx, int len) {
    if (idx == len) {
        res.push_back(nums);
        return;
    }
    //ʹ�����������ÿ��Ԫ�طֱ��Ϊ��������ĵ�һ��Ԫ��
    for (int i = idx; i < len; i++) {
     
        swap(nums[i], nums[idx]);
        dfs(nums, idx + 1, len);
        swap(nums[i], nums[idx]);
    }
}
void generate(vector<int>& nums, int usedcnt, vector<int>& visit) {
    if (usedcnt == nums.size()) {
        res.push_back(item);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visit[i] == 0) {
            visit[i] = 1;
            item.push_back(nums[i]);
            generate(nums, usedcnt + 1, visit);
            item.pop_back();
            visit[i] = 0;
        }
    }
}
//leetcode �����,ʹ��һ���������Ѿ����ʹ�������
//ʱ�临�Ӷ�����,������������ֵ������
vector<vector<int>> permute2(vector<int>& nums) {
    vector<int> visit(nums.size());//����Ƿ���ʹ�
    generate(nums, 0, visit);
    return res;

}

void helper(vector<int>& nums, vector<int>& used) {

    if (item.size() == nums.size()) {//���item��size�ﵽnums.size()
        res.push_back(item);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] == 0) {//��һ�α�����ǰԪ�ص�used[i]���1��
            item.push_back(nums[i]);
            used[i] = 1;//���λ���ù���
            helper(nums, used);//������һ�α���
            item.pop_back();//�ѵ�ǰ
            used[i] = 0;
        }
    }
}
//2021��5��27�ո�ϰ,����д
vector<vector<int>> permute3(vector<int>& nums) {
    int n = nums.size();
    vector<int> used(n);
    helper(nums, used);

    return res;

}

void test01()
{
    vector<int> nums{ 1,2,3 };
    printvectorvector(permute(nums));
}
int main()
{
    test01();
	system("pause");
	return 0;
}
#endif