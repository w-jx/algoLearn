#if 0
#include <iostream>
using namespace std;
/*
leecodeÌâÄ¿½éÉÜ:


*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

	if (headA == NULL || headB == NULL)
		return NULL;
	if (headA == headB)
		return headA;
	ListNode* pRet = NULL;
	if (headA != headB) {
		pRet =  getIntersectionNode(headA->next, headB);
		headA = headA->next;
	}
	


}
void push(ListNode* head, int val)
{
	if (head == NULL)
		return;
	ListNode* pHead = head;
	while (head->next != NULL) {
		head = head->next;
	}
	ListNode* pNew = new ListNode(val);
	head->next = pNew;
}
void printNode(ListNode* head)
{
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
void test01()
{	
	auto node1 = new ListNode(4);
	push(node1, 1);
	push(node1, 8);
	push(node1, 4);
	push(node1, 5);

	auto node2 = new ListNode(5);
	push(node2, 0);
	push(node2, 1);
	push(node2, 8);
	push(node2, 4);
	push(node2, 5);
	printNode(node1);
	printNode(node2);

	ListNode* pRet = getIntersectionNode(node1, node2);
	printNode(pRet);


}
int main()
{
	test01();
	system("pause");
	return 0;
}
#endif