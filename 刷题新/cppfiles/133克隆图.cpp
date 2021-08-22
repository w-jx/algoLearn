#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
//leetcode 题解,不知其解
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
//存储的是原结点和克隆结点的键值对,看克隆结点是否为空
//就直到当前结点是否已经被拷贝过了
unordered_map<Node*, Node*> node_map;
Node* cloneGraph(Node* node) {
    if (node == nullptr)
        return node;
    
    //如果这个结点已经被访问过了,直接从哈希表中取出对应的克隆结点返回
    if (node_map.find(node) != node_map.end())
        return node_map.at(node);

    //克隆结点,只克隆值,不克隆其邻接点
    Node* cloneNode = new Node(node->val);
    // node->neighbors里面存放的指向的顶点
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