#if 0
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
//���������������
void inorder(Node* node,vector<Node*>& vec_node) {
    if (!node)
        return;
    inorder(node->left, vec_node);
    vec_node.push_back(node);
    inorder(node->right, vec_node);
}
//����1:����vector�洢���
Node* treeToDoublyList(Node* root) {
    if (!root)
        return nullptr;
    vector<Node*> vec_node;
    inorder(root, vec_node);
    for (int i = 0; i < vec_node.size() - 1; ++i) {
        vec_node[i]->right = vec_node[i + 1];
        vec_node[i + 1]->left = vec_node[i];
    }
    vec_node[0]->left = vec_node[vec_node.size() - 1];
    vec_node[vec_node.size() - 1]->right = vec_node[0];

    return vec_node[0];

}
//������ ����2  ����
Node* treeToDoublyList2(Node* root) {
    if (!root)
        return nullptr;

    auto root_left = root->left;
    auto root_right = root->right;

    auto leftHead = treeToDoublyList2(root_left);
    auto rightHead = treeToDoublyList2(root_right);

    if (leftHead) {
        auto cur = leftHead;
        auto end = leftHead->left;
        
        while (cur->right != end) {
            cur->right->left = cur;
            cur = cur->right;
        }
            
        if (!cur->right) {
            cur->right = root;
            root->left = cur;
        }
        else {
            cur->right->right = root;
            root->left = cur->right->right;
        }

    }
    if (rightHead) {
        auto cur = rightHead;
        auto end = rightHead->left;
        
        while (cur->right != end) {
            cur->right->left = cur;
            cur = cur->right;
        }
         

        if (leftHead) {
            cur->right = leftHead;
            leftHead->left = cur;
        }
        else {
            root->left = cur;
            cur->right = root;
        }

        root->right = rightHead;
        rightHead->left = root;
    }

    if (leftHead)
        return leftHead;

    return root;
}
Node* head;
Node* pre;
void dfs(Node* cur) {
    if (!cur)
        return;
    dfs(cur->left);
    if (pre)
        pre->right = cur;
    else
        head = cur;
    cur->left = pre;
    pre = cur;
    dfs(cur->right);

}

//������ ����3
Node* treeToDoublyList3(Node* root) {
    if (!root)
        return nullptr;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
}
class Solution {
public:
    void dfs(Node* cur) {
        if (!cur)
            return;
        dfs(cur->left);
        if (pre)
            pre->right = cur;//��ǰ�����ǰһ�������ҽڵ�
        else
            head = cur;//���ǰһ�����Ϊ��,˵����ǰ����Ǹ����
        cur->left = pre;//��ǰ�����ڵ���ǰһ�����
        pre = cur;//������һ�α���,��ǰ�����ǰһ�����
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node* pre;//����ʱ�򱣴�ǰһ�����
    Node* head;//����˫�������ͷ���
};
void test01()
{
    Node* root = new Node(4, new Node(2,new Node(1),new Node(3)), new Node(5));
    auto newroot = treeToDoublyList2(root);
    int i = 0;
    while (true) {
        if (i == 10)
            break;
        cout << newroot->val << " ";
        newroot = newroot->right;
        ++i;
    }
}
int main()
{
    test01();
	system("pause");
	return 0;
}


#endif