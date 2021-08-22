#if 0
#include "../headers/wjxHeaders.h"
/*
leecodeÃ‚ƒøΩÈ…‹:


*/
ListNode* removeNodes(ListNode* head, int start, int end)
{
	ListNode* dummy = new ListNode(-1, head);
	ListNode* pre = dummy;
	
	for (int i = 1; i < start; ++i)
		pre = pre->next;
	auto node = pre->next;
	for (int i = start; i < end; ++i)
		node = node->next;
	pre->next = node->next;

	return dummy->next;
}
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
	ListNode* dummy = new ListNode(-1, list1);
	ListNode* pre = dummy;

	for (int i = 0; i < a; ++i)
		pre = pre->next;
	auto node = pre->next;
	for (int i = a ; i < b; ++i)
		node = node->next;
	node = node->next;

	ListNode* preCur = new ListNode(-1, list2);
	ListNode* cur = list2;

	while (cur) {
		cur = cur->next;
		preCur = preCur->next;
	}
	pre->next = list2;
	preCur->next = node;

	return dummy->next;

}
void test01()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(3);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(2);
	auto node = removeNodes(head,2,3);

	while (node) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif