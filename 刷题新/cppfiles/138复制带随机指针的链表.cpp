#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:


*/

RandomNode* copyRandomList(RandomNode* head) {
	std::unordered_map< RandomNode*, int> hashmap;//��ַ�ͽ��λ�� ӳ��
	vector< RandomNode*> node_vec;//���ݽ��λ�� ���ʵ�ַ

	RandomNode* ptr = head;
	int i = 0;//�洢��hashmap�н��λ��

	while (ptr) {//��һ�α���������������
		node_vec.push_back(new RandomNode(ptr->val));
		hashmap.insert({ ptr,i });
		ptr = ptr->next;
		++i;
	}
	ptr = head;
	i = 0;
	node_vec.push_back(0);//Ϊ�˴������һ�����ȽϷ��㣬�Ͳ��ú���Խ����
	while (ptr) {//ptr �ڶ��α��� ����next ָ���Randomָ��
			node_vec[i]->next = node_vec[i+1];

		if (ptr->random) {
			int idx = hashmap[ptr->random];//��ȡ��� ��λ��
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