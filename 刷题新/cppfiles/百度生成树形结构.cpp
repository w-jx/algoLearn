#include "../headers/wjxHeaders.h"

struct Node
{
    int id;
    int pid;
    Node(int _id, int _pid) : id(_id), pid(_pid) {}
};

void printNode(vector<Node> &nodelist)
{
    unordered_map<int, vector<Node>> _mp;

    for (int i = 0; i < nodelist.size(); ++i)
    {
        Node node = nodelist[i];
    }
}
void test01()
{
    Node node1(1, 0);
    Node node2(2, 1);
    Node node3(3, 1);
    Node node4(4, 2);
    Node node5(5, 3);
    Node node6(6, 3);
    vector<Node> nodelist{node1, node2, node3, node4, node5, node6};
    printNode(nodelist);
}
int main()
{
}