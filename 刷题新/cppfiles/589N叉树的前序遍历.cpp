#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

vector<int> vret;
vector<int> preorder(Node* root) {
    if (!root)
        return {};
    stack<std::pair<Node*, bool> > mystack;
    mystack.push({ root,false });

    while (!mystack.empty()) {
        auto node = mystack.top();
        mystack.pop();

        if (node.second) {
            vret.push_back(node.first->val);
        }
        else {
            for (auto iter = node.first->children.rbegin(); iter != node.first->children.rend(); iter++) {
                if (*iter)
                    mystack.push({ *iter,false });
            }
            node.second = true;
            mystack.push(node);
        }
    }
    return vret;

}

void test01()
{
	
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif