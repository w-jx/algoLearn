#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/

RandomNode* copyRandomList(RandomNode* head) {
	std::unordered_map< RandomNode*, int> hashmap;//地址和结点位置 映射
	vector< RandomNode*> node_vec;//根据结点位置 访问地址

	RandomNode* ptr = head;
	int i = 0;//存储在hashmap中结点位置

	while (ptr) {//第一次遍历，构造各个结点
		node_vec.push_back(new RandomNode(ptr->val));
		hashmap.insert({ ptr,i });
		ptr = ptr->next;
		++i;
	}
	ptr = head;
	i = 0;
	node_vec.push_back(0);//为了处理最后一个结点比较方便，就不用害怕越界了
	while (ptr) {//ptr 第二次遍历 构造next 指针和Random指针
			node_vec[i]->next = node_vec[i+1];

		if (ptr->random) {
			int idx = hashmap[ptr->random];//获取结点 的位置
			node_vec[i]->random = node_vec[idx];
		}
		ptr = ptr->next;
		++i;
	}
	return node_vec.front();

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