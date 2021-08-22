#if 0
#include "../headers/wjxHeaders.h"

//����1 ʹ�ö���ռ�ķ���
vector<TreeNode*> preorder(TreeNode* root)
{
	if (!root)
		return {};
	stack<std::pair<TreeNode*, bool>> mystack;
	mystack.push({ root,false });
	vector<TreeNode*> pre_vec;

	while (!mystack.empty()) {
		auto node = mystack.top();
		mystack.pop();

		if (node.second) {
			pre_vec.push_back(node.first);
		}
		else {
			if (node.first->right)
				mystack.push({ node.first->right,false });
			if (node.first->left)
				mystack.push({ node.first->left,false });
			node.second = true;
			mystack.push(node);
		}
	}
	return pre_vec;
}
void flatten(TreeNode* root) {
	
	auto pre_vec = preorder(root);
	pre_vec.push_back(nullptr);
	for (int i = 0; i < pre_vec.size()-1; ++i) {
		pre_vec[i]->left = nullptr;
		pre_vec[i]->right = pre_vec[i + 1];
	}
}
//�����������  ��������ǽ̳�����ģ������޷�ͨ��leetcode 
//��������� �ᶪʧ �Һ��� ԭ�����Һ����Ĳ���2 ���˼�����
void preorder(TreeNode* root,TreeNode* &last)
{
	if (!root)//��ǰ���Ϊ�� ֱ�ӷ���
		return;
	if (!root->left && !root->right) {//û����������
		last = root;
		return;
	}
	TreeNode* left_tmp = root->left;
	TreeNode* right_tmp = root->right;//��������ָ��
	TreeNode* left_last = nullptr, * right_last = nullptr;
	//��������  
	if (left_tmp) {
		preorder(left_tmp, left_last);
		//���������ı������ù���left_last��Ȼ��nullptr����˶�ʧ��������
		root->left = nullptr;
		root->right = left_tmp;
		last = left_last;
	}
	if (right_tmp) {
		preorder(right_tmp, right_last);//����������ֱ
		//�������������
		if (left_last) {
			left_last->right = right_tmp;
		}
		last = right_last;
	}
}
void flatten2(TreeNode* root) {
	TreeNode* last = nullptr;
	preorder(root, last);

}
//leetcode �ٷ����
void flatten3(TreeNode* root) {
	TreeNode* curr = root;
	while (curr != nullptr) {
		if (curr->left != nullptr) {
			auto next = curr->left;
			auto predecessor = next;
			while (predecessor->right != nullptr) {
				predecessor = predecessor->right;
			}
			predecessor->right = curr->right;
			curr->left = nullptr;
			curr->right = next;
		}
		curr = curr->right;
	}
}
//leetcode ���˵���� �о��ܺ����
void flatten4(TreeNode* root) {
	if (!root) return;

	flatten4(root->left);
	flatten4(root->right);

	/**** �������λ�� ****/
	// 1�����������Ѿ�����ƽ��һ������
	auto left = root->left;
	auto right = root->right;
	// 2������������Ϊ������
	root->left = NULL;
	root->right = left;
	// 3����ԭ�ȵ��������ӵ���ǰ��������ĩ��
	auto p = root;
	while (p->right) {//���������һ��
		p = p->right;
	}
	p->right = right;
}


//ˢ���������
void test01()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);

	//root->left->left = new TreeNode(3);
	//root->left->right = new TreeNode(4);

	//root->right->right = new TreeNode(6);

	flatten2(root);//���ֻ��123
	while (root) {
		if (root->left) {
			cout << "error\n";
		}
		cout << root->val;
		root = root->right;
	}
	

}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif