#if 0
#include "../headers/wjxHeaders.h"

void int_tostring(int val, string& str_val)
{
	std::string tmp;
	while (val) {
		//ÿ�ν�val�����λת��Ϊ�ַ�����ӵ�tmpβ��
		tmp += val % 10+'0';
		val /= 10;
	}
	//�����ַ�����ӵ�str_val��
	for (int i = tmp.size() - 1; i >= 0; i--)
		str_val += tmp[i];
	str_val += '#';

}
void bst_insert(TreeNode* root, TreeNode* node)
{
	if (!root)
		root = node;
	if (node->val < root->val) {
		if (!root->left)
			root->left = node;
		else
			bst_insert(root->left, node);
	}
	else {
		if (!root->right)
			root->right = node;
		else
			bst_insert(root->right, node);
	}
}
void bst_preorder(TreeNode* node, string& data)
{
	if (!node)
		return;
	string str_val;
	int_tostring(node->val, str_val);
	data += str_val;
	bst_preorder(node->left, data);
	bst_preorder(node->right, data);
	
}

string serialize(TreeNode* root) {
	std::string data;
	bst_preorder(root, data);
	return data;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	if (data.empty())
		return nullptr;
	vector<TreeNode*> node_vec;//����ȡ���������֣��������������Ľ��
	int val = 0;
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] == '#') {
			node_vec.push_back(new TreeNode(val));
			val = 0;
		}
		else
			val = val * 10 + data[i] - '0';
	}
	for (int i = 1; i < node_vec.size(); i++)
		bst_insert(node_vec[0], node_vec[i]);
	return node_vec[0];
}
//��������"123#456#100#1#"�õ� 123 456 100 1 ���ַ�������
void decodestr(string str)
{
	int val = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '#') {
			cout << val << " ";
			val = 0;
		}
		else {
			val = val * 10 + str[i] - '0';
		}
	}
}
void test01()
{
	string str = "123#456#100#1#";
	decodestr(str);
}
int main()
{
	test01();
	system("pause");
	return 0;
}


#endif