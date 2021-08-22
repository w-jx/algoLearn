#if 0
#include "../headers/wjxHeaders.h"
/*
leecode题目介绍:


*/
ListNode* reverse(ListNode* head) {
	if (!head || !head->next)
		return head;
	ListNode* pre = nullptr;
	while (head) {
		ListNode* pNext = head->next;
		head->next = pre;
		pre = head;
		head = pNext;
	}
	return pre;
}
void reorderList(ListNode* head) {
	ListNode* dummy = new ListNode(-1, head);
	ListNode* pre = dummy;
	ListNode* cur = dummy;

	while (cur && cur->next) {
		cur = cur->next->next;
		pre = pre->next;
	}
	auto second = reverse(pre->next);
	auto first = head;
	pre->next = nullptr;//这个很重要

	//cout << "first" << endl;
	//while (first) {
	//	cout << first->val << " ";
	//	first = first->next;
	//}

	//cout << endl;
	//cout << "second" << endl;
	//while (second) {
	//	cout << second->val << " ";
	//	second = second->next;
	//}
	//cout << endl;
	
	
	ListNode* pNext = nullptr,*pNext2=nullptr;
	while (second) {
		pNext = first->next;//
		pNext2 = second->next;
		ListNode* cur = second;
		cur->next = first->next;
		first->next = cur;

		first = pNext;
		second = pNext2;
	}



}
void test01()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	reorderList(head);


}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif