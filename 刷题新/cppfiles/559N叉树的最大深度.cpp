#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÌâÄ¿½éÉÜ:


*/

int maxDepth(Node* root) {
    if (!root)
        return 0;
    int maxOne = 0;
    for (auto iter : root->children) {
        int temp = maxDepth(iter);
        if (temp > maxOne)
            maxOne = temp;
    }
    return maxOne + 1;
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