#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
ListNode* mergeLists(ListNode* list1, ListNode* list2) {
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
ListNode* sortList(ListNode* head) {

	if (!head || !head->next)
		return head;//没有节点或者1个节点，不用排序
	ListNode* dummy = new ListNode(-1, head);
	ListNode* pre = dummy;
	ListNode* cur = dummy;
	while (cur && cur->next) {
		cur = cur->next->next;
		pre = pre->next;
	}

	auto second = pre->next;
	pre->next = nullptr;

	auto first = sortList(head);
	second = sortList(second);

	return mergeLists(first, second);
	//cout << "first" << endl;
	//while (head) {
	//	cout << head->val << " ";
	//	head = head->next;
	//}

	//cout << endl;
	//cout << "second" << endl;
	//while (second) {
	//	cout << second->val << " ";
	//	second = second->next;
	//}
	//cout << endl;
	//return nullptr;
}
ListNode* merge(ListNode* first, ListNode* second) {
	auto dummy = new ListNode(-1);
	auto cur = dummy;

	while (true) {
		if (!first) {
			cur->next = second;
			second = second->next;
		}
		else if (!second) {
			cur->next = first;
			first = first->next;
		}
		else if (first->val <= second->val) {
			cur->next = first;
			first = first->next;
		}
		else {
			cur->next = second;
			second = second->next;
		}
		cur = cur->next;
	}
	cur->next = nullptr;
	return dummy->next;
}
//2021年6月9日复习
ListNode* sortList2(ListNode* head) {
	if (!head || !head->next)
		return head;

	auto dummy = new ListNode(-1, head);
	auto pre = dummy;
	auto cur = head;

	while (cur && cur->next) {
		cur = cur->next->next;
		pre = pre->next;
	}
	auto second = sortList(pre->next);
	pre->next = nullptr;
	auto first = sortList(dummy->next);
	

	return merge(first, second);
}
void test01()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	sortList(head);
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif