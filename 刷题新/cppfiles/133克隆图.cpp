#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/
//leetcode ���,��֪���
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
//�洢����ԭ���Ϳ�¡���ļ�ֵ��,����¡����Ƿ�Ϊ��
//��ֱ����ǰ����Ƿ��Ѿ�����������
unordered_map<Node*, Node*> node_map;
Node* cloneGraph(Node* node) {
    if (node == nullptr)
        return node;
    
    //����������Ѿ������ʹ���,ֱ�Ӵӹ�ϣ����ȡ����Ӧ�Ŀ�¡��㷵��
    if (node_map.find(node) != node_map.end())
        return node_map.at(node);

    //��¡���,ֻ��¡ֵ,����¡���ڽӵ�
    Node* cloneNode = new Node(node->val);
    // node->neighbors�����ŵ�ָ��Ķ���
    for (auto neighbor_node : node->neighbors) {
        cloneNode->neighbors.push_back(cloneGraph(neighbor_node));
    }

    return cloneNode;
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