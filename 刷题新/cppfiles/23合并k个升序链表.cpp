#if 0
#include "../headers/wjxHeaders.h"
/*
leecode��Ŀ����:

1.����1
�Ⱥϲ���һ���͵ڶ������ٽ��µ�����͵�3���ϲ����Դ�����
2.����2
	�Ƚ��������ٽ�������
3.����3 ����ʱ�临�Ӷ�
	���з���
*/

/// <summary>
/// �ϲ�������������
/// </summary>
auto mergeLists = [](ListNode* list1, ListNode* list2)->ListNode* {
	ListNode* pHead = new ListNode(-1);

	ListNode* cur = pHead;
	ListNode* cur1 = list1;
	ListNode* cur2 = list2;

	while (cur1 && cur2) {
		if (cur1->val < cur2->val) {
			cur->next = cur1;
			cur1 = cur1->next;
		}
		else {
			cur->next = cur2;
			cur2 = cur2->next;
		}
		cur = cur->next;
	}
	while (cur1) {
		cur->next = cur1;
		cur = cur->next;
		cur1 = cur1->next;
	}
	while (cur2) {
		cur->next = cur2;
		cur = cur->next;
		cur2 = cur2->next;
	}
	return pHead->next;
};
//����2 ������
ListNode* mergeKLists2(vector<ListNode*>& lists) {
	std::vector<ListNode*> node_vec;

	for (int i = 0; i < lists.size(); ++i) {
		ListNode* cur = lists[i];
		while (cur) {
			node_vec.push_back(cur);
			cur = cur->next;
		}
	}
	if (node_vec.empty())//�޽��
		return nullptr;

	std::sort(node_vec.begin(), node_vec.end(), [](ListNode* l1, ListNode* l2)->bool
		{return l1->val < l2->val; }
	);
	node_vec.push_back(nullptr);
	for (int i = 0; i < node_vec.size(); ++i) {
		node_vec[i]->next = node_vec[i+1];
	}
	return node_vec[0];

}
//����3�����μ��㡤
ListNode* mergeKLists3(vector<ListNode*>& lists) {
	if (lists.empty())//������
		return nullptr;
	if (lists.size() == 1)
		return lists.front();

	if (lists.size() == 2) {//����������ͺϲ�
		return mergeLists(lists.front(), lists.back());
	}
	vector<ListNode*> sub1_lists;
	vector<ListNode*> sub2_lists;

	int mid = lists.size() / 2;

	for (int i = 0; i < mid; ++i)
		sub1_lists.push_back(lists[i]);
	for (int i = mid; i < lists.size(); ++i)
		sub2_lists.push_back(lists[i]);
	
	ListNode* l1 = mergeKLists3(sub1_lists);
	ListNode* l2 = mergeKLists3(sub2_lists);

	return mergeLists(l1, l2);
}
//����3����,2021��5��20�ո�ϰ��ʱ���Լ�д��,�����ٷ�֮99.64
ListNode* merge(ListNode* l1, ListNode* l2) {
	if (!l1 && !l2)
		return nullptr;

	ListNode* root = nullptr;
	if (l1 && !l2) {
		root = l1;
		root->next = merge(l1->next, l2);
	}
	else if (!l1 && l2) {
		root = l2;
		root->next = merge(l1, l2->next);
	}
	else if (l1->val <= l2->val) {
		root = l1;
		root->next = merge(l1->next, l2);
	}
	else {
		root = l2;
		root->next = merge(l1, l2->next);
	}
	return root;
}
ListNode* partion(vector<ListNode*>& lists, int left, int right) {
	if (left > right)
		return nullptr;
	if (left == right)
		return lists[left];
	ListNode* root = nullptr;
	if (left < right) {
		int mid = left + (right - left) / 2;
		auto node1 = partion(lists, left, mid);
		auto node2 = partion(lists, mid + 1, right);
		root = merge(node1, node2);
	}
	return root;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty())
		return nullptr;
	if (lists.size() == 1)
		return lists[0];
	if (lists.size() == 2)
		return merge(lists[0], lists[1]);
	return partion(lists, 0, lists.size() - 1);
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