#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÃ‚ƒøΩÈ…‹:


*/

vector<vector<int>> levelOrder(Node* root) {
	if (!root)
		return {};
	queue<Node*> myque;
	myque.push(root);
	vector<int> vtemp;
	vector<vector<int> > vret;
	while (!myque.empty()) {
		int len = myque.size();
		for (int i = 0; i < len; ++i) {
			auto node = myque.front();
			vtemp.push_back(node->val);
			myque.pop();
			for (auto iter : node->children)
				myque.push(iter);
		}
		vret.push_back(vtemp);
		vtemp.clear();
	}
	return vret;
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