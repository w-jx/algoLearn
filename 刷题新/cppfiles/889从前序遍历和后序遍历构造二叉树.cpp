#if 0
#include "../headers/wjxHeaders.h"

TreeNode* buildtree(vector<int>& pre, vector<int>& post, int pre_start, int
    pre_end, int post_start, int post_end);

TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    int len = pre.size();
    return buildtree(pre, post, 0, len - 1, 0, len - 1);
}
/*
����ⷨ������:
ǰ�����:�� ������ ������
������� ������ ������  ��
��Ҫ�ҵ��ܰѸ� ������ ������ ���ֿ��Ľ���

����:
       1
     2   3
    4 5 6 7
ǰ��:[1 2 4 5 3 6 7]
����:[4 5 2 6 7 3 1]
���Կ��������� [2,4,5],������[3,6,7]����1
ǰ��ĵڶ������Ϊ2,Ҳ�����������ĸ�,���ں�����2�����ȫ��������,2���ұ߳��������������
�������Ƿ��ֺ����п���ֱ���������Ľ��������3
�������һ���Ǹ�,��˿��Խ����������Ľ������,
����������������������ǰ�������������ķ�Χ,�ֱ���


*/
TreeNode* buildtree(vector<int>& pre, vector<int>& post, int pre_start, int
    pre_end, int post_start, int post_end) {
    if (pre_start > pre_end || post_start > post_end)
        return nullptr;
    TreeNode* root = new TreeNode(pre[pre_start]);//
    if (pre_start == pre_end)//ֻ��һ����㣬ֱ�ӷ��ؼ���
        return root;
    int index = post_start;
    while (pre[pre_start + 1] != post[index])//�����ҵ�ǰ������ĵڶ���Ԫ���ں�������е�λ��
        index++;//��һ��Ҳ�����ù�ϣ������
    //����index,��ô����������������index-post_start+1 ,��leftcount����
    /*
  ��������У�����֪�� ��������[post_start,index], ��������[index+1, post_end-1]
��ǰ������У���������ʼλ��Ϊpre_start+1,����������һ����(index - post_start+1)��������
����Ҫ���Ƿ�Χ�������������ʼλ�ü�index-post_start����

����������ķ�Χ�ǣ�[pre_start+1, pre_start+1 + (index - post_start)] 
��������ʼλ��Ϊ��������ֹλ��+1����ֹλ��Ϊpre_end��
�����������Χ�ǣ�[ pre_start+1 + (index - post_start) + 1, pre_end]

������
pre = [1,2,4,5,3,6,7]    ǰ������ĵڶ���Ԫ��2���ں���������±�Ϊ2
�����ں���������ǿ��Կ��������� [4,5,2] ���Է�Χ��[0,2] ,������[6,7,3]����Χ��[3,5]
����ǰ�������������[2,4,5]��Χ��[1��3],������[3,6,7]����Χ��[4,6]
post = [4,5,2,6,7,3,1]

    */

    root->left = buildtree(pre, post, pre_start + 1, pre_start + 1 + index - post_start, post_start, index);
    
    root->right = buildtree(pre, post, pre_start + 1 + 1 + index - post_start, pre_end, index + 1, post_end - 1);

 
    return root;
}
unordered_map<int, int>  post_map;//����������ֵ�Ĺ�ϣ��
//�ٸ������乹��������Ľ��
TreeNode* bd(vector<int>& pre, vector<int>& post, int pre_s, int pre_e, int post_s, int post_e) {
    if (pre_s > pre_e || post_s > post_e)
        return nullptr;
    TreeNode* root = new TreeNode(pre[pre_s]);//
    if (pre_s == pre_e)
        return root;
    int idx = post_map[pre[pre_s + 1]];

    root->left = bd(pre, post, pre_s + 1, pre_s + 1 + idx-post_s, post_s, idx);
    root->right = bd(pre, post, pre_s + 1 + idx - post_s+1, pre_e, idx + 1, post_e - 1);
    return root;
}
//2021��5��20�ո�ϰ,�д���
TreeNode* constructFromPrePost2(vector<int>& pre, vector<int>& post) {
    int n = pre.size();
    for (int i = 0; i < n; ++i) {
        post_map[post[i]] = i;
    }
    return bd(pre, post, 0, n - 1, 0, n - 1);
}
void test01()
{
    vector<int> pre{ 1,2,4,5,3,6,7 };
    vector<int> post{ 4,5,2,6,7,3,1 };
    TreeNode* root = constructFromPrePost2(pre, post);

    recursionTree(root);
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif