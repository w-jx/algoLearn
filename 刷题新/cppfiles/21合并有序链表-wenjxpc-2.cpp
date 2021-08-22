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
ListNode* mergeLists(ListNode* l1, ListNode* l2)//目前实现把两个链表结合在一起
{
	ListNode* head1 = new ListNode; 
	head1->next = l1;
	ListNode* pCurrent1 =l1;
	head1 = head1->next;

	while (l2 != NULL) {
		if (head1->val <=l2->val) {
			ListNode* nodeNew = new ListNode(l2->val);
			ListNode* pNext = head1->next;//把下个结点保存下来
			head1->next = nodeNew;
			nodeNew->next = pNext;			
			l2 = l2->next;
				
		}
		head1 = pCurrent1;
		
	}
	return pCurrent1;
}
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2)//
{
	//新建结点,放置l1,l2小的
	ListNode* nodeRet = new ListNode;
	ListNode* nodeOperator = new ListNode;
	nodeOperator->next = nodeRet;


	ListNode* head1 = new ListNode;
	head1->next = l1;	
	ListNode* pCurrent1 = l1;

	ListNode* head2 = new ListNode;
	head2->next = l2;
	ListNode* pCurrent2 = l2;
	
	while (head1->next != NULL) {
		if (head2->next != NULL) {
			
		}
	}
	return nodeRet;
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

