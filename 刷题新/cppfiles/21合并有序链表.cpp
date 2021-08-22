#if 0
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
void printList(ListNode* list)
{
	ListNode* pCurrent = list;
	while (pCurrent != NULL) {
		cout << pCurrent->val << " ";
		pCurrent = pCurrent->next;
	}
	cout << endl;

}
ListNode* mergeLists(ListNode* l1, ListNode* l2)//
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	ListNode* pMergedHead = NULL;
	
	if (l1->val < l2->val) {
		pMergedHead = l1;
		pMergedHead->next = mergeLists(l1->next, l2);
	}
	else {
		pMergedHead = l2;
		pMergedHead->next = mergeLists(l1, l2->next);
	}
	return pMergedHead;
}

void test01()
{
	//首先准备两个链表的头结点
	ListNode* head1 = new ListNode(1);
	ListNode* l1 = head1;
	for (int i = 1; i < 4; i++) {//遍历head1不影响打印l1
		ListNode* pNext = new ListNode(i);
		head1->next = pNext;
		head1 = pNext;
	}
	ListNode* head2 = new ListNode(3);
	ListNode* l2 = head2;
	for (int i = 5; i < 8; i++) {
		ListNode* pNext = new ListNode(i);
		head2->next = pNext;
		head2 = pNext;
	}
	printList(l1);
	printList(l2);
	printList(mergeLists(l1, l2));
	

}
void test02()
{
	
}
int main()
{
	test01();
	//test02();
	system("pause");
	return 0;
}
#endif

