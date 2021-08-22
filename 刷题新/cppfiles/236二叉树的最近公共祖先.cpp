#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

��root��p,q������������ȣ�ֻ������������֮1
1.p,q��root�������У��ҷֱ���root����ࣨ���ֱ�������������������
2.p=root,��q��root������������������
3.q=root,��p��root������������������

����˼·��
��1�� �����ǰ��� rootroot ���� NULL����ֱ�ӷ��� NULL
��2�� ��� rootroot ���� pp ���� qq ���������һ������ pp ���� qq
��3�� Ȼ��ݹ�������������Ϊ�ǵݹ飬ʹ�ú��������Ϊ���������Ѿ����������� leftleft �� rightright ��ʾ
��4�� ��ʱ��leftleftΪ�գ������ս��ֻҪ�� rightright���� rightright Ϊ�գ������ս��ֻҪ�� leftleft
��5�� ��� leftleft �� rightright ���ǿգ���Ϊֻ���� pp �� qq ������㣬���ǿգ�˵��һ��һ������� rootroot �����ǵ������������
��6�� ��� leftleft �� rightright ��Ϊ�գ��򷵻ؿգ���ʵ�Ѿ�������ǰ���������ˣ�

*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	if (!root)
		return root;
	if (root == p || root == q)//���root��p����q,��ôһ������p����q
		return root;
	/*
	�ݹ�������������Ϊ�ǵݹ飬������Ϊ���������Ѿ�������,�ֱ���left,right
	*/
	TreeNode* left = lowestCommonAncestor(root->left, p, q);
	TreeNode* right = lowestCommonAncestor(root->right, p, q);
	//����ɸѡ���õ����Ľ��
	if (!left)
		return right;
	if (!right)
		return left;
	if (left && right)//p,q������
		return root;
	return nullptr;


}
/// <summary>
/// 
/// </summary>
/// <param name="node">�������Ľ��</param>
/// <param name="search">���������</param>
/// <param name="path">����·��ջ����vecģ��</param>
/// <param name="res">����������� ����</param>
/// <param name="isFind">��¼�Ƿ��Ѿ��ҵ�</param>
void preorder(TreeNode* node,TreeNode *search,
	 vector<TreeNode*>& path, vector<TreeNode*> & res
	,bool& isFind
	) {
	//���Ϊ�գ������Ѿ��ҵ�������
	if (!node || isFind)
		return;
	//�����ѹ��pathջ
	path.emplace_back(node);
	//�ҵ�search��㣬��Ǳ���Ϊ��
	if (node == search) {
		isFind = true;
		res = path;
	}

	preorder(node->left, search,path,res,isFind);
	preorder(node->right, search, path, res, isFind);

	path.pop_back();//��������node����node��㵯��path


}
//ˢ��̵̳� ����
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> pathp, resp, pathq, resq;
	bool findp, findq;
	preorder(root, p, pathp, resp, findp);
	preorder(root, p, pathq, resq, findq);

	int n = resp.size() < resq.size() ? resp.size() : resq.size();

	TreeNode* last = nullptr;
	for (int i = 0; i < n; ++i) {
		if (resp[i] != resq[i])
			return last;
		last = resp[i];
	}
	return nullptr;
}
vector<TreeNode*> res;
void dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& path)
{
	path.push_back(root);
	if (root == node)
	{
		res = path;//Ҫ������,֮ǰ��112·���ܺ���res.push_back(path)��������
		return ;
	}
	else
	{
		if (root->left)
		{
			dfs(root->left, node, path);
			path.pop_back();
		}
		if (root->right)
		{
			dfs(root->right, node, path);
			path.pop_back();
		}
	}
}
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
{
	vector<TreeNode*> pathp, pathq,resp,resq;
	dfs(root, p, pathp);
	resp = res;
	res.clear();
	dfs(root, q, pathq);
	resq = res;

	//for (auto iter : pathp)
	//	cout << iter->val << " ";
	//cout << "----------------------\n";

	//for (auto iter : pathq)
	//	cout << iter->val << " ";
	//cout << endl;

	TreeNode* ancestor = nullptr;
	for (int i = 0; i < resp.size() && i < resq.size(); i++)
	{
		if (resp[i] == resq[i])
			ancestor = resp[i];
	}
	return ancestor;
}
//2021��5��15�ո�ϰ
void getpath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
	path.push_back(root);
	if (root->val == node->val)
		return;
	else {
		if (root->left) {
			getpath(root->left, node, path);
			path.pop_back();
		}
		if (root->right) {
			getpath(root->right, node, path);
			path.pop_back();
		}
	}//

}
TreeNode* lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q) {

	vector<TreeNode*> pathp, pathq;
	getpath(root, p, pathp);
	getpath(root, q, pathq);
	int n = std::min(pathp.size(), pathq.size());

	TreeNode* ances=nullptr;
	for (int i = 0; i < n; ++i) {
		if (pathp[i] != pathq[i])
			return ances;
		ances = pathp[i];
	}
	return ances;
}
void test01()
{
	TreeNode* root = new TreeNode(3, 5, 1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2, 7, 4);

	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);

	//auto ret =
	//	lowestCommonAncestor2(root, root->left, root->left->right->right);

	//cout << ret->val << endl;


	vector<TreeNode*> resp;
	getpath(root, root->right->left, resp);
	for (int i = 0; i < resp.size(); ++i) {
		cout << resp[i]->val << " ";
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif