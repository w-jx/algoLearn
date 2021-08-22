#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:

1.方法1
先合并第一个和第二个，再将新的链表和第3个合并，以此类推
2.方法2
	先进行排序，再进行连接
3.方法3 最优时间复杂度
	进行分治
*/

/// <summary>
/// 合并两个有序链表
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
//方法2 先排序
ListNode* mergeKLists2(vector<ListNode*>& lists) {
	std::vector<ListNode*> node_vec;

	for (int i = 0; i < lists.size(); ++i) {
		ListNode* cur = lists[i];
		while (cur) {
			node_vec.push_back(cur);
			cur = cur->next;
		}
	}
	if (node_vec.empty())//无结点
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
//方法3：分治计算·
ListNode* mergeKLists3(vector<ListNode*>& lists) {
	if (lists.empty())//无链表
		return nullptr;
	if (lists.size() == 1)
		return lists.front();

	if (lists.size() == 2) {//如果两个，就合并
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
//方法3分治,2021年5月20日复习的时候自己写的,超过百分之99.64
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